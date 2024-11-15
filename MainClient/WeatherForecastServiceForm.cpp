#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <random>
#include <Windows.h> 

#include "ServiceForm.h"
#include "WeatherForecastServiceForm.h"

HANDLE hFileMutex = CreateMutex(NULL, FALSE, L"Global\\WeatherForecastMutex");
bool isMasterClient = false;

MainClient::WeatherForecastServiceForm::WeatherForecastServiceForm(void)
{
	Init();
}

MainClient::WeatherForecastServiceForm::WeatherForecastServiceForm(String^ userName)
{
	Init();
	UsernameLbl->Text = userName;
}

System::Void MainClient::WeatherForecastServiceForm::OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e)
{
	UpdateSubscribersList();
}

System::Void MainClient::WeatherForecastServiceForm::OnWeatherTimerTick(System::Object^ sender, System::EventArgs^ e)
{
	UpdateWeatherTemperature();
}

System::Void MainClient::WeatherForecastServiceForm::btnGoBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isSubscribed = CheckIfUserIsSubscribed(UsernameLbl->Text);  

	if (isSubscribed) {
		std::ofstream file("master_client.txt", std::ios::trunc);
		if (file.is_open()) {
			file << "false" << std::endl;
			file.close();
		}
	}

	this->Hide();

	ServiceForm^ form = gcnew ServiceForm(UsernameLbl->Text);

	if (isSubscribed) {
		form->btnSub1->Text = "Watch";
		form->btnSub1->Visible = true;
		form->btnUnsub1->Visible = true;
	}
	else {
		form->btnSub1->Visible = true;
		form->btnUnsub1->Visible = false;
	}

	form->ShowDialog();

	this->Close();
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
	else
	{
		MessageBox::Show("Unable to load subscribers list. The file might be missing or inaccessible.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void MainClient::WeatherForecastServiceForm::UpdateWeatherTemperature()
{
	DWORD dwWaitResult = WaitForSingleObject(hFileMutex, 5000);

	if (dwWaitResult == WAIT_OBJECT_0) {
		try {
			std::ifstream file("weather_forecast.txt");
			if (file.is_open()) {
				std::stringstream updatedData;
				std::string line;

				if (isMasterClient) {
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_int_distribution<> dist(-3, 3);

					while (std::getline(file, line)) {
						std::istringstream ss(line);
						std::string city, monday, tuesday, wednesday, thursday, friday, saturday, sunday;

						ss >> city >> monday >> tuesday >> wednesday >> thursday >> friday >> saturday >> sunday;

						monday = std::to_string(std::stoi(monday) + dist(gen));
						tuesday = std::to_string(std::stoi(tuesday) + dist(gen));
						wednesday = std::to_string(std::stoi(wednesday) + dist(gen));
						thursday = std::to_string(std::stoi(thursday) + dist(gen));
						friday = std::to_string(std::stoi(friday) + dist(gen));
						saturday = std::to_string(std::stoi(saturday) + dist(gen));
						sunday = std::to_string(std::stoi(sunday) + dist(gen));

						updatedData << city << " "
							<< monday << " "
							<< tuesday << " "
							<< wednesday << " "
							<< thursday << " "
							<< friday << " "
							<< saturday << " "
							<< sunday << "\n";
					}
					file.close();

					std::ofstream outFile("weather_forecast.txt", std::ios::trunc);
					if (outFile.is_open()) {
						outFile << updatedData.str();
						outFile.close();
					}
					else {
						MessageBox::Show("Failed to save updated weather forecast data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else {
					updatedData << file.rdbuf(); 
					file.close();
				}

				LoadWeatherForecast();
			}
			else {
				MessageBox::Show("Failed to load weather forecast data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (...) {
			MessageBox::Show("An error occurred during weather forecast update.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		ReleaseMutex(hFileMutex);
	}
	else {
		MessageBox::Show("Another client is updating the weather forecast. Please try again later.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

MainClient::WeatherForecastServiceForm::~WeatherForecastServiceForm()
{
	if (isMasterClient) {
		std::ofstream masterFile("master_client.txt");
		if (masterFile.is_open()) {
			masterFile << "false";
			masterFile.close();
		}
	}

	if (components) {
		delete components;
	}
}

void MainClient::WeatherForecastServiceForm::Init()
{
	InitializeComponent();

	std::ifstream masterFile("master_client.txt");
	if (masterFile.is_open()) {
		std::string status;
		masterFile >> status;
		if (status == "true") {
			isMasterClient = false;
		}
		else {
			isMasterClient = true;
			std::ofstream outFile("master_client.txt");
			outFile << "true";
			outFile.close();
		}
		masterFile.close();
	}

	LoadWeatherForecast();

	this->updateTimer = gcnew System::Windows::Forms::Timer();
	this->updateTimer->Interval = 5000;  // 5000 мілісекунд = 5 секунд
	this->updateTimer->Tick += gcnew System::EventHandler(this, &MainClient::WeatherForecastServiceForm::OnUpdateTimerTick);
	this->updateTimer->Start();

	this->weatherTimer = gcnew System::Windows::Forms::Timer();
	this->weatherTimer->Interval = 5000;  // 36000000 мілісекунд = 1 год
	this->weatherTimer->Tick += gcnew System::EventHandler(this, &MainClient::WeatherForecastServiceForm::OnWeatherTimerTick);
	this->weatherTimer->Start();
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
	this->weatherTimer = (gcnew System::Windows::Forms::Timer(this->components));
	this->btnGoBack = (gcnew System::Windows::Forms::Button());
	this->UsernameLbl = (gcnew System::Windows::Forms::Label());
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
	this->weatherInformationBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
		static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
	this->weatherInformationBox->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->weatherInformationBox->ForeColor = System::Drawing::SystemColors::WindowText;
	this->weatherInformationBox->Location = System::Drawing::Point(29, 120);
	this->weatherInformationBox->Multiline = true;
	this->weatherInformationBox->Name = L"weatherInformationBox";
	this->weatherInformationBox->ReadOnly = true;
	this->weatherInformationBox->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
	this->weatherInformationBox->Size = System::Drawing::Size(556, 382);
	this->weatherInformationBox->TabIndex = 1;
	this->weatherInformationBox->WordWrap = false;
	// 
	// weatherInfoLbl
	// 
	this->weatherInfoLbl->AutoSize = true;
	this->weatherInfoLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->weatherInfoLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
		static_cast<System::Int32>(static_cast<System::Byte>(156)));
	this->weatherInfoLbl->Location = System::Drawing::Point(24, 91);
	this->weatherInfoLbl->Name = L"weatherInfoLbl";
	this->weatherInfoLbl->Size = System::Drawing::Size(560, 26);
	this->weatherInfoLbl->TabIndex = 2;
	this->weatherInfoLbl->Text = L"Weather information (city name/m, tu, w, th, f, sat, sun)";
	// 
	// subscribersListBox
	// 
	this->subscribersListBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)),
		static_cast<System::Int32>(static_cast<System::Byte>(227)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
	this->subscribersListBox->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->subscribersListBox->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)),
		static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(156)));
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
	this->subscribersListLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)),
		static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(156)));
	this->subscribersListLbl->Location = System::Drawing::Point(621, 91);
	this->subscribersListLbl->Name = L"subscribersListLbl";
	this->subscribersListLbl->Size = System::Drawing::Size(195, 26);
	this->subscribersListLbl->TabIndex = 4;
	this->subscribersListLbl->Text = L"Current users list:";
	// 
	// btnGoBack
	// 
	this->btnGoBack->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold));
	this->btnGoBack->ForeColor = System::Drawing::SystemColors::ActiveCaption;
	this->btnGoBack->Location = System::Drawing::Point(12, 12);
	this->btnGoBack->Name = L"btnGoBack";
	this->btnGoBack->Size = System::Drawing::Size(123, 40);
	this->btnGoBack->TabIndex = 5;
	this->btnGoBack->Text = L"Go back";
	this->btnGoBack->UseVisualStyleBackColor = true;
	this->btnGoBack->Click += gcnew System::EventHandler(this, &WeatherForecastServiceForm::btnGoBack_Click);
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
	this->UsernameLbl->Location = System::Drawing::Point(776, 19);
	this->UsernameLbl->Name = L"UsernameLbl";
	this->UsernameLbl->Size = System::Drawing::Size(119, 26);
	this->UsernameLbl->TabIndex = 16;
	this->UsernameLbl->Text = L"username";
	this->UsernameLbl->TextAlign = System::Drawing::ContentAlignment::TopRight;
	// 
	// WeatherForecastServiceForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
		static_cast<System::Int32>(static_cast<System::Byte>(227)));
	this->ClientSize = System::Drawing::Size(925, 544);
	this->Controls->Add(this->UsernameLbl);
	this->Controls->Add(this->btnGoBack);
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
	weatherInformationBox->Clear();

	std::ifstream file("weather_forecast.txt");
	if (file.is_open()) {
		std::string line;
		bool isFirstLine = true;

		while (std::getline(file, line)) {
			std::istringstream ss(line);
			std::string city;
			std::string monday, tuesday, wednesday, thursday, friday, saturday, sunday;

			ss >> city >> monday >> tuesday >> wednesday >> thursday
				>> friday >> saturday >> sunday;

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

			if (isFirstLine) {
				weatherInformationBox->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold)); // Моноширинний шрифт
				isFirstLine = false;
			} else {
				weatherInformationBox->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular)); // Моноширинний шрифт
			}

			weatherInformationBox->AppendText(formattedLine + Environment::NewLine);
		}
		file.close();
	} else {
		MessageBox::Show("Failed to load weather forecast data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

bool MainClient::WeatherForecastServiceForm::CheckIfUserIsSubscribed(String^ userName)
{
	std::ifstream file("usersOfWeatherService.txt");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			String^ subscriber = gcnew String(line.c_str());
			if (subscriber == userName) {
				file.close();
				return true;
			}
		}
		file.close();
	}
	return false;
}

