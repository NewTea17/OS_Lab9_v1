#include "UserDetailsForm.h"

MainClient::UserDetailsForm::UserDetailsForm(void)
{
	InitializeComponent();
}

MainClient::UserDetailsForm::~UserDetailsForm()
{
	if (components)
	{
		delete components;
	}
}

void MainClient::UserDetailsForm::InitializeComponent(void)
{
	this->usernameTextBox = (gcnew System::Windows::Forms::TextBox());
	this->userEmailTextBox = (gcnew System::Windows::Forms::TextBox());
	this->loginLanel = (gcnew System::Windows::Forms::Label());
	this->loginBtn = (gcnew System::Windows::Forms::Button());
	this->SuspendLayout();
	// 
	// usernameTextBox
	// 
	this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->usernameTextBox->Location = System::Drawing::Point(362, 162);
	this->usernameTextBox->Name = L"usernameTextBox";
	this->usernameTextBox->Size = System::Drawing::Size(350, 34);
	this->usernameTextBox->TabIndex = 0;
	// 
	// userEmailTextBox
	// 
	this->userEmailTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->userEmailTextBox->Location = System::Drawing::Point(362, 222);
	this->userEmailTextBox->Name = L"userEmailTextBox";
	this->userEmailTextBox->Size = System::Drawing::Size(350, 34);
	this->userEmailTextBox->TabIndex = 1;
	// 
	// loginLanel
	// 
	this->loginLanel->AutoSize = true;
	this->loginLanel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->loginLanel->Location = System::Drawing::Point(493, 85);
	this->loginLanel->Name = L"loginLanel";
	this->loginLanel->Size = System::Drawing::Size(80, 31);
	this->loginLanel->TabIndex = 2;
	this->loginLanel->Text = L"Login";
	// 
	// loginBtn
	// 
	this->loginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->loginBtn->Location = System::Drawing::Point(467, 276);
	this->loginBtn->Name = L"loginBtn";
	this->loginBtn->Size = System::Drawing::Size(142, 42);
	this->loginBtn->TabIndex = 3;
	this->loginBtn->Text = L"Save";
	this->loginBtn->UseVisualStyleBackColor = true;
	// 
	// UserDetailsForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1074, 518);
	this->Controls->Add(this->loginBtn);
	this->Controls->Add(this->loginLanel);
	this->Controls->Add(this->userEmailTextBox);
	this->Controls->Add(this->usernameTextBox);
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
