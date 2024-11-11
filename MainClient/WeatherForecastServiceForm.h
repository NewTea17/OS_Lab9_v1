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

	protected:
		~WeatherForecastServiceForm();
	private: System::Windows::Forms::Label^ weatherForecastLbl;
	protected:

	protected:

	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void);
	};
}
