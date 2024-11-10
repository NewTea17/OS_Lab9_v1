#pragma once

namespace MainClient {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class UserDetailsForm : public System::Windows::Forms::Form
	{
	public:
		UserDetailsForm(void);

	protected:
		~UserDetailsForm();
	private: System::Windows::Forms::TextBox^ usernameTextBox;
	protected:
	private: System::Windows::Forms::TextBox^ userEmailTextBox;
	private: System::Windows::Forms::Label^ loginLanel;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ userEmailLabel;

	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void);

		System::Void UserDetailsForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
