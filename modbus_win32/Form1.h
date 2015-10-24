#pragma once
#include <string>
#include <ctime>
#include "DotNetUtilities.h"
#include "dt200.h"

char *DT200_SERVER_IP;
unsigned short DT200_SERVER_PORT;
unsigned short DT200_SERVER_TYPE;
unsigned short func_regs[31][11] = {0};

namespace modbus_win32 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 的摘要
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RichTextBox^  TextBox_log;
	private: System::Windows::Forms::TextBox^  Text_IP;
	private: System::Windows::Forms::NumericUpDown^  NumUpDown_SID;
	private: System::Windows::Forms::TableLayoutPanel^  table_server_field;





	private: System::Windows::Forms::Label^  label_IP;
	private: System::Windows::Forms::Label^  label_SID;


	private: System::Windows::Forms::Button^  button_connect;
	private: System::Windows::Forms::Label^  label_UID;

	private: System::Windows::Forms::NumericUpDown^  NumUpDown_UID;
	private: System::Windows::Forms::TableLayoutPanel^  table_register_field;




	private: System::Windows::Forms::Label^  label_reg5;



	private: System::Windows::Forms::Label^  label_reg1;
	private: System::Windows::Forms::Label^  label_reg2;
	private: System::Windows::Forms::Label^  label_reg3;
	private: System::Windows::Forms::Label^  label_reg4;
	private: System::Windows::Forms::Label^  label_reg6;
	private: System::Windows::Forms::Label^  label_reg7;
	private: System::Windows::Forms::Label^  label_reg8;
	private: System::Windows::Forms::Label^  label_reg9;
	private: System::Windows::Forms::Label^  label_reg10;


































	private: System::Windows::Forms::TableLayoutPanel^  table_lock_field;
	private: System::Windows::Forms::CheckBox^  checkBox_lock1;



	private: System::Windows::Forms::CheckBox^  checkBox_lock2;
	private: System::Windows::Forms::CheckBox^  checkBox_lock3;
	private: System::Windows::Forms::CheckBox^  checkBox_lock4;
	private: System::Windows::Forms::CheckBox^  checkBox_lock5;
	private: System::Windows::Forms::CheckBox^  checkBox_lock6;
	private: System::Windows::Forms::CheckBox^  checkBox_lock7;
	private: System::Windows::Forms::CheckBox^  checkBox_lock8;
	private: System::Windows::Forms::CheckBox^  checkBox_lock9;
	private: System::Windows::Forms::CheckBox^  checkBox_lock10;
	private: System::Windows::Forms::CheckBox^  checkBox_lock11;
	private: System::Windows::Forms::CheckBox^  checkBox_lock12;
	private: System::Windows::Forms::CheckBox^  checkBox_lock13;
	private: System::Windows::Forms::CheckBox^  checkBox_lock14;
	private: System::Windows::Forms::CheckBox^  checkBox_lock15;
	private: System::Windows::Forms::CheckBox^  checkBox_lock16;
	private: System::Windows::Forms::CheckBox^  checkBox_lock17;
	private: System::Windows::Forms::CheckBox^  checkBox_lock18;
	private: System::Windows::Forms::CheckBox^  checkBox_lock19;
	private: System::Windows::Forms::CheckBox^  checkBox_lock20;
	private: System::Windows::Forms::CheckBox^  checkBox_lock21;
	private: System::Windows::Forms::CheckBox^  checkBox_lock22;
	private: System::Windows::Forms::CheckBox^  checkBox_lock23;
	private: System::Windows::Forms::CheckBox^  checkBox_lock24;
	private: System::Windows::Forms::CheckBox^  checkBox_lock25;
	private: System::Windows::Forms::CheckBox^  checkBox_lock26;
	private: System::Windows::Forms::CheckBox^  checkBox_lock27;
	private: System::Windows::Forms::CheckBox^  checkBox_lock28;
	private: System::Windows::Forms::CheckBox^  checkBox_lock29;
	private: System::Windows::Forms::CheckBox^  checkBox_lock30;
	private: System::Windows::Forms::CheckBox^  checkBox_lock31;

private: System::Windows::Forms::Label^  label_lock;

private: System::Windows::Forms::Label^  label_polling;
private: System::Windows::Forms::TableLayoutPanel^  table_count_field;


private: System::Windows::Forms::Label^  label_count;
private: System::Windows::Forms::Button^  button_lock_all;
private: System::Windows::Forms::Button^  button_unlock_all;
private: System::Windows::Forms::TextBox^  Text_val1;
private: System::Windows::Forms::TextBox^  Text_val10;
private: System::Windows::Forms::TextBox^  Text_val5;
private: System::Windows::Forms::TextBox^  Text_val9;



private: System::Windows::Forms::TextBox^  Text_val4;


private: System::Windows::Forms::TextBox^  Text_val8;
private: System::Windows::Forms::TextBox^  Text_val3;
private: System::Windows::Forms::TextBox^  Text_val7;




private: System::Windows::Forms::TextBox^  Text_val2;


private: System::Windows::Forms::TextBox^  Text_val6;
private: System::Windows::Forms::Label^  label_Type;
private: System::Windows::Forms::Label^  label_Port;
private: System::Windows::Forms::NumericUpDown^  NumUpDown_PORT;
private: System::Windows::Forms::ComboBox^  comboBox_TYPE;









	protected: 

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器
		/// 修改這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->TextBox_log = (gcnew System::Windows::Forms::RichTextBox());
			this->Text_IP = (gcnew System::Windows::Forms::TextBox());
			this->NumUpDown_SID = (gcnew System::Windows::Forms::NumericUpDown());
			this->table_server_field = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label_IP = (gcnew System::Windows::Forms::Label());
			this->button_connect = (gcnew System::Windows::Forms::Button());
			this->label_Type = (gcnew System::Windows::Forms::Label());
			this->label_Port = (gcnew System::Windows::Forms::Label());
			this->NumUpDown_PORT = (gcnew System::Windows::Forms::NumericUpDown());
			this->comboBox_TYPE = (gcnew System::Windows::Forms::ComboBox());
			this->label_SID = (gcnew System::Windows::Forms::Label());
			this->label_UID = (gcnew System::Windows::Forms::Label());
			this->NumUpDown_UID = (gcnew System::Windows::Forms::NumericUpDown());
			this->table_register_field = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Text_val10 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val5 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val9 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val4 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val8 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val3 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val7 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val2 = (gcnew System::Windows::Forms::TextBox());
			this->Text_val6 = (gcnew System::Windows::Forms::TextBox());
			this->label_reg1 = (gcnew System::Windows::Forms::Label());
			this->label_reg2 = (gcnew System::Windows::Forms::Label());
			this->label_reg3 = (gcnew System::Windows::Forms::Label());
			this->label_reg4 = (gcnew System::Windows::Forms::Label());
			this->label_reg6 = (gcnew System::Windows::Forms::Label());
			this->label_reg7 = (gcnew System::Windows::Forms::Label());
			this->label_reg8 = (gcnew System::Windows::Forms::Label());
			this->label_reg9 = (gcnew System::Windows::Forms::Label());
			this->label_reg10 = (gcnew System::Windows::Forms::Label());
			this->Text_val1 = (gcnew System::Windows::Forms::TextBox());
			this->label_reg5 = (gcnew System::Windows::Forms::Label());
			this->table_lock_field = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->checkBox_lock1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock9 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock10 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock11 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock12 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock13 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock14 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock15 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock16 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock17 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock18 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock19 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock20 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock21 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock22 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock23 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock24 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock25 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock26 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock27 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock28 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock29 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock30 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_lock31 = (gcnew System::Windows::Forms::CheckBox());
			this->label_lock = (gcnew System::Windows::Forms::Label());
			this->label_polling = (gcnew System::Windows::Forms::Label());
			this->table_count_field = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label_count = (gcnew System::Windows::Forms::Label());
			this->button_lock_all = (gcnew System::Windows::Forms::Button());
			this->button_unlock_all = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NumUpDown_SID))->BeginInit();
			this->table_server_field->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NumUpDown_PORT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NumUpDown_UID))->BeginInit();
			this->table_register_field->SuspendLayout();
			this->table_lock_field->SuspendLayout();
			this->table_count_field->SuspendLayout();
			this->SuspendLayout();
			// 
			// TextBox_log
			// 
			this->TextBox_log->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->TextBox_log->Location = System::Drawing::Point(375, 63);
			this->TextBox_log->Name = L"TextBox_log";
			this->TextBox_log->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->TextBox_log->Size = System::Drawing::Size(465, 247);
			this->TextBox_log->TabIndex = 400;
			this->TextBox_log->Text = L"";
			// 
			// Text_IP
			// 
			this->Text_IP->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->Text_IP->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_IP->Location = System::Drawing::Point(34, 5);
			this->Text_IP->Name = L"Text_IP";
			this->Text_IP->Size = System::Drawing::Size(120, 22);
			this->Text_IP->TabIndex = 11;
			this->Text_IP->Text = L"192.168.0.1";
			this->Text_IP->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->Text_IP->Enter += gcnew System::EventHandler(this, &Form1::Text_IP_Enter);
			// 
			// NumUpDown_SID
			// 
			this->NumUpDown_SID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->NumUpDown_SID->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NumUpDown_SID->Location = System::Drawing::Point(650, 5);
			this->NumUpDown_SID->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {31, 0, 0, 0});
			this->NumUpDown_SID->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NumUpDown_SID->Name = L"NumUpDown_SID";
			this->NumUpDown_SID->Size = System::Drawing::Size(50, 22);
			this->NumUpDown_SID->TabIndex = 15;
			this->NumUpDown_SID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NumUpDown_SID->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NumUpDown_SID->Enter += gcnew System::EventHandler(this, &Form1::NumUpDown_SID_Enter);
			// 
			// table_server_field
			// 
			this->table_server_field->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->table_server_field->AutoSize = true;
			this->table_server_field->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->table_server_field->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Inset;
			this->table_server_field->ColumnCount = 11;
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_server_field->Controls->Add(this->label_IP, 0, 0);
			this->table_server_field->Controls->Add(this->Text_IP, 1, 0);
			this->table_server_field->Controls->Add(this->button_connect, 10, 0);
			this->table_server_field->Controls->Add(this->label_Type, 2, 0);
			this->table_server_field->Controls->Add(this->label_Port, 4, 0);
			this->table_server_field->Controls->Add(this->NumUpDown_PORT, 5, 0);
			this->table_server_field->Controls->Add(this->comboBox_TYPE, 3, 0);
			this->table_server_field->Controls->Add(this->label_SID, 8, 0);
			this->table_server_field->Controls->Add(this->label_UID, 6, 0);
			this->table_server_field->Controls->Add(this->NumUpDown_SID, 9, 0);
			this->table_server_field->Controls->Add(this->NumUpDown_UID, 7, 0);
			this->table_server_field->Location = System::Drawing::Point(12, 12);
			this->table_server_field->Name = L"table_server_field";
			this->table_server_field->RowCount = 1;
			this->table_server_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_server_field->Size = System::Drawing::Size(833, 33);
			this->table_server_field->TabIndex = 1;
			// 
			// label_IP
			// 
			this->label_IP->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_IP->AutoSize = true;
			this->label_IP->Location = System::Drawing::Point(5, 10);
			this->label_IP->Name = L"label_IP";
			this->label_IP->Size = System::Drawing::Size(21, 12);
			this->label_IP->TabIndex = 0;
			this->label_IP->Text = L"IP :";
			// 
			// button_connect
			// 
			this->button_connect->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button_connect->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_connect->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_connect->Location = System::Drawing::Point(708, 5);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(120, 23);
			this->button_connect->TabIndex = 16;
			this->button_connect->Text = L"立即更新";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &Form1::button_connect_Click);
			// 
			// label_Type
			// 
			this->label_Type->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_Type->AutoSize = true;
			this->label_Type->Location = System::Drawing::Point(162, 10);
			this->label_Type->Name = L"label_Type";
			this->label_Type->Size = System::Drawing::Size(35, 12);
			this->label_Type->TabIndex = 0;
			this->label_Type->Text = L"Type :";
			// 
			// label_Port
			// 
			this->label_Port->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_Port->AutoSize = true;
			this->label_Port->Location = System::Drawing::Point(373, 10);
			this->label_Port->Name = L"label_Port";
			this->label_Port->Size = System::Drawing::Size(30, 12);
			this->label_Port->TabIndex = 0;
			this->label_Port->Text = L"Port :";
			// 
			// NumUpDown_PORT
			// 
			this->NumUpDown_PORT->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->NumUpDown_PORT->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NumUpDown_PORT->Location = System::Drawing::Point(411, 5);
			this->NumUpDown_PORT->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {65535, 0, 0, 0});
			this->NumUpDown_PORT->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NumUpDown_PORT->Name = L"NumUpDown_PORT";
			this->NumUpDown_PORT->Size = System::Drawing::Size(60, 22);
			this->NumUpDown_PORT->TabIndex = 13;
			this->NumUpDown_PORT->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NumUpDown_PORT->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {502, 0, 0, 0});
			this->NumUpDown_PORT->Enter += gcnew System::EventHandler(this, &Form1::NumUpDown_PORT_Enter);
			// 
			// comboBox_TYPE
			// 
			this->comboBox_TYPE->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->comboBox_TYPE->FormattingEnabled = true;
			this->comboBox_TYPE->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Modbus TCP", L"Modbus RTU over TCP"});
			this->comboBox_TYPE->Location = System::Drawing::Point(205, 5);
			this->comboBox_TYPE->Name = L"comboBox_TYPE";
			this->comboBox_TYPE->Size = System::Drawing::Size(160, 22);
			this->comboBox_TYPE->TabIndex = 12;
			this->comboBox_TYPE->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox_TYPE_SelectedIndexChanged);
			// 
			// label_SID
			// 
			this->label_SID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_SID->AutoSize = true;
			this->label_SID->Location = System::Drawing::Point(591, 10);
			this->label_SID->Name = L"label_SID";
			this->label_SID->Size = System::Drawing::Size(51, 12);
			this->label_SID->TabIndex = 0;
			this->label_SID->Text = L"Slave ID :";
			// 
			// label_UID
			// 
			this->label_UID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_UID->AutoSize = true;
			this->label_UID->Location = System::Drawing::Point(479, 10);
			this->label_UID->Name = L"label_UID";
			this->label_UID->Size = System::Drawing::Size(46, 12);
			this->label_UID->TabIndex = 0;
			this->label_UID->Text = L"Unit ID :";
			// 
			// NumUpDown_UID
			// 
			this->NumUpDown_UID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->NumUpDown_UID->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->NumUpDown_UID->Location = System::Drawing::Point(533, 5);
			this->NumUpDown_UID->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {30, 0, 0, 0});
			this->NumUpDown_UID->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NumUpDown_UID->Name = L"NumUpDown_UID";
			this->NumUpDown_UID->Size = System::Drawing::Size(50, 22);
			this->NumUpDown_UID->TabIndex = 14;
			this->NumUpDown_UID->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->NumUpDown_UID->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->NumUpDown_UID->Enter += gcnew System::EventHandler(this, &Form1::NumUpDown_UID_Enter);
			// 
			// table_register_field
			// 
			this->table_register_field->AutoSize = true;
			this->table_register_field->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->table_register_field->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Outset;
			this->table_register_field->ColumnCount = 4;
			this->table_register_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_register_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_register_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_register_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_register_field->Controls->Add(this->Text_val10, 3, 4);
			this->table_register_field->Controls->Add(this->Text_val5, 1, 4);
			this->table_register_field->Controls->Add(this->Text_val9, 3, 3);
			this->table_register_field->Controls->Add(this->Text_val4, 1, 3);
			this->table_register_field->Controls->Add(this->Text_val8, 3, 2);
			this->table_register_field->Controls->Add(this->Text_val3, 1, 2);
			this->table_register_field->Controls->Add(this->Text_val7, 3, 1);
			this->table_register_field->Controls->Add(this->Text_val2, 1, 1);
			this->table_register_field->Controls->Add(this->Text_val6, 3, 0);
			this->table_register_field->Controls->Add(this->label_reg1, 0, 0);
			this->table_register_field->Controls->Add(this->label_reg2, 0, 1);
			this->table_register_field->Controls->Add(this->label_reg3, 0, 2);
			this->table_register_field->Controls->Add(this->label_reg4, 0, 3);
			this->table_register_field->Controls->Add(this->label_reg6, 2, 0);
			this->table_register_field->Controls->Add(this->label_reg7, 2, 1);
			this->table_register_field->Controls->Add(this->label_reg8, 2, 2);
			this->table_register_field->Controls->Add(this->label_reg9, 2, 3);
			this->table_register_field->Controls->Add(this->label_reg10, 2, 4);
			this->table_register_field->Controls->Add(this->Text_val1, 1, 0);
			this->table_register_field->Controls->Add(this->label_reg5, 0, 4);
			this->table_register_field->Location = System::Drawing::Point(12, 63);
			this->table_register_field->Name = L"table_register_field";
			this->table_register_field->RowCount = 5;
			this->table_register_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_register_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_register_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_register_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_register_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_register_field->Size = System::Drawing::Size(332, 117);
			this->table_register_field->TabIndex = 2;
			// 
			// Text_val10
			// 
			this->Text_val10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val10->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val10->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val10->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val10->Location = System::Drawing::Point(267, 97);
			this->Text_val10->Name = L"Text_val10";
			this->Text_val10->Size = System::Drawing::Size(60, 15);
			this->Text_val10->TabIndex = 30;
			this->Text_val10->Text = L"0";
			this->Text_val10->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val5
			// 
			this->Text_val5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val5->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val5->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val5->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val5->Location = System::Drawing::Point(90, 97);
			this->Text_val5->Name = L"Text_val5";
			this->Text_val5->Size = System::Drawing::Size(60, 15);
			this->Text_val5->TabIndex = 25;
			this->Text_val5->Text = L"0";
			this->Text_val5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val9
			// 
			this->Text_val9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val9->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val9->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val9->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val9->Location = System::Drawing::Point(267, 74);
			this->Text_val9->Name = L"Text_val9";
			this->Text_val9->Size = System::Drawing::Size(60, 15);
			this->Text_val9->TabIndex = 29;
			this->Text_val9->Text = L"0";
			this->Text_val9->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val4
			// 
			this->Text_val4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val4->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val4->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val4->Location = System::Drawing::Point(90, 74);
			this->Text_val4->Name = L"Text_val4";
			this->Text_val4->Size = System::Drawing::Size(60, 15);
			this->Text_val4->TabIndex = 24;
			this->Text_val4->Text = L"0";
			this->Text_val4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val8
			// 
			this->Text_val8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val8->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val8->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val8->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val8->Location = System::Drawing::Point(267, 51);
			this->Text_val8->Name = L"Text_val8";
			this->Text_val8->Size = System::Drawing::Size(60, 15);
			this->Text_val8->TabIndex = 28;
			this->Text_val8->Text = L"0";
			this->Text_val8->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val3
			// 
			this->Text_val3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val3->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val3->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val3->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val3->Location = System::Drawing::Point(90, 51);
			this->Text_val3->Name = L"Text_val3";
			this->Text_val3->Size = System::Drawing::Size(60, 15);
			this->Text_val3->TabIndex = 23;
			this->Text_val3->Text = L"0";
			this->Text_val3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val7
			// 
			this->Text_val7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val7->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val7->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val7->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val7->Location = System::Drawing::Point(267, 28);
			this->Text_val7->Name = L"Text_val7";
			this->Text_val7->Size = System::Drawing::Size(60, 15);
			this->Text_val7->TabIndex = 27;
			this->Text_val7->Text = L"0";
			this->Text_val7->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val2
			// 
			this->Text_val2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val2->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val2->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val2->Location = System::Drawing::Point(90, 28);
			this->Text_val2->Name = L"Text_val2";
			this->Text_val2->Size = System::Drawing::Size(60, 15);
			this->Text_val2->TabIndex = 22;
			this->Text_val2->Text = L"0";
			this->Text_val2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// Text_val6
			// 
			this->Text_val6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val6->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val6->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val6->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val6->Location = System::Drawing::Point(267, 5);
			this->Text_val6->Name = L"Text_val6";
			this->Text_val6->Size = System::Drawing::Size(60, 15);
			this->Text_val6->TabIndex = 26;
			this->Text_val6->Text = L"0";
			this->Text_val6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_reg1
			// 
			this->label_reg1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg1->AutoSize = true;
			this->label_reg1->Location = System::Drawing::Point(5, 6);
			this->label_reg1->Name = L"label_reg1";
			this->label_reg1->Size = System::Drawing::Size(77, 12);
			this->label_reg1->TabIndex = 0;
			this->label_reg1->Text = L"感測器溫度：";
			// 
			// label_reg2
			// 
			this->label_reg2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg2->AutoSize = true;
			this->label_reg2->Location = System::Drawing::Point(5, 29);
			this->label_reg2->Name = L"label_reg2";
			this->label_reg2->Size = System::Drawing::Size(77, 12);
			this->label_reg2->TabIndex = 0;
			this->label_reg2->Text = L"溫度設定值：";
			// 
			// label_reg3
			// 
			this->label_reg3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg3->AutoSize = true;
			this->label_reg3->Location = System::Drawing::Point(17, 52);
			this->label_reg3->Name = L"label_reg3";
			this->label_reg3->Size = System::Drawing::Size(65, 12);
			this->label_reg3->TabIndex = 0;
			this->label_reg3->Text = L"風速狀態：";
			// 
			// label_reg4
			// 
			this->label_reg4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg4->AutoSize = true;
			this->label_reg4->Location = System::Drawing::Point(26, 75);
			this->label_reg4->Name = L"label_reg4";
			this->label_reg4->Size = System::Drawing::Size(56, 12);
			this->label_reg4->TabIndex = 0;
			this->label_reg4->Text = L"ON/OFF：";
			// 
			// label_reg6
			// 
			this->label_reg6->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg6->AutoSize = true;
			this->label_reg6->Location = System::Drawing::Point(182, 6);
			this->label_reg6->Name = L"label_reg6";
			this->label_reg6->Size = System::Drawing::Size(77, 12);
			this->label_reg6->TabIndex = 0;
			this->label_reg6->Text = L"溫度偏移值：";
			// 
			// label_reg7
			// 
			this->label_reg7->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg7->AutoSize = true;
			this->label_reg7->Location = System::Drawing::Point(194, 29);
			this->label_reg7->Name = L"label_reg7";
			this->label_reg7->Size = System::Drawing::Size(65, 12);
			this->label_reg7->TabIndex = 0;
			this->label_reg7->Text = L"定時時間：";
			// 
			// label_reg8
			// 
			this->label_reg8->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg8->AutoSize = true;
			this->label_reg8->Location = System::Drawing::Point(158, 52);
			this->label_reg8->Name = L"label_reg8";
			this->label_reg8->Size = System::Drawing::Size(101, 12);
			this->label_reg8->TabIndex = 0;
			this->label_reg8->Text = L"節能溫度偏移值：";
			// 
			// label_reg9
			// 
			this->label_reg9->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg9->AutoSize = true;
			this->label_reg9->Location = System::Drawing::Point(182, 75);
			this->label_reg9->Name = L"label_reg9";
			this->label_reg9->Size = System::Drawing::Size(77, 12);
			this->label_reg9->TabIndex = 0;
			this->label_reg9->Text = L"內部設定項：";
			// 
			// label_reg10
			// 
			this->label_reg10->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg10->AutoSize = true;
			this->label_reg10->Location = System::Drawing::Point(170, 98);
			this->label_reg10->Name = L"label_reg10";
			this->label_reg10->Size = System::Drawing::Size(89, 12);
			this->label_reg10->TabIndex = 0;
			this->label_reg10->Text = L"輸入輸出接點：";
			// 
			// Text_val1
			// 
			this->Text_val1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Text_val1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->Text_val1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Text_val1->Cursor = System::Windows::Forms::Cursors::Default;
			this->Text_val1->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->Text_val1->Location = System::Drawing::Point(90, 5);
			this->Text_val1->Name = L"Text_val1";
			this->Text_val1->Size = System::Drawing::Size(60, 15);
			this->Text_val1->TabIndex = 21;
			this->Text_val1->Text = L"0";
			this->Text_val1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label_reg5
			// 
			this->label_reg5->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_reg5->AutoSize = true;
			this->label_reg5->Location = System::Drawing::Point(17, 98);
			this->label_reg5->Name = L"label_reg5";
			this->label_reg5->Size = System::Drawing::Size(65, 12);
			this->label_reg5->TabIndex = 0;
			this->label_reg5->Text = L"工作模式：";
			// 
			// table_lock_field
			// 
			this->table_lock_field->AutoSize = true;
			this->table_lock_field->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->table_lock_field->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->table_lock_field->ColumnCount = 16;
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_lock_field->Controls->Add(this->checkBox_lock1, 0, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock2, 1, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock3, 2, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock4, 3, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock5, 4, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock6, 5, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock7, 6, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock8, 7, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock9, 8, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock10, 9, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock11, 10, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock12, 11, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock13, 12, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock14, 13, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock15, 14, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock16, 15, 0);
			this->table_lock_field->Controls->Add(this->checkBox_lock17, 0, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock18, 1, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock19, 2, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock20, 3, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock21, 4, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock22, 5, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock23, 6, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock24, 7, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock25, 8, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock26, 9, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock27, 10, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock28, 11, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock29, 12, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock30, 13, 1);
			this->table_lock_field->Controls->Add(this->checkBox_lock31, 14, 1);
			this->table_lock_field->Location = System::Drawing::Point(12, 238);
			this->table_lock_field->Name = L"table_lock_field";
			this->table_lock_field->RowCount = 2;
			this->table_lock_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->table_lock_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->table_lock_field->Size = System::Drawing::Size(353, 43);
			this->table_lock_field->TabIndex = 3;
			// 
			// checkBox_lock1
			// 
			this->checkBox_lock1->AutoSize = true;
			this->checkBox_lock1->Enabled = false;
			this->checkBox_lock1->Location = System::Drawing::Point(4, 4);
			this->checkBox_lock1->Name = L"checkBox_lock1";
			this->checkBox_lock1->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock1->TabIndex = 101;
			this->checkBox_lock1->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock2
			// 
			this->checkBox_lock2->AutoSize = true;
			this->checkBox_lock2->Enabled = false;
			this->checkBox_lock2->Location = System::Drawing::Point(26, 4);
			this->checkBox_lock2->Name = L"checkBox_lock2";
			this->checkBox_lock2->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock2->TabIndex = 102;
			this->checkBox_lock2->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock3
			// 
			this->checkBox_lock3->AutoSize = true;
			this->checkBox_lock3->Enabled = false;
			this->checkBox_lock3->Location = System::Drawing::Point(48, 4);
			this->checkBox_lock3->Name = L"checkBox_lock3";
			this->checkBox_lock3->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock3->TabIndex = 103;
			this->checkBox_lock3->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock4
			// 
			this->checkBox_lock4->AutoSize = true;
			this->checkBox_lock4->Enabled = false;
			this->checkBox_lock4->Location = System::Drawing::Point(70, 4);
			this->checkBox_lock4->Name = L"checkBox_lock4";
			this->checkBox_lock4->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock4->TabIndex = 104;
			this->checkBox_lock4->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock5
			// 
			this->checkBox_lock5->AutoSize = true;
			this->checkBox_lock5->Enabled = false;
			this->checkBox_lock5->Location = System::Drawing::Point(92, 4);
			this->checkBox_lock5->Name = L"checkBox_lock5";
			this->checkBox_lock5->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock5->TabIndex = 105;
			this->checkBox_lock5->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock6
			// 
			this->checkBox_lock6->AutoSize = true;
			this->checkBox_lock6->Enabled = false;
			this->checkBox_lock6->Location = System::Drawing::Point(114, 4);
			this->checkBox_lock6->Name = L"checkBox_lock6";
			this->checkBox_lock6->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock6->TabIndex = 106;
			this->checkBox_lock6->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock7
			// 
			this->checkBox_lock7->AutoSize = true;
			this->checkBox_lock7->Enabled = false;
			this->checkBox_lock7->Location = System::Drawing::Point(136, 4);
			this->checkBox_lock7->Name = L"checkBox_lock7";
			this->checkBox_lock7->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock7->TabIndex = 107;
			this->checkBox_lock7->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock8
			// 
			this->checkBox_lock8->AutoSize = true;
			this->checkBox_lock8->Enabled = false;
			this->checkBox_lock8->Location = System::Drawing::Point(158, 4);
			this->checkBox_lock8->Name = L"checkBox_lock8";
			this->checkBox_lock8->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock8->TabIndex = 108;
			this->checkBox_lock8->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock9
			// 
			this->checkBox_lock9->AutoSize = true;
			this->checkBox_lock9->Enabled = false;
			this->checkBox_lock9->Location = System::Drawing::Point(180, 4);
			this->checkBox_lock9->Name = L"checkBox_lock9";
			this->checkBox_lock9->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock9->TabIndex = 109;
			this->checkBox_lock9->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock10
			// 
			this->checkBox_lock10->AutoSize = true;
			this->checkBox_lock10->Enabled = false;
			this->checkBox_lock10->Location = System::Drawing::Point(202, 4);
			this->checkBox_lock10->Name = L"checkBox_lock10";
			this->checkBox_lock10->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock10->TabIndex = 110;
			this->checkBox_lock10->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock11
			// 
			this->checkBox_lock11->AutoSize = true;
			this->checkBox_lock11->Enabled = false;
			this->checkBox_lock11->Location = System::Drawing::Point(224, 4);
			this->checkBox_lock11->Name = L"checkBox_lock11";
			this->checkBox_lock11->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock11->TabIndex = 111;
			this->checkBox_lock11->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock12
			// 
			this->checkBox_lock12->AutoSize = true;
			this->checkBox_lock12->Enabled = false;
			this->checkBox_lock12->Location = System::Drawing::Point(246, 4);
			this->checkBox_lock12->Name = L"checkBox_lock12";
			this->checkBox_lock12->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock12->TabIndex = 112;
			this->checkBox_lock12->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock13
			// 
			this->checkBox_lock13->AutoSize = true;
			this->checkBox_lock13->Enabled = false;
			this->checkBox_lock13->Location = System::Drawing::Point(268, 4);
			this->checkBox_lock13->Name = L"checkBox_lock13";
			this->checkBox_lock13->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock13->TabIndex = 113;
			this->checkBox_lock13->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock14
			// 
			this->checkBox_lock14->AutoSize = true;
			this->checkBox_lock14->Enabled = false;
			this->checkBox_lock14->Location = System::Drawing::Point(290, 4);
			this->checkBox_lock14->Name = L"checkBox_lock14";
			this->checkBox_lock14->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock14->TabIndex = 114;
			this->checkBox_lock14->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock15
			// 
			this->checkBox_lock15->AutoSize = true;
			this->checkBox_lock15->Enabled = false;
			this->checkBox_lock15->Location = System::Drawing::Point(312, 4);
			this->checkBox_lock15->Name = L"checkBox_lock15";
			this->checkBox_lock15->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock15->TabIndex = 115;
			this->checkBox_lock15->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock16
			// 
			this->checkBox_lock16->AutoSize = true;
			this->checkBox_lock16->Enabled = false;
			this->checkBox_lock16->Location = System::Drawing::Point(334, 4);
			this->checkBox_lock16->Name = L"checkBox_lock16";
			this->checkBox_lock16->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock16->TabIndex = 116;
			this->checkBox_lock16->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock17
			// 
			this->checkBox_lock17->AutoSize = true;
			this->checkBox_lock17->Enabled = false;
			this->checkBox_lock17->Location = System::Drawing::Point(4, 25);
			this->checkBox_lock17->Name = L"checkBox_lock17";
			this->checkBox_lock17->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock17->TabIndex = 117;
			this->checkBox_lock17->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock18
			// 
			this->checkBox_lock18->AutoSize = true;
			this->checkBox_lock18->Enabled = false;
			this->checkBox_lock18->Location = System::Drawing::Point(26, 25);
			this->checkBox_lock18->Name = L"checkBox_lock18";
			this->checkBox_lock18->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock18->TabIndex = 118;
			this->checkBox_lock18->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock19
			// 
			this->checkBox_lock19->AutoSize = true;
			this->checkBox_lock19->Enabled = false;
			this->checkBox_lock19->Location = System::Drawing::Point(48, 25);
			this->checkBox_lock19->Name = L"checkBox_lock19";
			this->checkBox_lock19->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock19->TabIndex = 119;
			this->checkBox_lock19->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock20
			// 
			this->checkBox_lock20->AutoSize = true;
			this->checkBox_lock20->Enabled = false;
			this->checkBox_lock20->Location = System::Drawing::Point(70, 25);
			this->checkBox_lock20->Name = L"checkBox_lock20";
			this->checkBox_lock20->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock20->TabIndex = 120;
			this->checkBox_lock20->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock21
			// 
			this->checkBox_lock21->AutoSize = true;
			this->checkBox_lock21->Enabled = false;
			this->checkBox_lock21->Location = System::Drawing::Point(92, 25);
			this->checkBox_lock21->Name = L"checkBox_lock21";
			this->checkBox_lock21->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock21->TabIndex = 121;
			this->checkBox_lock21->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock22
			// 
			this->checkBox_lock22->AutoSize = true;
			this->checkBox_lock22->Enabled = false;
			this->checkBox_lock22->Location = System::Drawing::Point(114, 25);
			this->checkBox_lock22->Name = L"checkBox_lock22";
			this->checkBox_lock22->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock22->TabIndex = 122;
			this->checkBox_lock22->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock23
			// 
			this->checkBox_lock23->AutoSize = true;
			this->checkBox_lock23->Enabled = false;
			this->checkBox_lock23->Location = System::Drawing::Point(136, 25);
			this->checkBox_lock23->Name = L"checkBox_lock23";
			this->checkBox_lock23->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock23->TabIndex = 123;
			this->checkBox_lock23->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock24
			// 
			this->checkBox_lock24->AutoSize = true;
			this->checkBox_lock24->Enabled = false;
			this->checkBox_lock24->Location = System::Drawing::Point(158, 25);
			this->checkBox_lock24->Name = L"checkBox_lock24";
			this->checkBox_lock24->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock24->TabIndex = 124;
			this->checkBox_lock24->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock25
			// 
			this->checkBox_lock25->AutoSize = true;
			this->checkBox_lock25->Enabled = false;
			this->checkBox_lock25->Location = System::Drawing::Point(180, 25);
			this->checkBox_lock25->Name = L"checkBox_lock25";
			this->checkBox_lock25->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock25->TabIndex = 125;
			this->checkBox_lock25->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock26
			// 
			this->checkBox_lock26->AutoSize = true;
			this->checkBox_lock26->Enabled = false;
			this->checkBox_lock26->Location = System::Drawing::Point(202, 25);
			this->checkBox_lock26->Name = L"checkBox_lock26";
			this->checkBox_lock26->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock26->TabIndex = 126;
			this->checkBox_lock26->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock27
			// 
			this->checkBox_lock27->AutoSize = true;
			this->checkBox_lock27->Enabled = false;
			this->checkBox_lock27->Location = System::Drawing::Point(224, 25);
			this->checkBox_lock27->Name = L"checkBox_lock27";
			this->checkBox_lock27->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock27->TabIndex = 127;
			this->checkBox_lock27->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock28
			// 
			this->checkBox_lock28->AutoSize = true;
			this->checkBox_lock28->Enabled = false;
			this->checkBox_lock28->Location = System::Drawing::Point(246, 25);
			this->checkBox_lock28->Name = L"checkBox_lock28";
			this->checkBox_lock28->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock28->TabIndex = 128;
			this->checkBox_lock28->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock29
			// 
			this->checkBox_lock29->AutoSize = true;
			this->checkBox_lock29->Enabled = false;
			this->checkBox_lock29->Location = System::Drawing::Point(268, 25);
			this->checkBox_lock29->Name = L"checkBox_lock29";
			this->checkBox_lock29->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock29->TabIndex = 129;
			this->checkBox_lock29->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock30
			// 
			this->checkBox_lock30->AutoSize = true;
			this->checkBox_lock30->Enabled = false;
			this->checkBox_lock30->Location = System::Drawing::Point(290, 25);
			this->checkBox_lock30->Name = L"checkBox_lock30";
			this->checkBox_lock30->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock30->TabIndex = 130;
			this->checkBox_lock30->UseVisualStyleBackColor = true;
			// 
			// checkBox_lock31
			// 
			this->checkBox_lock31->AutoSize = true;
			this->checkBox_lock31->Enabled = false;
			this->checkBox_lock31->Location = System::Drawing::Point(312, 25);
			this->checkBox_lock31->Name = L"checkBox_lock31";
			this->checkBox_lock31->Size = System::Drawing::Size(15, 14);
			this->checkBox_lock31->TabIndex = 131;
			this->checkBox_lock31->UseVisualStyleBackColor = true;
			// 
			// label_lock
			// 
			this->label_lock->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label_lock->AutoSize = true;
			this->label_lock->Location = System::Drawing::Point(10, 223);
			this->label_lock->Name = L"label_lock";
			this->label_lock->Size = System::Drawing::Size(178, 12);
			this->label_lock->TabIndex = 0;
			this->label_lock->Text = L"Modbus 鎖定（打勾表示鎖定）：";
			// 
			// label_polling
			// 
			this->label_polling->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->label_polling->AutoSize = true;
			this->label_polling->Location = System::Drawing::Point(5, 5);
			this->label_polling->Name = L"label_polling";
			this->label_polling->Size = System::Drawing::Size(44, 12);
			this->label_polling->TabIndex = 0;
			this->label_polling->Text = L"Polling :";
			// 
			// table_count_field
			// 
			this->table_count_field->AutoSize = true;
			this->table_count_field->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->table_count_field->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Outset;
			this->table_count_field->ColumnCount = 2;
			this->table_count_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_count_field->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->table_count_field->Controls->Add(this->label_count, 1, 0);
			this->table_count_field->Controls->Add(this->label_polling, 0, 0);
			this->table_count_field->Location = System::Drawing::Point(222, 191);
			this->table_count_field->Name = L"table_count_field";
			this->table_count_field->RowCount = 1;
			this->table_count_field->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->table_count_field->Size = System::Drawing::Size(122, 22);
			this->table_count_field->TabIndex = 0;
			// 
			// label_count
			// 
			this->label_count->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label_count->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label_count->Font = (gcnew System::Drawing::Font(L"Verdana", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_count->Location = System::Drawing::Point(57, 2);
			this->label_count->Name = L"label_count";
			this->label_count->Size = System::Drawing::Size(60, 18);
			this->label_count->TabIndex = 0;
			this->label_count->Text = L"0";
			this->label_count->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_lock_all
			// 
			this->button_lock_all->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_lock_all->Location = System::Drawing::Point(98, 287);
			this->button_lock_all->Name = L"button_lock_all";
			this->button_lock_all->Size = System::Drawing::Size(75, 23);
			this->button_lock_all->TabIndex = 301;
			this->button_lock_all->Text = L"全部鎖定";
			this->button_lock_all->UseVisualStyleBackColor = true;
			this->button_lock_all->Click += gcnew System::EventHandler(this, &Form1::button_lock_all_Click);
			// 
			// button_unlock_all
			// 
			this->button_unlock_all->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button_unlock_all->Location = System::Drawing::Point(186, 287);
			this->button_unlock_all->Name = L"button_unlock_all";
			this->button_unlock_all->Size = System::Drawing::Size(75, 23);
			this->button_unlock_all->TabIndex = 302;
			this->button_unlock_all->Text = L"全部解鎖";
			this->button_unlock_all->UseVisualStyleBackColor = true;
			this->button_unlock_all->Click += gcnew System::EventHandler(this, &Form1::button_unlock_all_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 322);
			this->Controls->Add(this->button_unlock_all);
			this->Controls->Add(this->button_lock_all);
			this->Controls->Add(this->table_count_field);
			this->Controls->Add(this->label_lock);
			this->Controls->Add(this->table_lock_field);
			this->Controls->Add(this->table_register_field);
			this->Controls->Add(this->table_server_field);
			this->Controls->Add(this->TextBox_log);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Honeywell DT200 controller v1.2";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NumUpDown_SID))->EndInit();
			this->table_server_field->ResumeLayout(false);
			this->table_server_field->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NumUpDown_PORT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->NumUpDown_UID))->EndInit();
			this->table_register_field->ResumeLayout(false);
			this->table_register_field->PerformLayout();
			this->table_lock_field->ResumeLayout(false);
			this->table_lock_field->PerformLayout();
			this->table_count_field->ResumeLayout(false);
			this->table_count_field->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void println(System::String^ str) {
				time_t rawtime;
				struct tm * timeinfo;
				char buffer[80];

				time (&rawtime);
				timeinfo = localtime(&rawtime);

				strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
				System::String^ timestamp = gcnew String(buffer);

				TextBox_log->AppendText("[" + timestamp + "] " + str + "\n");
				TextBox_log->ScrollToCaret();
			 }

	private: System::Void dt200_update() {
				unsigned short uid = (unsigned short)NumUpDown_UID->Value;
				unsigned short sid = (unsigned short)NumUpDown_SID->Value;
				unsigned short unit_status[32][11];
				unsigned short return_value;

				std::string server_ip;
				MarshalString(Text_IP->Text, server_ip);
				DT200_SERVER_IP = (char*)server_ip.c_str();
				DT200_SERVER_PORT = (unsigned short)NumUpDown_PORT->Value;
				DT200_SERVER_TYPE = comboBox_TYPE->SelectedIndex;
				println("Updated " + Text_IP->Text + ":" + DT200_SERVER_PORT);
				//println("HOST: " + Text_IP->Text + ":" + DT200_SERVER_PORT + ", TYPE: " + DT200_SERVER_TYPE + ", UID: " + uid.ToString() + ", SID: " + sid.ToString());

				array<TextBox^,1>^ Text_vals = {Text_val1, Text_val2, Text_val3, Text_val4, Text_val5
											  , Text_val6, Text_val7, Text_val8, Text_val9, Text_val10};

				array<CheckBox^,1>^ checkBox_locks = {checkBox_lock1,  checkBox_lock2,  checkBox_lock3,  checkBox_lock4,  checkBox_lock5
													, checkBox_lock6,  checkBox_lock7,  checkBox_lock8,  checkBox_lock9,  checkBox_lock10
													, checkBox_lock11, checkBox_lock12, checkBox_lock13, checkBox_lock14, checkBox_lock15
													, checkBox_lock16, checkBox_lock17, checkBox_lock18, checkBox_lock19, checkBox_lock20
													, checkBox_lock21, checkBox_lock22, checkBox_lock23, checkBox_lock24, checkBox_lock25
													, checkBox_lock26, checkBox_lock27, checkBox_lock28, checkBox_lock29, checkBox_lock30
													, checkBox_lock31};
				 
				label_count->Text = (int::Parse(label_count->Text) + 1).ToString();
				
				return_value = modbus_dt200::dt200_global_status_get(DT200_SERVER_IP, DT200_SERVER_PORT, DT200_SERVER_TYPE, uid, unit_status);
				if (return_value == EXIT_MODBUS_FAILURE) {
					for (int i=0; i<10; i++)
						Text_vals[i]->Text = "FAILED";
					return;
				}

				for (int i=0; i<Text_vals->Length; i++) {
					func_regs[sid][i] = unit_status[sid][i];
					Text_vals[i]->Text = unit_status[sid][i].ToString();
					//System::Windows::Forms::Application::DoEvents();
				}
				for (int i=1; i<32; i++) {
					unsigned short index = i - 1;
					func_regs[i][10] = unit_status[i][10];
					checkBox_locks[index]->Checked = unit_status[i][10] > 0 ? true : false;
					checkBox_locks[index]->Enabled = true;
				}
			 }

	private: System::Void button_connect_Click(System::Object^  sender, System::EventArgs^  e) {
				 dt200_update();
				 TextBox_log->Focus();
			 }
			 
	private: System::Void checkBox_locks_Click(System::Object^  sender, System::EventArgs^  e) {
				 unsigned short uid = (unsigned short)NumUpDown_UID->Value;
				 CheckBox^ checkBox = (CheckBox^)(sender);
				 
				 std::string server_ip;
				 MarshalString(Text_IP->Text, server_ip);
				 DT200_SERVER_IP = (char*)server_ip.c_str();
				 DT200_SERVER_PORT = (unsigned short)NumUpDown_PORT->Value;
				 DT200_SERVER_TYPE = comboBox_TYPE->SelectedIndex;

				 for (int i=1; i<32; i++) {
					 if (checkBox->Name == "checkBox_lock" + i.ToString()) {
						if (checkBox->Checked) {
							modbus_dt200::dt200_drive_lock(DT200_SERVER_IP, DT200_SERVER_PORT, DT200_SERVER_TYPE, uid, i);
							println("Lock slave(" + i.ToString() + ")");
						} else {
							modbus_dt200::dt200_drive_unlock(DT200_SERVER_IP, DT200_SERVER_PORT, DT200_SERVER_TYPE, uid, i);
							println("Unlock slave(" + i.ToString() + ")");
						}
						break;
					 }
				 }
				 TextBox_log->Focus();
			 }

	private: System::Void button_lock_all_Click(System::Object^  sender, System::EventArgs^  e) {
				 unsigned short uid = (unsigned short)NumUpDown_UID->Value;
				 
				 std::string server_ip;
				 MarshalString(Text_IP->Text, server_ip);
				 DT200_SERVER_IP = (char*)server_ip.c_str();
				 DT200_SERVER_PORT = (unsigned short)NumUpDown_PORT->Value;
				 DT200_SERVER_TYPE = comboBox_TYPE->SelectedIndex;

				 modbus_dt200::dt200_drive_lock(DT200_SERVER_IP, DT200_SERVER_PORT, DT200_SERVER_TYPE, uid, DT200_DRIVE_ALL);
				 dt200_update();
				 println("Lock all slaves.");
				 TextBox_log->Focus();
			 }
	private: System::Void button_unlock_all_Click(System::Object^  sender, System::EventArgs^  e) {
				 unsigned short uid = (unsigned short)NumUpDown_UID->Value;
				 
				 std::string server_ip;
				 MarshalString(Text_IP->Text, server_ip);
				 DT200_SERVER_IP = (char*)server_ip.c_str();
				 DT200_SERVER_PORT = (unsigned short)NumUpDown_PORT->Value;
				 DT200_SERVER_TYPE = comboBox_TYPE->SelectedIndex;

				 modbus_dt200::dt200_drive_unlock(DT200_SERVER_IP, DT200_SERVER_PORT, DT200_SERVER_TYPE, uid, DT200_DRIVE_ALL);
				 dt200_update();
				 println("Unlock all slaves.");
				 TextBox_log->Focus();
			 }
	private: System::Void Text_vals_submit(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyCode != Keys::Enter)
					 return;
				 unsigned short uid = (unsigned short)NumUpDown_UID->Value;
				 unsigned short sid = (unsigned short)NumUpDown_SID->Value;
				 TextBox^ textBox = (TextBox^)(sender);
				 unsigned short value = int::Parse(textBox->Text);
				 
				 std::string server_ip;
				 MarshalString(Text_IP->Text, server_ip);
				 DT200_SERVER_IP = (char*)server_ip.c_str();
				 DT200_SERVER_PORT = (unsigned short)NumUpDown_PORT->Value;
				 DT200_SERVER_TYPE = comboBox_TYPE->SelectedIndex;

				 for (int i=1; i<11; i++) {
					 if (textBox->Name == "Text_val" + i.ToString()) {
						modbus_dt200::dt200_register_set(DT200_SERVER_IP, DT200_SERVER_PORT, DT200_SERVER_TYPE, uid, sid, i, value);
						dt200_update();
						println("Set slave(" + sid.ToString() + ") func(" + i.ToString() + ") to " + value.ToString());
						break;
					 }
				 }
				 TextBox_log->Focus();
			 }

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 array<TextBox^,1>^ Text_vals = {Text_val1, Text_val2, Text_val3, Text_val4, Text_val5
											   , Text_val6, Text_val7, Text_val8, Text_val9, Text_val10};

				 array<CheckBox^,1>^ checkBox_locks = {checkBox_lock1,  checkBox_lock2,  checkBox_lock3,  checkBox_lock4,  checkBox_lock5
													 , checkBox_lock6,  checkBox_lock7,  checkBox_lock8,  checkBox_lock9,  checkBox_lock10
													 , checkBox_lock11, checkBox_lock12, checkBox_lock13, checkBox_lock14, checkBox_lock15
													 , checkBox_lock16, checkBox_lock17, checkBox_lock18, checkBox_lock19, checkBox_lock20
													 , checkBox_lock21, checkBox_lock22, checkBox_lock23, checkBox_lock24, checkBox_lock25
													 , checkBox_lock26, checkBox_lock27, checkBox_lock28, checkBox_lock29, checkBox_lock30
													 , checkBox_lock31};
				
				for (int i=0; i<Text_vals->Length; i++) {
					Text_vals[i]->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Text_vals_submit);
				}
				for (int i=0; i<checkBox_locks->Length; i++) {
					checkBox_locks[i]->Click += gcnew System::EventHandler(this, &Form1::checkBox_locks_Click);
				}
				comboBox_TYPE->SelectedIndex = 0;
			 }

	private: System::Void Text_IP_Enter(System::Object^  sender, System::EventArgs^  e) {
				Text_IP->SelectAll();
			 }
	private: System::Void NumUpDown_PORT_Enter(System::Object^  sender, System::EventArgs^  e) {
				NumUpDown_PORT->Select(0, NumUpDown_PORT->Text->Length);
			 }
	private: System::Void NumUpDown_UID_Enter(System::Object^  sender, System::EventArgs^  e) {
				NumUpDown_UID->Select(0, NumUpDown_UID->Text->Length);
			 }
	private: System::Void NumUpDown_SID_Enter(System::Object^  sender, System::EventArgs^  e) {
				NumUpDown_SID->Select(0, NumUpDown_SID->Text->Length);
			 }
	private: System::Void comboBox_TYPE_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				switch (comboBox_TYPE->SelectedIndex) {
					case 0:
						NumUpDown_PORT->Text = "502";
						break;
					case 1:
						NumUpDown_PORT->Text = "4660";
						break;
				}
			 }
};
}
