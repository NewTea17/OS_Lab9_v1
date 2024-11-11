#include "StockForecastForm.h"
#include <fstream>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

MainClient::StockForecastForm::StockForecastForm(void)
{
	InitializeComponent();
}

MainClient::StockForecastForm::~StockForecastForm()
{
	if (components)
	{
		delete components;
	}
}

void MainClient::StockForecastForm::InitializeComponent(void)
{
	this->titleLbl = (gcnew System::Windows::Forms::Label());
	this->userListLbl = (gcnew System::Windows::Forms::Label());
	this->txtUserList = (gcnew System::Windows::Forms::TextBox());
	this->txtStocksInfo = (gcnew System::Windows::Forms::TextBox());
	this->stocksInfoLbl = (gcnew System::Windows::Forms::Label());
	this->startUpdatesBtn = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// titleLbl
	// 
	this->titleLbl->AutoSize = true;
	this->titleLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->titleLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
		static_cast<System::Int32>(static_cast<System::Byte>(158)));
	this->titleLbl->Location = System::Drawing::Point(12, 30);
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
	// startUpdatesBtn
	// 
	this->startUpdatesBtn->Font = (gcnew System::Drawing::Font(L"Elephant", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->startUpdatesBtn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
		static_cast<System::Int32>(static_cast<System::Byte>(156)));
	this->startUpdatesBtn->Location = System::Drawing::Point(722, 30);
	this->startUpdatesBtn->Name = L"startUpdatesBtn";
	this->startUpdatesBtn->Size = System::Drawing::Size(180, 42);
	this->startUpdatesBtn->TabIndex = 5;
	this->startUpdatesBtn->Text = L"Start updates";
	this->startUpdatesBtn->UseVisualStyleBackColor = true;
	this->startUpdatesBtn->Click += gcnew System::EventHandler(this, &StockForecastForm::startUpdatesBtn_Click);
	// 
	// StockForecastForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
		static_cast<System::Int32>(static_cast<System::Byte>(227)));
	this->ClientSize = System::Drawing::Size(925, 544);
	this->Controls->Add(this->startUpdatesBtn);
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

// Таймер та методи оновлення у клас StockForecastForm
void MainClient::StockForecastForm::StartStockUpdates() {
	System::Threading::Timer^ stockUpdateTimer = gcnew System::Threading::Timer(
		gcnew System::Threading::TimerCallback(this, &StockForecastForm::UpdateStocks),
		nullptr, 0, 15000);  // оновлення кожні 15 секунд
}

void MainClient::StockForecastForm::UpdateStocks(Object^ state)
{
	std::ifstream stockFile("stocks.txt");
	if (!stockFile.is_open()) {
		MessageBox::Show("Не вдалося відкрити файл з акціями.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	std::string line, updatedStocksInfo;

	std::stringstream newFileContent;

	while (std::getline(stockFile, line)) {
		std::istringstream ss(line);
		std::string company;
		double price;
		ss >> company >> price;

		double percentChange = ((rand() % 21) - 10) / 100.0; // зміна на +-10%
		double newPrice = price * (1 + percentChange);
		std::string status = percentChange >= 0 ? "зросла" : "впала";

		updatedStocksInfo += company + " - $" + std::to_string(newPrice) + " (" + status + ")\n";
		newFileContent << company << " " << newPrice << std::endl;  // для запису у файл
	}

	stockFile.close();

	// Записуємо оновлені дані у файл
	std::ofstream outFile("stocks.txt", std::ios::trunc);
	outFile << newFileContent.str();
	outFile.close();

	// Оновлюємо текстове поле
	txtStocksInfo->Text = gcnew String(updatedStocksInfo.c_str());
}


void MainClient::StockForecastForm::UpdateUserList()
{
	std::ifstream userFile("users.txt");
	if (!userFile.is_open()) {
		MessageBox::Show("Не вдалося відкрити файл користувачів.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	std::string line, userList;
	while (std::getline(userFile, line)) {
		userList += line + "\n"; // Збираємо всі рядки у std::string
	}

	userFile.close();

	// Перетворюємо весь накопичений std::string в System::String
	txtUserList->Text = gcnew String(userList.c_str()); // Оновлюємо текстове поле
}

System::Void MainClient::StockForecastForm::startUpdatesBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	UpdateStocks(nullptr); // Оновлюємо акції
	UpdateUserList();      // Оновлюємо список користувачів
}