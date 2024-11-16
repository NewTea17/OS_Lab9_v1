#pragma once

namespace MainClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class CurrencyForm : public System::Windows::Forms::Form
	{
	public:
		CurrencyForm(void);
		CurrencyForm(String^ userName);

		System::Void AddSubscriberToList(String^ userName);
		System::Void UpdateSubscribersList();
		void UpdateCurrencyRates();

	protected:
		~CurrencyForm();

	private: 
		System::Windows::Forms::Label^ currencyInfoLbl;

		System::Windows::Forms::TextBox^ txtCurrencyInfo;
		System::Windows::Forms::TextBox^ txtUserList;
		System::Windows::Forms::Label^ userListLbl;
		System::Windows::Forms::Label^ titleLbl;
		System::Windows::Forms::Panel^ panel1;

		System::Windows::Forms::Timer^ updateTimer;
		System::Windows::Forms::Timer^ currencyTimer;
		System::Windows::Forms::Button^ btnGoBack;
		System::Windows::Forms::Label^ UsernameLbl;
		System::ComponentModel::IContainer^ components;

		void InitializeComponent(void);
		void LoadCurrencyRates();

		void Init();

		System::Void OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e);
		System::Void OnCurrencyTimerTick(System::Object^ sender, System::EventArgs^ e);
		System::Void CurrencyForm_Load(System::Object^ sender, System::EventArgs^ e);
		System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

		bool CheckIfUserIsSubscribed(String^ userName);
		System::Void btnGoBack_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
