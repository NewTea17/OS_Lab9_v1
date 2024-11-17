#include <sstream>
#include <string>
#include <fstream>
#include <random>
#include <Windows.h> 
#include <iostream>
#include <iomanip>

#include "ServiceForm.h"
#include "StockForecastForm1.h"

HANDLE hStocksFileMutex = CreateMutex(NULL, FALSE, L"Global\\StocksForecastMutex");
bool isMasterClient2 = false;

MainClient::StockForecastForm::StockForecastForm(void)
{
	Init();
}

MainClient::StockForecastForm::StockForecastForm(String^ userName)
{
	Init();
	UsernameLbl->Text = userName;
}

System::Void MainClient::StockForecastForm::OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e)
{
	UpdateSubscribersList();
}

System::Void MainClient::StockForecastForm::OnStocksTimerTick(System::Object^ sender, System::EventArgs^ e)
{
	UpdateStocksPrices();
}

System::Void MainClient::StockForecastForm::btnGoBack_Click(System::Object^ sender, System::EventArgs^ e)
{
	bool isSubscribed = CheckIfUserIsSubscribed(UsernameLbl->Text);

	if (isSubscribed) {
		std::ofstream file("master_client2.txt", std::ios::trunc);
		if (file.is_open()) {
			file << "false" << std::endl;
			file.close();
		}
	}

	this->Hide();

	ServiceForm^ form = gcnew ServiceForm(UsernameLbl->Text);

	if (isSubscribed) {
		form->btnSub2->Text = "Watch";
		form->btnSub2->Visible = true;
		form->btnUnsub2->Visible = true;
	}
	else {
		form->btnSub2->Visible = true;
		form->btnUnsub2->Visible = false;
	}

	form->ShowDialog();

	this->Close();
}

System::Void MainClient::StockForecastForm::AddSubscriberToList(String^ userName)
{
	if (!String::IsNullOrWhiteSpace(userName)) {
		txtUserList->ReadOnly = false;

		txtUserList->AppendText(userName + Environment::NewLine);

		txtUserList->ReadOnly = true;
	}
}

System::Void MainClient::StockForecastForm::UpdateSubscribersList()
{
	txtUserList->Clear();

	std::ifstream file("usersOfStocksService.txt");
	if (file.is_open())
	{
		txtUserList->ReadOnly = false;

		std::string line;
		while (std::getline(file, line))
		{
			String^ userName = gcnew String(line.c_str());
			txtUserList->AppendText(userName + Environment::NewLine);
		}
		file.close();

		txtUserList->ReadOnly = true;
	}
	else
	{
		MessageBox::Show("Unable to load subscribers list. The file might be missing or inaccessible.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void MainClient::StockForecastForm::UpdateStocksPrices()
{
	DWORD dwWaitResult = WaitForSingleObject(hStocksFileMutex, 5000);

	if (dwWaitResult == WAIT_OBJECT_0) {
		try {
			std::ifstream file("stocks_forecast.txt");
			if (file.is_open()) {
				std::stringstream updatedData;
				std::string line;

				if (isMasterClient2) {
					std::random_device rd;
					std::mt19937 gen(rd());
					std::uniform_real_distribution<> dist(-5.0, 5.0); // Рандомні зміни для ціни акцій

					while (std::getline(file, line)) {
						std::istringstream ss(line);
						std::string company;
						double price;

						ss >> company >> price;

						// Додаємо випадкове значення до поточної ціни
						price += dist(gen);
						updatedData << company << " " << std::fixed << std::setprecision(2) << price << "\n";
					}
					file.close();

					// Записуємо оновлені дані назад у файл
					std::ofstream outFile("stocks_forecast.txt", std::ios::trunc);
					if (outFile.is_open()) {
						outFile << updatedData.str();
						outFile.close();
					}
					else {
						MessageBox::Show("Failed to save updated stocks data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				else {
					// Читаємо поточний вміст файлу для інших клієнтів
					updatedData << file.rdbuf();
					file.close();
				}

				LoadStocksForecast(); // Метод для завантаження та відображення оновлених даних
			}
			else {
				MessageBox::Show("Failed to load stocks data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (...) {
			MessageBox::Show("An error occurred during stocks update.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		ReleaseMutex(hStocksFileMutex);
	}
	else {
		MessageBox::Show("Another client is updating the stocks data. Please try again later.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

MainClient::StockForecastForm::~StockForecastForm()
{
	if (isMasterClient2) {
		std::ofstream masterFile("master_client2.txt");
		if (masterFile.is_open()) {
			masterFile << "false";
			masterFile.close();
		}
	}

	if (components) {
		delete components;
	}
}

void MainClient::StockForecastForm::InitializeComponent(void)
{
	this->components = (gcnew System::ComponentModel::Container());
	System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StockForecastForm::typeid));
	this->titleLbl = (gcnew System::Windows::Forms::Label());
	this->userListLbl = (gcnew System::Windows::Forms::Label());
	this->txtUserList = (gcnew System::Windows::Forms::TextBox());
	this->txtStocksInfo = (gcnew System::Windows::Forms::TextBox());
	this->stocksInfoLbl = (gcnew System::Windows::Forms::Label());
	this->updateTimer = (gcnew System::Windows::Forms::Timer(this->components));
	this->stocksTimer = (gcnew System::Windows::Forms::Timer(this->components));
	this->btnGoBack = (gcnew System::Windows::Forms::Button());
	this->UsernameLbl = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// titleLbl
	// 
	this->titleLbl->AutoSize = true;
	this->titleLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->titleLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
		static_cast<System::Int32>(static_cast<System::Byte>(158)));
	this->titleLbl->Location = System::Drawing::Point(159, 33);
	this->titleLbl->Name = L"titleLbl";
	this->titleLbl->Size = System::Drawing::Size(643, 38);
	this->titleLbl->TabIndex = 0;
	this->titleLbl->Text = L"Minute-by-minute stock forecast service";
	// 
	// userListLbl
	// 
	this->userListLbl->AutoSize = true;
	this->userListLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->userListLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
		static_cast<System::Int32>(static_cast<System::Byte>(156)));
	this->userListLbl->Location = System::Drawing::Point(649, 87);
	this->userListLbl->Name = L"userListLbl";
	this->userListLbl->Size = System::Drawing::Size(214, 26);
	this->userListLbl->TabIndex = 1;
	this->userListLbl->Text = L"Current users list:";
	// 
	// txtUserList
	// 
	this->txtUserList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	this->txtUserList->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->txtUserList->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
		static_cast<System::Int32>(static_cast<System::Byte>(156)));
	this->txtUserList->Location = System::Drawing::Point(654, 120);
	this->txtUserList->Multiline = true;
	this->txtUserList->Name = L"txtUserList";
	this->txtUserList->ReadOnly = true;
	this->txtUserList->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
	this->txtUserList->Size = System::Drawing::Size(259, 398);
	this->txtUserList->TabIndex = 2;
	// 
	// txtStocksInfo
	// 
	this->txtStocksInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	this->txtStocksInfo->Location = System::Drawing::Point(17, 120);
	this->txtStocksInfo->Multiline = true;
	this->txtStocksInfo->Name = L"txtStocksInfo";
	this->txtStocksInfo->ReadOnly = true;
	this->txtStocksInfo->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
	this->txtStocksInfo->Size = System::Drawing::Size(612, 398);
	this->txtStocksInfo->TabIndex = 3;
	// 
	// stocksInfoLbl
	// 
	this->stocksInfoLbl->AutoSize = true;
	this->stocksInfoLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->stocksInfoLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
		static_cast<System::Int32>(static_cast<System::Byte>(156)));
	this->stocksInfoLbl->Location = System::Drawing::Point(12, 87);
	this->stocksInfoLbl->Name = L"stocksInfoLbl";
	this->stocksInfoLbl->Size = System::Drawing::Size(552, 26);
	this->stocksInfoLbl->TabIndex = 4;
	this->stocksInfoLbl->Text = L"Stocks information (company name/price/status):";
	// 
	// btnGoBack
	// 
	this->btnGoBack->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold));
	this->btnGoBack->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(85)),
		static_cast<System::Int32>(static_cast<System::Byte>(179)));
	this->btnGoBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGoBack.Image")));
	this->btnGoBack->Location = System::Drawing::Point(12, 12);
	this->btnGoBack->Name = L"btnGoBack";
	this->btnGoBack->Size = System::Drawing::Size(123, 40);
	this->btnGoBack->TabIndex = 6;
	this->btnGoBack->Text = L"Go back";
	this->btnGoBack->UseVisualStyleBackColor = true;
	this->btnGoBack->Click += gcnew System::EventHandler(this, &StockForecastForm::btnGoBack_Click);
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
	this->UsernameLbl->Location = System::Drawing::Point(794, 7);
	this->UsernameLbl->Name = L"UsernameLbl";
	this->UsernameLbl->Size = System::Drawing::Size(119, 26);
	this->UsernameLbl->TabIndex = 17;
	this->UsernameLbl->Text = L"username";
	this->UsernameLbl->TextAlign = System::Drawing::ContentAlignment::TopRight;
	// 
	// StockForecastForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
		static_cast<System::Int32>(static_cast<System::Byte>(227)));
	this->ClientSize = System::Drawing::Size(925, 544);
	this->Controls->Add(this->UsernameLbl);
	this->Controls->Add(this->btnGoBack);
	this->Controls->Add(this->stocksInfoLbl);
	this->Controls->Add(this->txtStocksInfo);
	this->Controls->Add(this->txtUserList);
	this->Controls->Add(this->userListLbl);
	this->Controls->Add(this->titleLbl);
	this->MaximumSize = System::Drawing::Size(943, 591);
	this->MinimumSize = System::Drawing::Size(943, 591);
	this->Name = L"StockForecastForm";
	this->Text = L"Stock Forecast Service";
	this->ResumeLayout(false);
	this->PerformLayout();

}

void MainClient::StockForecastForm::LoadStocksForecast()
{
	txtStocksInfo->Clear();

	std::ifstream file("stocks_forecast.txt");
	if (file.is_open()) {
		std::string line;
		bool isFirstLine = true;

		while (std::getline(file, line)) {
			std::istringstream ss(line);
			std::string company;
			std::string price;

			ss >> company >> price;

			String^ companyStr = gcnew String(company.c_str());
			String^ priceStr = gcnew String(price.c_str());

			String^ formattedLine = companyStr->PadRight(20) + priceStr->PadRight(10);

			if (isFirstLine) {
				txtStocksInfo->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold)); // Моноширинний шрифт для першого рядка
				isFirstLine = false;
			}
			else {
				txtStocksInfo->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular)); // Моноширинний шрифт для інших рядків
			}

			txtStocksInfo->AppendText(formattedLine + Environment::NewLine);
		}
		file.close();
	}
	else {
		MessageBox::Show("Failed to load stocks forecast.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void MainClient::StockForecastForm::Init()
{
	InitializeComponent();

	std::ifstream masterFile("master_client2.txt");
	if (masterFile.is_open()) {
		std::string status;
		masterFile >> status;
		if (status == "true") {
			isMasterClient2 = false;
		}
		else {
			isMasterClient2 = true;
			std::ofstream outFile("master_client2.txt");
			outFile << "true";
			outFile.close();
		}
		masterFile.close();
	}

	LoadStocksForecast();

	this->updateTimer = gcnew System::Windows::Forms::Timer();
	this->updateTimer->Interval = 5000;  // 5000 мілісекунд = 5 секунд
	this->updateTimer->Tick += gcnew System::EventHandler(this, &MainClient::StockForecastForm::OnUpdateTimerTick);
	this->updateTimer->Start();

	this->stocksTimer = gcnew System::Windows::Forms::Timer();
	this->stocksTimer->Interval = 5000;  // 36000000 мілісекунд = 1 год
	this->stocksTimer->Tick += gcnew System::EventHandler(this, &MainClient::StockForecastForm::OnStocksTimerTick);
	this->stocksTimer->Start();
}

bool MainClient::StockForecastForm::CheckIfUserIsSubscribed(String^ userName)
{
	std::ifstream file("usersOfStocksService.txt");
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
