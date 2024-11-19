#pragma once

#include "UserDetails.h" 

namespace MainClient {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	public ref class UserDetailsForm : public System::Windows::Forms::Form
	{
	public:
		UserDetailsForm(void);

	protected:
		~UserDetailsForm();

	private: 
		System::Windows::Forms::TextBox^ textBoxName;
		System::Windows::Forms::TextBox^ textBoxEmail;

		System::Windows::Forms::Label^ nameLbl;
		System::Windows::Forms::Label^ label1;

		System::Windows::Forms::Button^ btnLogIn;
		System::Windows::Forms::Button^ btnRegister;

		System::ComponentModel::Container^ components;

		void InitializeComponent(void);

		System::Void UserDetailsForm_Load(System::Object^ sender, System::EventArgs^ e);

		System::Void btnLogIn_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e);

		void MainClient::UserDetailsForm::LogMessage(const std::string& userName, const std::string& userEmail, const std::string& message);
	};
}
