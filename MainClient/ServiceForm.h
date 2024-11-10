#pragma once

namespace MainClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ServiceForm
	/// </summary>
	public ref class ServiceForm : public System::Windows::Forms::Form
	{
	public:
		ServiceForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ServiceForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ ServicesLbl;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureWeather;
	private: System::Windows::Forms::PictureBox^ pictureStocks;
	private: System::Windows::Forms::PictureBox^ pictureExchange;
	private: System::Windows::Forms::Label^ weatherLbl;
	private: System::Windows::Forms::Label^ stockLbl1;
	private: System::Windows::Forms::Label^ exchangeLbl;






	private: System::Windows::Forms::Label^ stockLbl2;
	private: System::Windows::Forms::Button^ btnSub1;
	private: System::Windows::Forms::Button^ btnUnsub1;


	private: System::Windows::Forms::Button^ btnSub2;
	private: System::Windows::Forms::Button^ btnUnsub2;


	private: System::Windows::Forms::Button^ btnSub3;
	private: System::Windows::Forms::Button^ btnUnsub3;





	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ServiceForm::typeid));
			this->ServicesLbl = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureWeather = (gcnew System::Windows::Forms::PictureBox());
			this->pictureStocks = (gcnew System::Windows::Forms::PictureBox());
			this->pictureExchange = (gcnew System::Windows::Forms::PictureBox());
			this->weatherLbl = (gcnew System::Windows::Forms::Label());
			this->stockLbl1 = (gcnew System::Windows::Forms::Label());
			this->exchangeLbl = (gcnew System::Windows::Forms::Label());
			this->stockLbl2 = (gcnew System::Windows::Forms::Label());
			this->btnSub1 = (gcnew System::Windows::Forms::Button());
			this->btnUnsub1 = (gcnew System::Windows::Forms::Button());
			this->btnSub2 = (gcnew System::Windows::Forms::Button());
			this->btnUnsub2 = (gcnew System::Windows::Forms::Button());
			this->btnSub3 = (gcnew System::Windows::Forms::Button());
			this->btnUnsub3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureWeather))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureStocks))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureExchange))->BeginInit();
			this->SuspendLayout();
			// 
			// ServicesLbl
			// 
			this->ServicesLbl->AutoSize = true;
			this->ServicesLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ServicesLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->ServicesLbl->Location = System::Drawing::Point(93, 36);
			this->ServicesLbl->Name = L"ServicesLbl";
			this->ServicesLbl->Size = System::Drawing::Size(769, 43);
			this->ServicesLbl->TabIndex = 0;
			this->ServicesLbl->Text = L"Select services you would like to subscribe to:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(53, 104);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(258, 383);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(335, 104);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(258, 383);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(619, 104);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(258, 383);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// pictureWeather
			// 
			this->pictureWeather->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureWeather.Image")));
			this->pictureWeather->Location = System::Drawing::Point(78, 114);
			this->pictureWeather->Name = L"pictureWeather";
			this->pictureWeather->Size = System::Drawing::Size(208, 169);
			this->pictureWeather->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureWeather->TabIndex = 0;
			this->pictureWeather->TabStop = false;
			// 
			// pictureStocks
			// 
			this->pictureStocks->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureStocks.Image")));
			this->pictureStocks->Location = System::Drawing::Point(357, 114);
			this->pictureStocks->Name = L"pictureStocks";
			this->pictureStocks->Size = System::Drawing::Size(213, 169);
			this->pictureStocks->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureStocks->TabIndex = 4;
			this->pictureStocks->TabStop = false;
			// 
			// pictureExchange
			// 
			this->pictureExchange->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureExchange.Image")));
			this->pictureExchange->Location = System::Drawing::Point(641, 114);
			this->pictureExchange->Name = L"pictureExchange";
			this->pictureExchange->Size = System::Drawing::Size(212, 169);
			this->pictureExchange->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureExchange->TabIndex = 5;
			this->pictureExchange->TabStop = false;
			// 
			// weatherLbl
			// 
			this->weatherLbl->AutoSize = true;
			this->weatherLbl->BackColor = System::Drawing::Color::Transparent;
			this->weatherLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->weatherLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->weatherLbl->Location = System::Drawing::Point(62, 300);
			this->weatherLbl->Name = L"weatherLbl";
			this->weatherLbl->Size = System::Drawing::Size(240, 22);
			this->weatherLbl->TabIndex = 6;
			this->weatherLbl->Text = L"Hourly weather forecast";
			// 
			// stockLbl1
			// 
			this->stockLbl1->AutoSize = true;
			this->stockLbl1->BackColor = System::Drawing::Color::Transparent;
			this->stockLbl1->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stockLbl1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->stockLbl1->Location = System::Drawing::Point(376, 300);
			this->stockLbl1->Name = L"stockLbl1";
			this->stockLbl1->Size = System::Drawing::Size(175, 22);
			this->stockLbl1->TabIndex = 7;
			this->stockLbl1->Text = L"Minute by minute";
			// 
			// exchangeLbl
			// 
			this->exchangeLbl->AutoSize = true;
			this->exchangeLbl->BackColor = System::Drawing::Color::Transparent;
			this->exchangeLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exchangeLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->exchangeLbl->Location = System::Drawing::Point(648, 300);
			this->exchangeLbl->Name = L"exchangeLbl";
			this->exchangeLbl->Size = System::Drawing::Size(196, 22);
			this->exchangeLbl->TabIndex = 8;
			this->exchangeLbl->Text = L"Daily exchange rate";
			// 
			// stockLbl2
			// 
			this->stockLbl2->AutoSize = true;
			this->stockLbl2->BackColor = System::Drawing::Color::Transparent;
			this->stockLbl2->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stockLbl2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)));
			this->stockLbl2->Location = System::Drawing::Point(396, 322);
			this->stockLbl2->Name = L"stockLbl2";
			this->stockLbl2->Size = System::Drawing::Size(141, 22);
			this->stockLbl2->TabIndex = 9;
			this->stockLbl2->Text = L"stock forecast";
			// 
			// btnSub1
			// 
			this->btnSub1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSub1->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSub1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnSub1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSub1.Image")));
			this->btnSub1->Location = System::Drawing::Point(89, 367);
			this->btnSub1->Name = L"btnSub1";
			this->btnSub1->Size = System::Drawing::Size(179, 39);
			this->btnSub1->TabIndex = 10;
			this->btnSub1->Text = L"Subscribe";
			this->btnSub1->UseVisualStyleBackColor = true;
			this->btnSub1->Click += gcnew System::EventHandler(this, &ServiceForm::btnSub1_Click);
			// 
			// btnUnsub1
			// 
			this->btnUnsub1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUnsub1->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUnsub1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->btnUnsub1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUnsub1.Image")));
			this->btnUnsub1->Location = System::Drawing::Point(89, 422);
			this->btnUnsub1->Name = L"btnUnsub1";
			this->btnUnsub1->Size = System::Drawing::Size(179, 38);
			this->btnUnsub1->TabIndex = 11;
			this->btnUnsub1->Text = L"Unsubscribe";
			this->btnUnsub1->UseVisualStyleBackColor = true;
			this->btnUnsub1->Click += gcnew System::EventHandler(this, &ServiceForm::btnUnsub1_Click);
			// 
			// btnSub2
			// 
			this->btnSub2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSub2->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSub2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnSub2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSub2.Image")));
			this->btnSub2->Location = System::Drawing::Point(372, 367);
			this->btnSub2->Name = L"btnSub2";
			this->btnSub2->Size = System::Drawing::Size(179, 39);
			this->btnSub2->TabIndex = 12;
			this->btnSub2->Text = L"Subscribe";
			this->btnSub2->UseVisualStyleBackColor = true;
			this->btnSub2->Click += gcnew System::EventHandler(this, &ServiceForm::btnSub2_Click);
			// 
			// btnUnsub2
			// 
			this->btnUnsub2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUnsub2->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUnsub2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->btnUnsub2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUnsub2.Image")));
			this->btnUnsub2->Location = System::Drawing::Point(372, 422);
			this->btnUnsub2->Name = L"btnUnsub2";
			this->btnUnsub2->Size = System::Drawing::Size(179, 38);
			this->btnUnsub2->TabIndex = 13;
			this->btnUnsub2->Text = L"Unsubscribe";
			this->btnUnsub2->UseVisualStyleBackColor = true;
			this->btnUnsub2->Click += gcnew System::EventHandler(this, &ServiceForm::btnUnsub2_Click);
			// 
			// btnSub3
			// 
			this->btnSub3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSub3->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSub3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(71)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btnSub3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSub3.Image")));
			this->btnSub3->Location = System::Drawing::Point(656, 367);
			this->btnSub3->Name = L"btnSub3";
			this->btnSub3->Size = System::Drawing::Size(179, 39);
			this->btnSub3->TabIndex = 14;
			this->btnSub3->Text = L"Subscribe";
			this->btnSub3->UseVisualStyleBackColor = true;
			this->btnSub3->Click += gcnew System::EventHandler(this, &ServiceForm::btnSub3_Click);
			// 
			// btnUnsub3
			// 
			this->btnUnsub3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnUnsub3->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUnsub3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(71)), static_cast<System::Int32>(static_cast<System::Byte>(12)),
				static_cast<System::Int32>(static_cast<System::Byte>(21)));
			this->btnUnsub3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUnsub3.Image")));
			this->btnUnsub3->Location = System::Drawing::Point(656, 422);
			this->btnUnsub3->Name = L"btnUnsub3";
			this->btnUnsub3->Size = System::Drawing::Size(179, 38);
			this->btnUnsub3->TabIndex = 15;
			this->btnUnsub3->Text = L"Unsubscribe";
			this->btnUnsub3->UseVisualStyleBackColor = true;
			this->btnUnsub3->Click += gcnew System::EventHandler(this, &ServiceForm::btnUnsub3_Click);
			// 
			// ServiceForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(201)),
				static_cast<System::Int32>(static_cast<System::Byte>(227)));
			this->ClientSize = System::Drawing::Size(925, 544);
			this->Controls->Add(this->btnUnsub3);
			this->Controls->Add(this->btnSub3);
			this->Controls->Add(this->btnUnsub2);
			this->Controls->Add(this->btnSub2);
			this->Controls->Add(this->btnUnsub1);
			this->Controls->Add(this->btnSub1);
			this->Controls->Add(this->stockLbl2);
			this->Controls->Add(this->exchangeLbl);
			this->Controls->Add(this->stockLbl1);
			this->Controls->Add(this->weatherLbl);
			this->Controls->Add(this->pictureExchange);
			this->Controls->Add(this->pictureStocks);
			this->Controls->Add(this->pictureWeather);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->ServicesLbl);
			this->Name = L"ServiceForm";
			this->Text = L"Subscribe";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureWeather))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureStocks))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureExchange))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnSub1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnSub2_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnSub3_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnUnsub1_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void btnUnsub2_Click(System::Object^ sender, System::EventArgs^ e);
	
	private: System::Void btnUnsub3_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
