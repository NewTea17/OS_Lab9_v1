#include <fstream>
#include <sstream>
#include <msclr/marshal.h>

#include "UserDetailsForm.h"
#include "ServiceForm.h"

#include "Client.h"

MainClient::UserDetailsForm::UserDetailsForm(void)
{
	InitializeComponent();
}

MainClient::UserDetailsForm::~UserDetailsForm()
{
	if (components) {
		delete components;
	}
}

void MainClient::UserDetailsForm::InitializeComponent(void)
{
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserDetailsForm::typeid));
    this->textBoxName = (gcnew System::Windows::Forms::TextBox());
    this->textBoxEmail = (gcnew System::Windows::Forms::TextBox());
    this->nameLbl = (gcnew System::Windows::Forms::Label());
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->btnLogIn = (gcnew System::Windows::Forms::Button());
    this->btnRegister = (gcnew System::Windows::Forms::Button());
    this->SuspendLayout();
    // 
    // textBoxName
    // 
    this->textBoxName->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->textBoxName->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->textBoxName->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
        static_cast<System::Int32>(static_cast<System::Byte>(191)));
    this->textBoxName->Location = System::Drawing::Point(118, 82);
    this->textBoxName->Name = L"textBoxName";
    this->textBoxName->Size = System::Drawing::Size(275, 26);
    this->textBoxName->TabIndex = 0;
    this->textBoxName->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    // 
    // textBoxEmail
    // 
    this->textBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
    this->textBoxEmail->Font = (gcnew System::Drawing::Font(L"Elephant", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->textBoxEmail->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(154)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
        static_cast<System::Int32>(static_cast<System::Byte>(191)));
    this->textBoxEmail->Location = System::Drawing::Point(69, 157);
    this->textBoxEmail->Name = L"textBoxEmail";
    this->textBoxEmail->Size = System::Drawing::Size(382, 26);
    this->textBoxEmail->TabIndex = 1;
    this->textBoxEmail->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
    // 
    // nameLbl
    // 
    this->nameLbl->AutoSize = true;
    this->nameLbl->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->nameLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->nameLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->nameLbl->Location = System::Drawing::Point(133, 49);
    this->nameLbl->Name = L"nameLbl";
    this->nameLbl->Size = System::Drawing::Size(230, 30);
    this->nameLbl->TabIndex = 2;
    this->nameLbl->Text = L"Enter your name:";
    // 
    // label1
    // 
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"Elephant", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(117)), static_cast<System::Int32>(static_cast<System::Byte>(76)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->label1->Location = System::Drawing::Point(133, 124);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(232, 30);
    this->label1->TabIndex = 3;
    this->label1->Text = L"Enter your email:";
    // 
    // btnLogIn
    // 
    this->btnLogIn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
    this->btnLogIn->Font = (gcnew System::Drawing::Font(L"Elephant", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(0)));
    this->btnLogIn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->btnLogIn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLogIn.Image")));
    this->btnLogIn->Location = System::Drawing::Point(296, 214);
    this->btnLogIn->Name = L"btnLogIn";
    this->btnLogIn->Size = System::Drawing::Size(155, 58);
    this->btnLogIn->TabIndex = 4;
    this->btnLogIn->Text = L"LogIn";
    this->btnLogIn->UseVisualStyleBackColor = true;
    this->btnLogIn->Click += gcnew System::EventHandler(this, &UserDetailsForm::btnLogIn_Click);
    // 
    // btnRegister
    // 
    this->btnRegister->Font = (gcnew System::Drawing::Font(L"Elephant", 13.8F, System::Drawing::FontStyle::Bold));
    this->btnRegister->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(44)),
        static_cast<System::Int32>(static_cast<System::Byte>(158)));
    this->btnRegister->Location = System::Drawing::Point(69, 217);
    this->btnRegister->Name = L"btnRegister";
    this->btnRegister->Size = System::Drawing::Size(155, 58);
    this->btnRegister->TabIndex = 5;
    this->btnRegister->Text = L"Register";
    this->btnRegister->UseVisualStyleBackColor = true;
    this->btnRegister->Click += gcnew System::EventHandler(this, &UserDetailsForm::btnRegister_Click);
    // 
    // UserDetailsForm
    // 
    this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
    this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
    this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(188)),
        static_cast<System::Int32>(static_cast<System::Byte>(227)));
    this->ClientSize = System::Drawing::Size(516, 330);
    this->Controls->Add(this->btnRegister);
    this->Controls->Add(this->btnLogIn);
    this->Controls->Add(this->label1);
    this->Controls->Add(this->nameLbl);
    this->Controls->Add(this->textBoxEmail);
    this->Controls->Add(this->textBoxName);
    this->ForeColor = System::Drawing::Color::White;
    this->MaximumSize = System::Drawing::Size(534, 377);
    this->MinimumSize = System::Drawing::Size(534, 377);
    this->Name = L"UserDetailsForm";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->Text = L"UserDetailsForm";
    this->Load += gcnew System::EventHandler(this, &UserDetailsForm::UserDetailsForm_Load);
    this->ResumeLayout(false);
    this->PerformLayout();

}

System::Void MainClient::UserDetailsForm::UserDetailsForm_Load(System::Object^ sender, System::EventArgs^ e)
{

}

System::Void MainClient::UserDetailsForm::btnLogIn_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ userNameManaged = textBoxName->Text;
    System::String^ userEmailManaged = textBoxEmail->Text;

    UserDetails^ currentUser = gcnew UserDetails(userNameManaged, userEmailManaged);

    if (!currentUser->isValid()) {
        MessageBox::Show("Invalid name or email.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return System::Void();
    }

    IntPtr ptrToUserName = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(userNameManaged);
    std::string userName = static_cast<const char*>(ptrToUserName.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToUserName);

    IntPtr ptrToUserEmail = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(userEmailManaged);
    std::string userEmail = static_cast<const char*>(ptrToUserEmail.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToUserEmail);

    std::ifstream inputFile("users.txt");
    std::string line;
    bool userFound = false;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string existingUsername, existingEmail;
        ss >> existingUsername >> existingEmail;

        if (existingUsername == userName && existingEmail == userEmail) {
            userFound = true;
            break;
        }
    }
    inputFile.close();

    if (userFound) {
        MessageBox::Show("Login successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

        try {
            Client^ client = gcnew Client();
            client->setUserDetails(currentUser);
            client->sendUserDetails();

            this->Hide();

            ServiceForm^ serviceForm = gcnew ServiceForm(userNameManaged);
            serviceForm->ShowDialog();

            this->Close();
        }
        catch (InvalidOperationException^ ex) {
            MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Failed to send user details!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }
    else {
        MessageBox::Show("User not found or incorrect email.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void MainClient::UserDetailsForm::btnRegister_Click(System::Object^ sender, System::EventArgs^ e)
{
    System::String^ userNameManaged = textBoxName->Text;
    System::String^ userEmailManaged = textBoxEmail->Text;

    UserDetails^ newUser = gcnew UserDetails(userNameManaged, userEmailManaged);

    if (!newUser->isValid()) {
        MessageBox::Show("Invalid name or email.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return System::Void();
    }

    IntPtr ptrToUserName = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(userNameManaged);
    std::string userName = static_cast<const char*>(ptrToUserName.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToUserName);

    IntPtr ptrToUserEmail = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(userEmailManaged);
    std::string userEmail = static_cast<const char*>(ptrToUserEmail.ToPointer());
    System::Runtime::InteropServices::Marshal::FreeHGlobal(ptrToUserEmail);

    std::ifstream inputFile("users.txt");
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string existingUsername, existingEmail;
        ss >> existingUsername >> existingEmail;
        if (existingUsername == userName) {
            MessageBox::Show("User already registered!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            inputFile.close();
            return System::Void();
        }
    }
    inputFile.close();

    std::ofstream outputFile("users.txt", std::ios::app);
    if (!outputFile.is_open()) {
        MessageBox::Show("Failed to open user file for registration!", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        return System::Void();
    }

    outputFile << userName << " " << userEmail << std::endl;
    outputFile.close();

    Client^ client = gcnew Client();
    client->setUserDetails(newUser);

    client->sendUserDetails();

    this->Hide();
    ServiceForm^ serviceForm = gcnew ServiceForm(userNameManaged);
    serviceForm->ShowDialog();
    this->Close();

    MessageBox::Show("Registration successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
    return System::Void();
}
