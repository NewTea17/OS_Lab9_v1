#pragma once
#include "UserDetails.h" // Підключення класу для роботи з даними користувача

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
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxEmail;
	protected:

	protected:

	private: System::Windows::Forms::Label^ nameLbl;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnLogIn;



	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void);

		System::Void UserDetailsForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void btnLogIn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
