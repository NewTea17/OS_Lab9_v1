#include <sstream>
#include <string>
#include <fstream>
#include <random>
#include <Windows.h>
#include <iostream>
#include <iomanip>

#include "CurrencyForm.h"

HANDLE hCurrencyFileMutex = CreateMutex(NULL, FALSE, L"Global\\CurrencyInfoMutex");
bool isMasterClient3 = false;

MainClient::CurrencyForm::CurrencyForm(void)
{
    InitializeComponent();

    std::ifstream masterFile("master_client3.txt");
    if (masterFile.is_open()) {
        std::string status;
        masterFile >> status;
        if (status == "true") {
            isMasterClient3 = false;
        }
        else {
            isMasterClient3 = true;
            std::ofstream outFile("master_client3.txt");
            outFile << "true";
            outFile.close();
        }
        masterFile.close();
    }
    LoadCurrencyRates();

    this->updateTimer = gcnew System::Windows::Forms::Timer();
    this->updateTimer->Interval = 5000;
    this->updateTimer->Tick += gcnew System::EventHandler(this, &MainClient::CurrencyForm::OnUpdateTimerTick);
    this->updateTimer->Start();

    this->currencyTimer = gcnew System::Windows::Forms::Timer();
    this->currencyTimer->Interval = 5000;
    this->currencyTimer->Tick += gcnew System::EventHandler(this, &MainClient::CurrencyForm::OnCurrencyTimerTick);
    this->currencyTimer->Start();
}

System::Void MainClient::CurrencyForm::OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e)
{
    UpdateCurrencyRates();
}

System::Void MainClient::CurrencyForm::OnCurrencyTimerTick(System::Object^ sender, System::EventArgs^ e)
{
    UpdateCurrencyRates();
}

System::Void MainClient::CurrencyForm::AddSubscriberToList(String^ userName)
{
    if (!String::IsNullOrWhiteSpace(userName)) {
        txtUserList->ReadOnly = false;
        txtUserList->AppendText(userName + Environment::NewLine);
        txtUserList->ReadOnly = true;
    }
}

System::Void MainClient::CurrencyForm::UpdateSubscribersList()
{
    txtUserList->Clear();

    std::ifstream file("usersOfCurrencyService.txt");
    if (file.is_open()) {
        txtUserList->ReadOnly = false;

        std::string line;
        while (std::getline(file, line)) {
            String^ userName = gcnew String(line.c_str());
            txtUserList->AppendText(userName + Environment::NewLine);
        }
        file.close();

        txtUserList->ReadOnly = true;
    }
    else {
        MessageBox::Show("Unable to load subscribers list. The file might be missing or inaccessible.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void MainClient::CurrencyForm::UpdateCurrencyRates()
{
    DWORD dwWaitResult = WaitForSingleObject(hCurrencyFileMutex, 5000);
    if (dwWaitResult == WAIT_OBJECT_0) {
        try {
            std::ifstream file("currency_rates.txt");
            if (file.is_open()) {
                std::stringstream updatedData;
                std::string line;

                if (isMasterClient3) {
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_real_distribution<> dist(-5.0, 5.0);

                    while (std::getline(file, line)) {
                        std::istringstream ss(line);
                        std::string currency;
                        double rate;
                        ss >> currency >> rate;
                        rate += dist(gen);
                        if (rate < 0) rate = 0;
                        updatedData << currency << " " << std::fixed << std::setprecision(2) << rate << "\n";
                    }
                    file.close();

                    std::ofstream outFile("currency_rates.txt", std::ios::trunc);
                    if (outFile.is_open()) {
                        outFile << updatedData.str();
                        outFile.close();
                    }
                    else {
                        MessageBox::Show("Failed to save updated currency data.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    }
                }
                else {
                    updatedData << file.rdbuf();
                    file.close();
                }
                LoadCurrencyRates();
            }
            else {
                MessageBox::Show("Failed to load currency rates.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (const std::exception& ex) {
            MessageBox::Show(gcnew String(ex.what()), "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (...) {
            MessageBox::Show("An unknown error occurred while updating currency rates.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        ReleaseMutex(hCurrencyFileMutex);
    }
    else {
        MessageBox::Show("Another client is updating the currency data. Please try again later.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

MainClient::CurrencyForm::~CurrencyForm()
{
    if (isMasterClient3) {
        std::ofstream masterFile("master_client3.txt");
        if (masterFile.is_open()) {
            masterFile << "false";
            masterFile.close();
        }
    }

    if (components) {
        delete components;
    }
}

void MainClient::CurrencyForm::InitializeComponent(void)
{
    this->currencyInfoLbl = (gcnew System::Windows::Forms::Label());
    this->txtCurrencyInfo = (gcnew System::Windows::Forms::TextBox());
    this->txtUserList = (gcnew System::Windows::Forms::TextBox());
    this->userListLbl = (gcnew System::Windows::Forms::Label());
    this->titleLbl = (gcnew System::Windows::Forms::Label());
    this->panel1 = (gcnew System::Windows::Forms::Panel());
    this->panel1->SuspendLayout();
    this->SuspendLayout();
    // 
    // currencyInfoLbl
    // 
    this->currencyInfoLbl->AutoSize = true;
    this->currencyInfoLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->currencyInfoLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
        static_cast<System::Int32>(static_cast<System::Byte>(156)));
    this->currencyInfoLbl->Location = System::Drawing::Point(22, 72);
    this->currencyInfoLbl->Name = L"currencyInfoLbl";
    this->currencyInfoLbl->Size = System::Drawing::Size(276, 25);
    this->currencyInfoLbl->TabIndex = 9;
    this->currencyInfoLbl->Text = L"Exchange rate information :";
    // 
    // txtCurrencyInfo
    // 
    this->txtCurrencyInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->txtCurrencyInfo->Location = System::Drawing::Point(12, 105);
    this->txtCurrencyInfo->Multiline = true;
    this->txtCurrencyInfo->Name = L"txtCurrencyInfo";
    this->txtCurrencyInfo->ReadOnly = true;
    this->txtCurrencyInfo->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
    this->txtCurrencyInfo->Size = System::Drawing::Size(612, 398);
    this->txtCurrencyInfo->TabIndex = 8;
    // 
    // txtUserList
    // 
    this->txtUserList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->txtUserList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->txtUserList->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
        static_cast<System::Int32>(static_cast<System::Byte>(156)));
    this->txtUserList->Location = System::Drawing::Point(642, 105);
    this->txtUserList->Multiline = true;
    this->txtUserList->Name = L"txtUserList";
    this->txtUserList->ReadOnly = true;
    this->txtUserList->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
    this->txtUserList->Size = System::Drawing::Size(259, 398);
    this->txtUserList->TabIndex = 7;
    // 
    // userListLbl
    // 
    this->userListLbl->AutoSize = true;
    this->userListLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->userListLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
        static_cast<System::Int32>(static_cast<System::Byte>(156)));
    this->userListLbl->Location = System::Drawing::Point(651, 72);
    this->userListLbl->Name = L"userListLbl";
    this->userListLbl->Size = System::Drawing::Size(183, 25);
    this->userListLbl->TabIndex = 6;
    this->userListLbl->Text = L"Current users list:";
    // 
    // titleLbl
    // 
    this->titleLbl->AutoSize = true;
    this->titleLbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->titleLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->titleLbl->Location = System::Drawing::Point(329, 9);
    this->titleLbl->Name = L"titleLbl";
    this->titleLbl->Size = System::Drawing::Size(295, 36);
    this->titleLbl->TabIndex = 5;
    this->titleLbl->Text = L"Daily exchange rate";
    // 
    // panel1
    // 
    this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
        static_cast<System::Int32>(static_cast<System::Byte>(227)));
    this->panel1->Controls->Add(this->currencyInfoLbl);
    this->panel1->Controls->Add(this->txtCurrencyInfo);
    this->panel1->Controls->Add(this->userListLbl);
    this->panel1->Controls->Add(this->titleLbl);
    this->panel1->Location = System::Drawing::Point(0, 0);
    this->panel1->Name = L"panel1";
    this->panel1->Size = System::Drawing::Size(927, 525);
    this->panel1->TabIndex = 10;
    this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CurrencyForm::panel1_Paint);
    // 
    // CurrencyForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(924, 521);
    this->Controls->Add(this->txtUserList);
    this->Controls->Add(this->panel1);
    this->Name = L"CurrencyForm";
    this->Text = L"CurrencyForm";
    this->Load += gcnew System::EventHandler(this, &CurrencyForm::CurrencyForm_Load);
    this->panel1->ResumeLayout(false);
    this->panel1->PerformLayout();
    this->ResumeLayout(false);
    this->PerformLayout();

}

void MainClient::CurrencyForm::LoadCurrencyRates()
{
    std::ifstream file("currency_rates.txt");
    if (file.is_open()) {
        txtCurrencyInfo->ReadOnly = false;
        txtCurrencyInfo->Clear();

        std::string line;
        while (std::getline(file, line)) {
            String^ currencyInfo = gcnew String(line.c_str());
            txtCurrencyInfo->AppendText(currencyInfo + Environment::NewLine);
        }
        file.close();

        txtCurrencyInfo->ReadOnly = true;
    }
    else {
        MessageBox::Show("Unable to load currency rates. The file might be missing or inaccessible.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

