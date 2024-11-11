#pragma once

namespace MainClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class StockForecastForm : public System::Windows::Forms::Form
	{
	public:
		StockForecastForm(void);

	protected:
		~StockForecastForm();

	private: 
		System::Windows::Forms::Label^ titleLbl;
		System::Windows::Forms::Label^ userListLbl;
		System::Windows::Forms::TextBox^ txtUserList;
		System::Windows::Forms::TextBox^ txtStocksInfo;
		System::Windows::Forms::Label^ stocksInfoLbl;
	private: System::Windows::Forms::Button^ startUpdatesBtn;

		   System::ComponentModel::Container^ components;

	private:
		void InitializeComponent(void);
		void StartStockUpdates();
		void UpdateStocks(Object^ state);
		void UpdateUserList();
		System::Void startUpdatesBtn_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
