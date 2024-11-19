#include <sstream>
#include <string>
#include <fstream>
#include <random>
#include <Windows.h>
#include <iostream>
#include <iomanip>

#include "ServiceForm.h"
#include "CurrencyForm.h"

HANDLE hCurrencyFileMutex = CreateMutex(NULL, FALSE, L"Global\\CurrencyInfoMutex");
bool isMasterClient3 = false;

MainClient::CurrencyForm::CurrencyForm(void)
{
    Init();
}

MainClient::CurrencyForm::CurrencyForm(String^ userName)
{
    Init();
    UsernameLbl->Text = userName;
}

System::Void MainClient::CurrencyForm::OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e)
{
    UpdateCurrencyRates();
}

System::Void MainClient::CurrencyForm::OnCurrencyTimerTick(System::Object^ sender, System::EventArgs^ e)
{
    UpdateCurrencyRates();
}

System::Void MainClient::CurrencyForm::CurrencyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void MainClient::CurrencyForm::panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
    return System::Void();
}

bool MainClient::CurrencyForm::CheckIfUserIsSubscribed(String^ userName)
{
    std::ifstream file("usersOfCurrencyService.txt");
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

System::Void MainClient::CurrencyForm::btnGoBack_Click(System::Object^ sender, System::EventArgs^ e)
{
    bool isSubscribed = CheckIfUserIsSubscribed(UsernameLbl->Text);

    if (isSubscribed) {
        std::ofstream file("master_client3.txt", std::ios::trunc);
        if (file.is_open()) {
            file << "false" << std::endl;
            file.close();
        }
    }

    this->Hide();

    ServiceForm^ form = gcnew ServiceForm(UsernameLbl->Text);

    if (isSubscribed) {
        form->btnSub3->Text = "Watch";
        form->btnSub3->Visible = true;
        form->btnUnsub3->Visible = true;
    }
    else {
        form->btnSub3->Visible = true;
        form->btnUnsub3->Visible = false;
    }

    form->ShowDialog();

    this->Close();
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
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CurrencyForm::typeid));
    this->currencyInfoLbl = (gcnew System::Windows::Forms::Label());
    this->txtCurrencyInfo = (gcnew System::Windows::Forms::TextBox());
    this->txtUserList = (gcnew System::Windows::Forms::TextBox());
    this->userListLbl = (gcnew System::Windows::Forms::Label());
    this->titleLbl = (gcnew System::Windows::Forms::Label());
    this->panel1 = (gcnew System::Windows::Forms::Panel());
    this->UsernameLbl = (gcnew System::Windows::Forms::Label());
    this->btnGoBack = (gcnew System::Windows::Forms::Button());
    this->panel1->SuspendLayout();
    this->SuspendLayout();
    // 
    // currencyInfoLbl
    // 
    this->currencyInfoLbl->AutoSize = true;
    this->currencyInfoLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold));
    this->currencyInfoLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
        static_cast<System::Int32>(static_cast<System::Byte>(156)));
    this->currencyInfoLbl->Location = System::Drawing::Point(12, 88);
    this->currencyInfoLbl->Name = L"currencyInfoLbl";
    this->currencyInfoLbl->Size = System::Drawing::Size(318, 26);
    this->currencyInfoLbl->TabIndex = 9;
    this->currencyInfoLbl->Text = L"Exchange rate information :";
    // 
    // txtCurrencyInfo
    // 
    this->txtCurrencyInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->txtCurrencyInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->txtCurrencyInfo->Location = System::Drawing::Point(12, 121);
    this->txtCurrencyInfo->Multiline = true;
    this->txtCurrencyInfo->Name = L"txtCurrencyInfo";
    this->txtCurrencyInfo->Size = System::Drawing::Size(637, 381);
    this->txtCurrencyInfo->TabIndex = 18;
    // 
    // txtUserList
    // 
    this->txtUserList->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(227)),
        static_cast<System::Int32>(static_cast<System::Byte>(255)));
    this->txtUserList->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold));
    this->txtUserList->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
        static_cast<System::Int32>(static_cast<System::Byte>(156)));
    this->txtUserList->Location = System::Drawing::Point(655, 121);
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
    this->userListLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Bold));
    this->userListLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(152)), static_cast<System::Int32>(static_cast<System::Byte>(48)),
        static_cast<System::Int32>(static_cast<System::Byte>(156)));
    this->userListLbl->Location = System::Drawing::Point(650, 88);
    this->userListLbl->Name = L"userListLbl";
    this->userListLbl->Size = System::Drawing::Size(214, 26);
    this->userListLbl->TabIndex = 6;
    this->userListLbl->Text = L"Current users list:";
    // 
    // titleLbl
    // 
    this->titleLbl->AutoSize = true;
    this->titleLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 18, System::Drawing::FontStyle::Bold));
    this->titleLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->titleLbl->Location = System::Drawing::Point(329, 45);
    this->titleLbl->Name = L"titleLbl";
    this->titleLbl->Size = System::Drawing::Size(326, 38);
    this->titleLbl->TabIndex = 5;
    this->titleLbl->Text = L"Daily exchange rate";
    // 
    // panel1
    // 
    this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
        static_cast<System::Int32>(static_cast<System::Byte>(227)));
    this->panel1->Controls->Add(this->txtUserList);
    this->panel1->Controls->Add(this->UsernameLbl);
    this->panel1->Controls->Add(this->btnGoBack);
    this->panel1->Controls->Add(this->currencyInfoLbl);
    this->panel1->Controls->Add(this->txtCurrencyInfo);
    this->panel1->Controls->Add(this->userListLbl);
    this->panel1->Controls->Add(this->titleLbl);
    this->panel1->Location = System::Drawing::Point(0, 0);
    this->panel1->MaximumSize = System::Drawing::Size(943, 591);
    this->panel1->MinimumSize = System::Drawing::Size(943, 591);
    this->panel1->Name = L"panel1";
    this->panel1->Size = System::Drawing::Size(943, 591);
    this->panel1->TabIndex = 10;
    this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CurrencyForm::panel1_Paint);
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
    this->UsernameLbl->Location = System::Drawing::Point(794, 6);
    this->UsernameLbl->Name = L"UsernameLbl";
    this->UsernameLbl->Size = System::Drawing::Size(119, 26);
    this->UsernameLbl->TabIndex = 17;
    this->UsernameLbl->Text = L"username";
    this->UsernameLbl->TextAlign = System::Drawing::ContentAlignment::TopRight;
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
    this->btnGoBack->TabIndex = 11;
    this->btnGoBack->Text = L"Go back";
    this->btnGoBack->UseVisualStyleBackColor = true;
    this->btnGoBack->Click += gcnew System::EventHandler(this, &CurrencyForm::btnGoBack_Click);
    // 
    // CurrencyForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->ClientSize = System::Drawing::Size(927, 543);
    this->Controls->Add(this->panel1);
    this->Name = L"CurrencyForm";
    this->Text = L"CurrencyForm";
    this->Load += gcnew System::EventHandler(this, &CurrencyForm::CurrencyForm_Load);
    this->panel1->ResumeLayout(false);
    this->panel1->PerformLayout();
    this->ResumeLayout(false);

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

void MainClient::CurrencyForm::Init()
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

