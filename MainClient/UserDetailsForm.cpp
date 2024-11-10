#include "UserDetailsForm.h"
#include "ServicesListForm.h"

#include "Client.h"

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
	this->usernameLabel = (gcnew System::Windows::Forms::Label());
	this->userEmailLabel = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// usernameTextBox
	// 
	this->usernameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->usernameTextBox->Location = System::Drawing::Point(361, 171);
	this->usernameTextBox->Name = L"usernameTextBox";
	this->usernameTextBox->Size = System::Drawing::Size(350, 34);
	this->usernameTextBox->TabIndex = 0;
	// 
	// userEmailTextBox
	// 
	this->userEmailTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->userEmailTextBox->Location = System::Drawing::Point(361, 257);
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
	this->loginBtn->Location = System::Drawing::Point(466, 311);
	this->loginBtn->Name = L"loginBtn";
	this->loginBtn->Size = System::Drawing::Size(142, 42);
	this->loginBtn->TabIndex = 3;
	this->loginBtn->Text = L"Save";
	this->loginBtn->UseVisualStyleBackColor = true;
	this->loginBtn->Click += gcnew System::EventHandler(this, &UserDetailsForm::loginBtn_Click);
	// 
	// usernameLabel
	// 
	this->usernameLabel->AutoSize = true;
	this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->usernameLabel->Location = System::Drawing::Point(356, 143);
	this->usernameLabel->Name = L"usernameLabel";
	this->usernameLabel->Size = System::Drawing::Size(150, 20);
	this->usernameLabel->TabIndex = 4;
	this->usernameLabel->Text = L"Enter name here ...";
	// 
	// userEmailLabel
	// 
	this->userEmailLabel->AutoSize = true;
	this->userEmailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->userEmailLabel->Location = System::Drawing::Point(356, 229);
	this->userEmailLabel->Name = L"userEmailLabel";
	this->userEmailLabel->Size = System::Drawing::Size(149, 20);
	this->userEmailLabel->TabIndex = 5;
	this->userEmailLabel->Text = L"Enter email here ...";
	// 
	// UserDetailsForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1074, 518);
	this->Controls->Add(this->userEmailLabel);
	this->Controls->Add(this->usernameLabel);
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

System::Void MainClient::UserDetailsForm::loginBtn_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ username = usernameTextBox->Text;
	String^ userEmail = userEmailTextBox->Text;

	if (String::IsNullOrWhiteSpace(username) || String::IsNullOrWhiteSpace(userEmail)) {
		MessageBox::Show("Username or email cannot be empty. Please before login enter it.", 
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	try
	{
		UserDetails^ details = gcnew UserDetails(username, userEmail);

		Client^ client = gcnew Client();
		client->setUserDetails(details);

		client->sendUserDetails();

		this->Hide();
		ServicesListForm^ servicesForm = gcnew ServicesListForm();
		servicesForm->ShowDialog();
		this->Close();
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Failed to send user details!", 
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
