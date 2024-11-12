#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "WeatherForecastServiceForm.h"

MainClient::WeatherForecastServiceForm::WeatherForecastServiceForm(void)
{
	InitializeComponent();

    LoadWeatherForecast();

    this->updateTimer = gcnew System::Windows::Forms::Timer();
    this->updateTimer->Interval = 5000;  // 5000 мілісекунд = 5 секунд
    this->updateTimer->Tick += gcnew System::EventHandler(this, &MainClient::WeatherForecastServiceForm::OnUpdateTimerTick);
    this->updateTimer->Start();
}

System::Void MainClient::WeatherForecastServiceForm::OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e)
{
    UpdateSubscribersList();
}

System::Void MainClient::WeatherForecastServiceForm::AddSubscriberToList(String^ userName)
{
    if (!String::IsNullOrWhiteSpace(userName)) {
        subscribersListBox->ReadOnly = false;

        subscribersListBox->AppendText(userName + Environment::NewLine);

        subscribersListBox->ReadOnly = true;
    }
}

System::Void MainClient::WeatherForecastServiceForm::UpdateSubscribersList()
{
    subscribersListBox->Clear();

    std::ifstream file("usersOfWeatherService.txt");
    if (file.is_open())
    {
        subscribersListBox->ReadOnly = false;

        std::string line;
        while (std::getline(file, line))
        {
            String^ userName = gcnew String(line.c_str()); 
            subscribersListBox->AppendText(userName + Environment::NewLine); 
        }
        file.close();

        subscribersListBox->ReadOnly = true;
    }
}

MainClient::WeatherForecastServiceForm::~WeatherForecastServiceForm()
{
	if (components) {
		delete components;
	}
}

void MainClient::WeatherForecastServiceForm::InitializeComponent(void)
{
    this->components = (gcnew System::ComponentModel::Container());
    this->weatherForecastLbl = (gcnew System::Windows::Forms::Label());
    this->weatherInformationBox = (gcnew System::Windows::Forms::TextBox());
    this->weatherInfoLbl = (gcnew System::Windows::Forms::Label());
    this->subscribersListBox = (gcnew System::Windows::Forms::TextBox());
    this->subscribersListLbl = (gcnew System::Windows::Forms::Label());
    this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
    this->SuspendLayout();
    // 
    // weatherForecastLbl
    // 
    this->weatherForecastLbl->AutoSize = true;
    this->weatherForecastLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weatherForecastLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)),
        static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->weatherForecastLbl->Location = System::Drawing::Point(241, 31);
    this->weatherForecastLbl->Name = L"weatherForecastLbl";
    this->weatherForecastLbl->Size = System::Drawing::Size(415, 42);
    this->weatherForecastLbl->TabIndex = 0;
    this->weatherForecastLbl->Text = L"Hourly weather forecast";
    // 
    // weatherInformationBox
    // 
    this->weatherInformationBox->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weatherInformationBox->Location = System::Drawing::Point(59, 120);
    this->weatherInformationBox->Multiline = true;
    this->weatherInformationBox->Name = L"weatherInformationBox";
    this->weatherInformationBox->ReadOnly = true;
    this->weatherInformationBox->WordWrap = false;
    this->weatherInformationBox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
    this->weatherInformationBox->Size = System::Drawing::Size(556, 382);
    this->weatherInformationBox->TabIndex = 1;
    // 
    // weatherInfoLbl
    // 
    this->weatherInfoLbl->AutoSize = true;
    this->weatherInfoLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->weatherInfoLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
        static_cast<System::Int32>(static_cast<System::Byte>(192)));
    this->weatherInfoLbl->Location = System::Drawing::Point(56, 89);
    this->weatherInfoLbl->Name = L"weatherInfoLbl";
    this->weatherInfoLbl->Size = System::Drawing::Size(559, 26);
    this->weatherInfoLbl->TabIndex = 2;
    this->weatherInfoLbl->Text = L"Weather information (сity name/m, tu, w, th, f, sat, sun)";
    // 
    // subscribersListBox
    // 
    this->subscribersListBox->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->subscribersListBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
    this->subscribersListBox->Location = System::Drawing::Point(626, 120);
    this->subscribersListBox->Multiline = true;
    this->subscribersListBox->Name = L"subscribersListBox";
    this->subscribersListBox->ReadOnly = true;
    this->subscribersListBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
    this->subscribersListBox->Size = System::Drawing::Size(269, 382);
    this->subscribersListBox->TabIndex = 3;
    // 
    // subscribersListLbl
    // 
    this->subscribersListLbl->AutoSize = true;
    this->subscribersListLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->subscribersListLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
        static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
    this->subscribersListLbl->Location = System::Drawing::Point(621, 91);
    this->subscribersListLbl->Name = L"subscribersListLbl";
    this->subscribersListLbl->Size = System::Drawing::Size(195, 26);
    this->subscribersListLbl->TabIndex = 4;
    this->subscribersListLbl->Text = L"Current users list:";
    // 
    // WeatherForecastServiceForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
        static_cast<System::Int32>(static_cast<System::Byte>(227)));
    this->ClientSize = System::Drawing::Size(925, 544);
    this->Controls->Add(this->subscribersListLbl);
    this->Controls->Add(this->subscribersListBox);
    this->Controls->Add(this->weatherInfoLbl);
    this->Controls->Add(this->weatherInformationBox);
    this->Controls->Add(this->weatherForecastLbl);
    this->MaximumSize = System::Drawing::Size(943, 591);
    this->MinimumSize = System::Drawing::Size(943, 591);
    this->Name = L"WeatherForecastServiceForm";
    this->Text = L"WeatherForecastServiceForm";
    this->ResumeLayout(false);
    this->PerformLayout();

}

void MainClient::WeatherForecastServiceForm::LoadWeatherForecast()
{
    std::ifstream file("weather_forecast.txt");
    if (file.is_open())
    {
        std::string line;
        bool isFirstLine = true;

        while (std::getline(file, line))
        {
            std::istringstream ss(line);
            std::string city;
            std::string monday, tuesday, wednesday, thursday, friday, saturday, sunday;

            ss >> city >> monday >> tuesday >> wednesday >> thursday >> friday >> saturday >> sunday;

            String^ cityStr = gcnew String(city.c_str());
            String^ mondayStr = gcnew String(monday.c_str());
            String^ tuesdayStr = gcnew String(tuesday.c_str());
            String^ wednesdayStr = gcnew String(wednesday.c_str());
            String^ thursdayStr = gcnew String(thursday.c_str());
            String^ fridayStr = gcnew String(friday.c_str());
            String^ saturdayStr = gcnew String(saturday.c_str());
            String^ sundayStr = gcnew String(sunday.c_str());

            String^ formattedLine = cityStr->PadRight(15) + " "  
                + mondayStr->PadRight(15)  
                + tuesdayStr->PadRight(15)
                + wednesdayStr->PadRight(15)
                + thursdayStr->PadRight(15)
                + fridayStr->PadRight(15)
                + saturdayStr->PadRight(15)
                + sundayStr->PadRight(15);

            if (isFirstLine)
            {
                weatherInformationBox->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold)); // Моноширинний шрифт
                isFirstLine = false;  
            }
            else
            {
                weatherInformationBox->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular)); // Моноширинний шрифт
            }

            weatherInformationBox->AppendText(formattedLine + Environment::NewLine);
        }
        file.close();
    }
    else
    {
        MessageBox::Show("Failed to load weather forecast data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}




