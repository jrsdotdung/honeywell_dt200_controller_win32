#include "stdafx.h"
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
//#include <windows.h>
#include <winsock2.h>
//#define _DEBUG
#include "crc16.h"
#include "dt200.h"

namespace modbus_dt200 {

	char *DT200_SERVER_IP;
	unsigned short DT200_SERVER_PORT;
	unsigned short DT200_SERVER_TYPE;
	unsigned short MBAP_HEADER_SIZE;
	unsigned short COMMAND_LENGTH;

	int sockinit(char *host, unsigned short port, unsigned short type)
	{
		DT200_SERVER_IP = host;
		DT200_SERVER_PORT = port;

		switch (type) {
			case MODBUS_TCP:
				DT200_SERVER_TYPE = 0;
				MBAP_HEADER_SIZE = 8;
				COMMAND_LENGTH = 12;
				break;
			case MODBUS_RTU_OVER_TCP:
				DT200_SERVER_TYPE = 1;
				MBAP_HEADER_SIZE = 2;
				COMMAND_LENGTH = 8;
				break;
			default:
				return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}

	int sockopen(char *host, unsigned short port, unsigned char *sendbuf, unsigned char *recvbuf, unsigned short timeout)
	{
		// Initialize Winsock.
		WSADATA wsaData;
		int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
		if (iResult != NO_ERROR) {
			ERROR("Error at WSAStartup()");
		}

		// Create a socket.
		SOCKET m_socket;
		m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

		// Set timeout
	//    fd_set fds;
	//    struct timeval tv;
	//    FD_ZERO(&fds);
	//    FD_SET(m_socket, &fds);
	//    tv.tv_sec = timeout;
	//    tv.tv_usec = 0;
	//    select (m_socket, &fds, NULL, NULL, &tv);

		if (m_socket == INVALID_SOCKET) {
			ERROR("Error at socket(): %d", WSAGetLastError());
			WSACleanup();
			return SOCKET_ERROR;
		}

		// Connect to a host.
		struct sockaddr_in clientService;

		clientService.sin_family = AF_INET;
		clientService.sin_addr.s_addr = inet_addr(host);
		clientService.sin_port = htons(port);

		if (connect(m_socket, (SOCKADDR*) &clientService, sizeof(clientService)) == SOCKET_ERROR) {
			ERROR("Failed to connect");
			WSACleanup();
			return SOCKET_ERROR;
		}

		// Send and receive data.
		int bytesSent = 0;
		int bytesRecv = 0; // 0 || SOCKET_ERROR

		#ifdef _DEBUG
		DEBUG("Command:");
		int i = 0;
		for (i=0; i<COMMAND_LENGTH; i++)
			DEBUG(" %02X", sendbuf[i]);
		DEBUG("\n");
		#endif

		bytesSent = send(m_socket, (char*)sendbuf, COMMAND_LENGTH, 0);
		DEBUG("Bytes Sent: %d\n", bytesSent);

		if (bytesRecv == 0 || (bytesRecv == SOCKET_ERROR && WSAGetLastError() == WSAECONNRESET)) {
			DEBUG("Wait for receive . . .\n");
			bytesRecv = recv(m_socket, (char*)recvbuf, MAX_MODBUS_RECV_SIZE, 0);
			if (bytesRecv == -1) {
				ERROR("Connection Closed");
				shutdown(m_socket, SD_BOTH);
				closesocket(m_socket);
				return SOCKET_ERROR;
			}
			if (bytesRecv < 0) {
				shutdown(m_socket, SD_BOTH);
				closesocket(m_socket);
				return SOCKET_ERROR;
			}

			DEBUG("Bytes Recv: %d\n", bytesRecv);
		}

		shutdown(m_socket, SD_BOTH);
		closesocket(m_socket);
		WSACleanup();
		return bytesRecv;
	}

	unsigned char *build_modbus_data(unsigned short arg1, unsigned short arg2)
	{
		static unsigned char data[MAX_MODBUS_RECV_SIZE] = {0};
		//DEBUG("Data address: 0x%X\n", &data[0]);
		sprintf((char*)data, "%c%c%c%c", uint16_high(arg1), uint16_low(arg1)
								, uint16_high(arg2), uint16_low(arg2));
		return data;
	}

	int build_modbus_request(unsigned char *buffer, unsigned short tid, unsigned short pid, unsigned short uid, unsigned short func, unsigned char *data, unsigned short datalen)
	{
		/*
			buffer: Socket buffer
			tid: Transaction Identifier
			pid: Protocol Identifier
			uid: Unit Identifier
			func: Function code
			data: Data bytes
			datalen: Data Length

		*/

		if (DT200_SERVER_TYPE == MODBUS_TCP) {
			//DEBUG("data: %02X %02X %02X %02X\n", data[0], data[1], data[2], data[3]);
			unsigned short length = datalen + 2; // Length Field
			sprintf((char*)buffer, "%c%c%c%c%c%c%c%c", uint16_high(tid), uint16_low(tid)
													 , uint16_high(pid), uint16_low(pid)
													 , uint16_high(length), uint16_low(length)
													 , uid
													 , func);
			memcpy(&buffer[MBAP_HEADER_SIZE], &data[0], sizeof(char)*datalen);
			buffer[MBAP_HEADER_SIZE + datalen] = '\0';
			return EXIT_SUCCESS;
		} else {
			//DEBUG("data: %02X %02X %02X %02X\n", data[0], data[1], data[2], data[3]);
			sprintf((char*)buffer, "%c%c", uid, func);
			memcpy(&buffer[MBAP_HEADER_SIZE], &data[0], sizeof(char)*datalen);
			unsigned short checksum = CRC16(buffer, 6);
			//DEBUG("CRC16: %02X %02X\n", uint16_low(checksum), uint16_high(checksum));
			buffer[MBAP_HEADER_SIZE + datalen] = uint16_low(checksum);
			buffer[MBAP_HEADER_SIZE + datalen + 1] = uint16_high(checksum);
			buffer[MBAP_HEADER_SIZE + datalen + 2] = '\0';
			return EXIT_SUCCESS;
		}
	}

	unsigned short sockopen_modbus(unsigned short uid, unsigned short func, unsigned short arg1, unsigned short arg2, unsigned short *ret)
	{
		unsigned short tid = 0x0101; // Transaction Identifier
		unsigned short pid = 0x0000; // Protocol Identifier

		unsigned char sendbuf[MAX_MODBUS_SEND_SIZE] = {0};
		unsigned char recvbuf[MAX_MODBUS_RECV_SIZE] = {0};

		switch (func) {
			case READ_HOLDING_REGISTERS:
				break;
			case WRITE_SINGLE_REGISTERS:
				break;
			default:
				fprintf(stderr, "Error: Illegal function 0x%02X", func);
				return EXIT_MODBUS_FAILURE;
				break;
		}

		build_modbus_request(sendbuf, tid, pid, uid, func, build_modbus_data(arg1, arg2), 4);

		DEBUG("==================================================\n");

		int i = 0;
		unsigned short metalen = 0;
		unsigned short datalen = 0;
		unsigned char mbap_header[MAX_MODBUS_RECV_SIZE] = {0};
		unsigned char modbus_meta[MAX_MODBUS_RECV_SIZE] = {0};
		unsigned char modbus_data[MAX_MODBUS_RECV_SIZE] = {0};

		int bytesRecv = sockopen(DT200_SERVER_IP, DT200_SERVER_PORT, sendbuf, recvbuf, 10);
		if (bytesRecv == SOCKET_ERROR || bytesRecv < MBAP_HEADER_SIZE) {
			ERROR("Error at sockopen()");
			return EXIT_MODBUS_FAILURE;
		}

		memcpy(mbap_header, &recvbuf[0], sizeof(char)*MBAP_HEADER_SIZE);
		//mbap_header[MBAP_HEADER_SIZE] = '\0';
		#ifdef _DEBUG
		DEBUG("MBAP Header:");
		for (i=0; i<MBAP_HEADER_SIZE; i++)
			DEBUG(" %02X", sendbuf[i]);
		DEBUG("\n");
		#endif

		// [01 01] [00 00] [00 06] [FF] [06]
		//  uid     pid     length  uid  func
		unsigned int RESPONSE_FUNC = MBAP_HEADER_SIZE - 1;
		switch (mbap_header[RESPONSE_FUNC]) {
			case READ_HOLDING_REGISTERS:
				metalen = 1;
				break;
			case WRITE_SINGLE_REGISTERS:
				metalen = 4;
				break;
		}
		if (DT200_SERVER_TYPE == MODBUS_TCP) {
			unsigned short revlen = (mbap_header[4]<<8) + mbap_header[5] - 2;
			datalen = revlen - metalen;
		} else {
			datalen = recvbuf[2];
		}

		DEBUG("Meta length: %d\n", metalen);
		DEBUG("Data length: %d\n", datalen);

		if (metalen > 0) {
			memcpy(modbus_meta, &recvbuf[MBAP_HEADER_SIZE], sizeof(char)*metalen);
			//mbap_header[MBAP_HEADER_SIZE] = '\0';
		}
		if (datalen > 0) {
			memcpy(modbus_data, &recvbuf[MBAP_HEADER_SIZE + metalen], sizeof(char)*datalen);
			//mbap_header[MBAP_HEADER_SIZE + metalen] = '\0';
		}

		#ifdef _DEBUG
		DEBUG("\nMeta bytes: ");
		for (i=0; i<metalen; i++) {
			DEBUG("%02X ", modbus_meta[i]);
		}
		DEBUG("\nData bytes: ");
		for (i=0; i<datalen; i++) {
			if (i%20 == 0) {
				DEBUG("\n");
			} else if (i > 0 && i%2 == 0) {
				DEBUG(" ");
			}
			DEBUG("%02X ", modbus_data[i]);
		}
		DEBUG("\n\n");
		#endif

		if ((mbap_header[RESPONSE_FUNC]&0xF0) == 0x80) {
			switch (modbus_data[0]&0x0F) {
				case 0x01:
					ERROR("Modbus Error: Illegal function");
					break;
				case 0x02:
					ERROR("Modbus Error: Illegal data address");
					break;
				case 0x03:
					ERROR("Modbus Error: Illegal data value");
					break;
				case 0x04:
					ERROR("Modbus Error: Slave device failure");
					break;
				case 0x05:
					ERROR("Modbus Error: Acknowledge");
					break;
				case 0x06:
					ERROR("Modbus Error: Slave device busy");
					break;
				default:
					ERROR("Modbus Error: Undefined error");
					break;
			}
			DEBUG("\n");
			return EXIT_MODBUS_FAILURE;
		}

		unsigned short result = EXIT_SUCCESS;
		if (datalen == 2) {
			result = (modbus_data[0] << 8) + modbus_data[1];
		} else if ((datalen > 2) && (datalen % 2 == 0)) {
			for (i=0; i<datalen; i+=2) {
				ret[i/2] = (modbus_data[i] << 8) + modbus_data[i+1];
				//DEBUG("modbus_data[%02d] = %02d\n", i/2, ret[i/2]);
			}
		}
		DEBUG("==================================================\n");
		return result; // EXIT_SUCCESS
	}

	unsigned short dt200_register_get(char *host, unsigned short port, unsigned short type, unsigned short uid, unsigned short sid, unsigned short addr)
	{
		/*
			return:
				- Fail:    0xFF80 (65408)
				- Success: 0x0000..0xFFFF (UNSIGNED SHORT INTEGER)
		*/
		sockinit(host, port, type);
		return sockopen_modbus(uid, READ_HOLDING_REGISTERS, sid*10 + addr, 1, NULL);
	}

	unsigned short dt200_register_set(char *host, unsigned short port, unsigned short type, unsigned short uid, unsigned short sid, unsigned short addr, unsigned short value)
	{
		/*
			return:
				- Fail:    EXIT_MODBUS_FAILURE (65408)
				- Success: EXIT_SUCCESS (0)
		*/
		sockinit(host, port, type);
		if (sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, sid*10 + addr, value, NULL) == EXIT_MODBUS_FAILURE)
			return EXIT_MODBUS_FAILURE;
		return EXIT_SUCCESS;
	}

	unsigned short dt200_drive_lock(char *host, unsigned short port, unsigned short type, unsigned short uid, unsigned short sid)
	{
		unsigned short value = 0x0000;
		sockinit(host, port, type);
		if (sid == DT200_DRIVE_ALL) {
			value = 0xFFFF;
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_1, value, NULL);
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_2, value, NULL);
		} else if (sid < 16) {
			value = sockopen_modbus(uid, READ_HOLDING_REGISTERS, DT200_LOCK_ADDR_1, 1, NULL);
			value = value | (1 << sid);
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_1, value, NULL);
		} else {
			value = sockopen_modbus(uid, READ_HOLDING_REGISTERS, DT200_LOCK_ADDR_2, 1, NULL);
			value = value | (1 << (sid - 16));
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_2, value, NULL);
		}
		return EXIT_SUCCESS;
	}

	unsigned short dt200_drive_unlock(char *host, unsigned short port, unsigned short type, unsigned short uid, unsigned short sid)
	{
		unsigned short value = 0x0000;
		sockinit(host, port, type);
		if (sid == DT200_DRIVE_ALL) {
			value = 0x0000;
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_1, value, NULL);
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_2, value, NULL);
		} else if (sid < 16) {
			value = sockopen_modbus(uid, READ_HOLDING_REGISTERS, DT200_LOCK_ADDR_1, 1, NULL);
			value = value & ~(1 << sid);
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_1, value, NULL);
		} else {
			value = sockopen_modbus(uid, READ_HOLDING_REGISTERS, DT200_LOCK_ADDR_2, 1, NULL);
			value = value & ~(1 << (sid - 16));
			sockopen_modbus(uid, WRITE_SINGLE_REGISTERS, DT200_LOCK_ADDR_2, value, NULL);
		}
		return EXIT_SUCCESS;
	}

	unsigned short dt200_global_status_get(char *host, unsigned short port, unsigned short type, unsigned short uid, unsigned short ret[32][11])
	{
		/*
			return:
				- Fail:    0xFF80 (65408)
				- Success: 0x0000..0xFFFF (UNSIGNED SHORT INTEGER)
		*/

		int i = 0, j = 0, k = 0;
		unsigned short return_value[MAX_MODBUS_RECV_SIZE] = {0};
		unsigned short result_value[320] = {0};
		unsigned short result_lock[2] = {0};
		unsigned short start = 0, ended = 320, length = 0, step = 28;

		sockinit(host, port, type);
		for(;;) {
			length = start + step > ended ? ended - start : step;
			if (sockopen_modbus(uid, READ_HOLDING_REGISTERS, start  , length + 1, return_value) == EXIT_MODBUS_FAILURE)
				return EXIT_MODBUS_FAILURE;
			memcpy(&result_value[start], &return_value[0], sizeof(unsigned short)*(length + 1));
			if ((start += step) >= ended)
				break;
		}

		result_lock[0] = sockopen_modbus(uid, READ_HOLDING_REGISTERS, DT200_LOCK_ADDR_1, 1, NULL);
		result_lock[1] = sockopen_modbus(uid, READ_HOLDING_REGISTERS, DT200_LOCK_ADDR_2, 1, NULL);

		/** Register address: 0, 1..10, 11..21, ... , 311..320 */

		for (i=0; i<32; i++) {
			for (j=0; j<10; j++){
				k = i * 10 + j + 1;
				ret[i][j] = result_value[k];
			}
			if (i < 16) {
				ret[i][10] = (result_lock[0] >> i) & 0x0001;
			} else {
				ret[i][10] = (result_lock[1] >> (i - 16)) & 0x0001;
			}
		}

		return EXIT_SUCCESS;
	}

}
