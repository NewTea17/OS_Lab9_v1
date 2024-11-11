#pragma once

namespace MainClient {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class WeatherForecastServiceForm : public System::Windows::Forms::Form
	{
	public:
		WeatherForecastServiceForm(void);

		System::Void AddSubscriberToList(String^ userName);

	protected:
		~WeatherForecastServiceForm();

	private:
		System::Windows::Forms::Label^ weatherForecastLbl;
		System::Windows::Forms::TextBox^ weatherInformationBox;
		System::Windows::Forms::Label^ weatherInfoLbl;

		System::Windows::Forms::TextBox^ subscribersListBox;
		System::Windows::Forms::Label^ subscribersListLbl;


	private:
		System::ComponentModel::Container^ components;

		void InitializeComponent(void);
	};
}
