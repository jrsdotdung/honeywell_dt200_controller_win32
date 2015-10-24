#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#ifdef _DEBUG
#define DEBUG(format, ...) printf(format, ##__VA_ARGS__);
#define ERROR(format, ...) fprintf(stderr, format, ##__VA_ARGS__);
#else
#define DEBUG(...)
#define ERROR(...)
#endif

#define DT200_SENSOR_TEMP  0x01  // 感測器溫度
#define DT200_CONFIG_TEMP  0x02  // 溫度設定值
#define DT200_FAN_SPEED    0x03  // 風速狀態
#define DT200_DRIVE_STATE  0x04  // ON/OFF
#define DT200_MODE_STATE   0x05  // 工作模式
#define DT200_TEMP_OFFSET  0x06  // 溫度偏移值
#define DT200_CLOCK_TIMER  0x07  // 定時時間
#define DT200_TEMP_CERANGE 0x08  // 節能溫度偏移值
#define DT200_INNER_CONFIG 0x09  // 內部設定項
#define DT200_IO_CONFIG    0x0A  // 輸入輸出接點

#define DT200_DRIVE_ALL   0x00
#define DT200_LOCK_ADDR_1 400
#define DT200_LOCK_ADDR_2 401

#define MODBUS_TCP             0x00
#define MODBUS_RTU_OVER_TCP    0x01
#define READ_HOLDING_REGISTERS 0x03
#define WRITE_SINGLE_REGISTERS 0x06
#define MAX_MODBUS_SEND_SIZE   32
#define MAX_MODBUS_RECV_SIZE   255
#define	EXIT_MODBUS_FAILURE	   0xFF80

#define uint16_high(number) (number >> 8)
#define uint16_low(number) (number & 0xFF)

namespace modbus_dt200 {

	int sockinit(
		char *host,
		unsigned short port,
		unsigned short type
	);

	int sockopen(
		char *host,
		unsigned short port,
		unsigned char *sendbuf,
		unsigned char *recvbuf,
		unsigned short timeout
	);

	unsigned char *build_modbus_data(
		unsigned short arg1,
		unsigned short arg2
	);

	int build_modbus_request(
		unsigned char *buffer,
		unsigned short tid,
		unsigned short pid,
		unsigned short uid,
		unsigned short func,
		unsigned char *data,
		unsigned short datalen
	);

	unsigned short sockopen_modbus(
		unsigned short uid,
		unsigned short func,
		unsigned short arg1,
		unsigned short arg2,
		unsigned short *ret
	);

	unsigned short dt200_register_get(
		char *host,
		unsigned short port,
		unsigned short type,
		unsigned short uid,
		unsigned short sid,
		unsigned short addr
	);

	unsigned short dt200_register_set(
		char *host,
		unsigned short port,
		unsigned short type,
		unsigned short uid,
		unsigned short sid,
		unsigned short addr,
		unsigned short value
	);

	unsigned short dt200_drive_lock(
		char *host,
		unsigned short port,
		unsigned short type,
		unsigned short uid,
		unsigned short sid
	);

	unsigned short dt200_drive_unlock(
		char *host,
		unsigned short port,
		unsigned short type,
		unsigned short uid,
		unsigned short sid
	);

	unsigned short dt200_global_status_get(
		char *host,
		unsigned short port,
		unsigned short type,
		unsigned short uid,
		unsigned short ret[32][11]
	);

}

#endif // MAIN_H_INCLUDED
