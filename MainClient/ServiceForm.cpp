#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

#include <msclr/marshal.h>

#include "ServiceForm.h"
#include "WeatherForecastServiceForm.h"
#include "StockForecastForm1.h"
#include "CurrencyForm.h"

MainClient::ServiceForm::ServiceForm(void)
{
	InitializeComponent();
}

MainClient::ServiceForm::ServiceForm(String^ userName)
{
    InitializeComponent();
    UsernameLbl->Text = userName;

    if (IsUserSubscribed("usersOfWeatherService.txt", userName)) {
        btnSub1->Text = "Watch";
        btnSub1->Visible = true;
        btnUnsub1->Visible = true;
    }
    else {
        btnSub1->Text = "Subscribe";
        btnSub1->Visible = true;
        btnUnsub1->Visible = false;
    }

    if (IsUserSubscribed("usersOfStocksService.txt", userName)) {
        btnSub2->Text = "Watch";
        btnSub2->Visible = true;
        btnUnsub2->Visible = true;
    }
    else {
        btnSub2->Text = "Subscribe";
        btnSub2->Visible = true;
        btnUnsub2->Visible = false;
    }

    if (IsUserSubscribed("usersOfCurrencyService.txt", userName)) {
        btnSub3->Text = "Watch";
        btnSub3->Visible = true;
        btnUnsub3->Visible = true;
    }
    else {
        btnSub3->Text = "Subscribe";
        btnSub3->Visible = true;
        btnUnsub3->Visible = false;
    }
}

MainClient::ServiceForm::~ServiceForm()
{
	if (components) {
		delete components;
	}
}

void MainClient::ServiceForm::InitializeComponent(void)
{
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ServiceForm::typeid));
    this->ServicesLbl = (gcnew System::Windows::Forms::Label());
    this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
    this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
    this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
    this->pictureWeather = (gcnew System::Windows::Forms::PictureBox());
    this->pictureStocks = (gcnew System::Windows::Forms::PictureBox());
    this->pictureExchange = (gcnew System::Windows::Forms::PictureBox());
    this->weatherLbl1 = (gcnew System::Windows::Forms::Label());
    this->stockLbl1 = (gcnew System::Windows::Forms::Label());
    this->exchangeLbl = (gcnew System::Windows::Forms::Label());
    this->stockLbl2 = (gcnew System::Windows::Forms::Label());
    this->btnSub1 = (gcnew System::Windows::Forms::Button());
    this->btnUnsub1 = (gcnew System::Windows::Forms::Button());
    this->btnSub2 = (gcnew System::Windows::Forms::Button());
    this->btnUnsub2 = (gcnew System::Windows::Forms::Button());
    this->btnSub3 = (gcnew System::Windows::Forms::Button());
    this->btnUnsub3 = (gcnew System::Windows::Forms::Button());
    this->UsernameLbl = (gcnew System::Windows::Forms::Label());
    this->weatherLbl2 = (gcnew System::Windows::Forms::Label());
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
    this->ServicesLbl->Location = System::Drawing::Point(50, 40);
    this->ServicesLbl->Name = L"ServicesLbl";
    this->ServicesLbl->Size = System::Drawing::Size(750, 42);
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
    // weatherLbl1
    // 
    this->weatherLbl1->AutoSize = true;
    this->weatherLbl1->BackColor = System::Drawing::Color::Transparent;
    this->weatherLbl1->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weatherLbl1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->weatherLbl1->Location = System::Drawing::Point(99, 300);
    this->weatherLbl1->Name = L"weatherLbl1";
    this->weatherLbl1->Size = System::Drawing::Size(159, 22);
    this->weatherLbl1->TabIndex = 6;
    this->weatherLbl1->Text = L"Hourly weather";
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
    this->btnUnsub1->Visible = false;
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
    this->btnUnsub2->Visible = false;
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
    this->btnUnsub3->Visible = false;
    this->btnUnsub3->Click += gcnew System::EventHandler(this, &ServiceForm::btnUnsub3_Click);
    // 
    // UsernameLbl
    // 
    this->UsernameLbl->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
        | System::Windows::Forms::AnchorStyles::Right));
    this->UsernameLbl->AutoSize = true;
    this->UsernameLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->UsernameLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
        static_cast<System::Int32>(static_cast<System::Byte>(179)));
    this->UsernameLbl->Location = System::Drawing::Point(794, 9);
    this->UsernameLbl->Name = L"UsernameLbl";
    this->UsernameLbl->Size = System::Drawing::Size(119, 26);
    this->UsernameLbl->TabIndex = 16;
    this->UsernameLbl->Text = L"username";
    this->UsernameLbl->TextAlign = System::Drawing::ContentAlignment::TopRight;
    // 
    // weatherLbl2
    // 
    this->weatherLbl2->AutoSize = true;
    this->weatherLbl2->BackColor = System::Drawing::Color::Transparent;
    this->weatherLbl2->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weatherLbl2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->weatherLbl2->Location = System::Drawing::Point(138, 322);
    this->weatherLbl2->Name = L"weatherLbl2";
    this->weatherLbl2->Size = System::Drawing::Size(86, 22);
    this->weatherLbl2->TabIndex = 17;
    this->weatherLbl2->Text = L"forecast";
    // 
    // ServiceForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(201)),
        static_cast<System::Int32>(static_cast<System::Byte>(227)));
    this->ClientSize = System::Drawing::Size(925, 544);
    this->Controls->Add(this->weatherLbl2);
    this->Controls->Add(this->UsernameLbl);
    this->Controls->Add(this->btnUnsub3);
    this->Controls->Add(this->btnSub3);
    this->Controls->Add(this->btnUnsub2);
    this->Controls->Add(this->btnSub2);
    this->Controls->Add(this->btnUnsub1);
    this->Controls->Add(this->btnSub1);
    this->Controls->Add(this->stockLbl2);
    this->Controls->Add(this->exchangeLbl);
    this->Controls->Add(this->stockLbl1);
    this->Controls->Add(this->weatherLbl1);
    this->Controls->Add(this->pictureExchange);
    this->Controls->Add(this->pictureStocks);
    this->Controls->Add(this->pictureWeather);
    this->Controls->Add(this->pictureBox3);
    this->Controls->Add(this->pictureBox2);
    this->Controls->Add(this->pictureBox1);
    this->Controls->Add(this->ServicesLbl);
    this->MaximumSize = System::Drawing::Size(943, 591);
    this->MinimumSize = System::Drawing::Size(943, 591);
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

// weather forecast
System::Void MainClient::ServiceForm::btnSub1_Click(System::Object^ sender, System::EventArgs^ e)
{
    IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(UsernameLbl->Text);
    std::string userName = static_cast<const char*>(ptrToNativeString.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);

    if (btnSub1->Text != "Watch")
    {
        std::ofstream file("usersOfWeatherService.txt", std::ios::app);
        if (file.is_open())
        {
            file << userName << std::endl;
            file.close();
        }

        logServiceAction(userName, "Weather Forecast", "Subscribe");
    }

    this->Hide();

    WeatherForecastServiceForm^ weatherForecastForm = gcnew WeatherForecastServiceForm(UsernameLbl->Text);

    weatherForecastForm->UpdateSubscribersList();  // Оновлюємо список користувачів
    weatherForecastForm->ShowDialog();

    this->Close();
}

//Stocks forecast
System::Void MainClient::ServiceForm::btnSub2_Click(System::Object^ sender, System::EventArgs^ e)
{
    IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(UsernameLbl->Text);
    std::string userName = static_cast<const char*>(ptrToNativeString.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);

    if (btnSub2->Text != "Watch")
    {
        std::ofstream file("usersOfStocksService.txt", std::ios::app);
        if (file.is_open())
        {
            file << userName << std::endl;
            file.close();
        }

        logServiceAction(userName, "Stocks Forecast", "Subscribe");
    }

    this->Hide();

    StockForecastForm^ stockForecastForm = gcnew StockForecastForm(UsernameLbl->Text);

    stockForecastForm->UpdateSubscribersList();  
    stockForecastForm->ShowDialog();

    this->Close();
}

System::Void MainClient::ServiceForm::btnSub3_Click(System::Object^ sender, System::EventArgs^ e)
{
    IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(UsernameLbl->Text);
    std::string userName = static_cast<const char*>(ptrToNativeString.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);

    std::string request;

    if (btnSub3->Text != "Watch")
    {
        std::ofstream file("usersOfCurrencyService.txt", std::ios::app);
        if (file.is_open())
        {
            file << userName << std::endl;
            file.close();
        }

        logServiceAction(userName, "Currency Forecast", "Subscribe");
    }

    this->Hide();

    CurrencyForm^ currencyForm = gcnew CurrencyForm(UsernameLbl->Text);

    currencyForm->UpdateSubscribersList();
    currencyForm->ShowDialog();

    this->Close();
}

System::Void MainClient::ServiceForm::btnUnsub1_Click(System::Object^ sender, System::EventArgs^ e)
{
    onUnSub("usersOfWeatherService.txt", 1);
}

System::Void MainClient::ServiceForm::btnUnsub2_Click(System::Object^ sender, System::EventArgs^ e)
{
    onUnSub("usersOfStocksService.txt", 2);
}

System::Void MainClient::ServiceForm::btnUnsub3_Click(System::Object^ sender, System::EventArgs^ e)
{
    onUnSub("usersOfCurrencyService.txt", 3);
}

void MainClient::ServiceForm::onUnSub(const std::string& filename, size_t type)
{
    IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(UsernameLbl->Text);
    std::string userName = static_cast<const char*>(ptrToNativeString.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);

    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        throw gcnew System::IO::IOException("Unable to open the subscription file for reading!");
    }

    std::vector<std::string> lines;
    std::string line;
    
    while (std::getline(inputFile, line)) {
        if (line != userName) {
            lines.push_back(line);
        }
    }
    inputFile.close();

    if (type == 1) {
        btnSub1->Visible = true;
        btnSub1->Text = "Subscribe";
        btnUnsub1->Visible = false;
        logServiceAction(userName, "Weather Forecast", "Unsubscribe");
    }
    else if (type == 2) {
        btnSub2->Visible = true;
        btnSub2->Text = "Subscribe";
        btnUnsub2->Visible = false;
        logServiceAction(userName, "Stocks Forecast", "Unsubscribe");
    }
    else {
        btnSub3->Visible = true;
        btnSub3->Text = "Subscribe";
        btnUnsub3->Visible = false;
        logServiceAction(userName, "Currency Forecast", "Unsubscribe");
    }

    MessageBox::Show("Unsubscription successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

    std::ofstream outputFile(filename, std::ios::trunc);
    if (!outputFile.is_open()) {
        throw gcnew System::IO::IOException("Unable to open the subscription file for writing!");
    }

    for (const auto& l : lines) {
        outputFile << l << std::endl;
    }
    outputFile.close();
}

std::string MainClient::ServiceForm::sendRequestThroughPipe(const std::string& request)
{
    const char* pipeName = "\\\\.\\pipe\\UserDetailsPipe";
    HANDLE hPipe = CreateFileA(
        pipeName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL
    );

    if (hPipe == INVALID_HANDLE_VALUE) {
        return "ERROR";
    }

    DWORD bytesWritten;
    WriteFile(hPipe, request.c_str(), request.size(), &bytesWritten, NULL);

    char buffer[512];
    DWORD bytesRead;
    ReadFile(hPipe, buffer, sizeof(buffer) - 1, &bytesRead, NULL);
    buffer[bytesRead] = '\0'; 

    CloseHandle(hPipe);
    return std::string(buffer);
}

bool MainClient::ServiceForm::IsUserSubscribed(const std::string& filename, String^ userName)
{
    IntPtr ptrToNativeString = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(userName);
    std::string nativeUserName = static_cast<const char*>(ptrToNativeString.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToNativeString);

    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        if (line == nativeUserName) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void MainClient::ServiceForm::logServiceAction(const std::string& userName, const std::string& serviceName, const std::string& action)
{
    std::ofstream logFile("servicesLogs.txt", std::ios::app);
    if (!logFile.is_open()) {
        throw gcnew System::IO::IOException("Unable to open the log file for writing!");
    }

    // Get current time
    std::time_t now = std::time(nullptr);
    char timeBuffer[100];
    std::strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    // Write to the log file
    logFile << "[" << timeBuffer << "] "
        << "User: " << userName << ", Service: " << serviceName << ", Action: " << action << std::endl;

    logFile.close();
}