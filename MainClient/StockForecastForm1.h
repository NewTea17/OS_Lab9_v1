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
		StockForecastForm(String^ userName);

		System::Void AddSubscriberToList(String^ userName);

		System::Void UpdateSubscribersList();

		void UpdateStocksPrices();

	protected:
		~StockForecastForm();

	private:
		System::Windows::Forms::Label^ titleLbl;
		System::Windows::Forms::Label^ userListLbl;
		System::Windows::Forms::TextBox^ txtUserList;
		System::Windows::Forms::TextBox^ txtStocksInfo;
		System::Windows::Forms::Label^ stocksInfoLbl;

		System::Windows::Forms::Timer^ updateTimer;
		System::Windows::Forms::Timer^ stocksTimer;
		System::Windows::Forms::Button^ btnGoBack;
		System::Windows::Forms::Label^ UsernameLbl;
		
		System::ComponentModel::IContainer^ components;



		void InitializeComponent(void);

		void LoadStocksForecast();

		void Init();

		bool CheckIfUserIsSubscribed(String^ userName);

		System::Void OnUpdateTimerTick(System::Object^ sender, System::EventArgs^ e);
		System::Void OnStocksTimerTick(System::Object^ sender, System::EventArgs^ e);
		System::Void btnGoBack_Click(System::Object^ sender, System::EventArgs^ e);
	};
}