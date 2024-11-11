#include "WeatherForecastServiceForm.h"

MainClient::WeatherForecastServiceForm::WeatherForecastServiceForm(void)
{
	InitializeComponent();
}

MainClient::WeatherForecastServiceForm::~WeatherForecastServiceForm()
{
	if (components) {
		delete components;
	}
}

void MainClient::WeatherForecastServiceForm::InitializeComponent(void)
{
	this->weatherForecastLbl = (gcnew System::Windows::Forms::Label());
	this->SuspendLayout();
	// 
	// weatherForecastLbl
	// 
	this->weatherForecastLbl->AutoSize = true;
	this->weatherForecastLbl->Font = (gcnew System::Drawing::Font(L"Elephant", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->weatherForecastLbl->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)),
		static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(158)));
	this->weatherForecastLbl->Location = System::Drawing::Point(217, 33);
	this->weatherForecastLbl->Name = L"weatherForecastLbl";
	this->weatherForecastLbl->Size = System::Drawing::Size(426, 43);
	this->weatherForecastLbl->TabIndex = 0;
	this->weatherForecastLbl->Text = L"Hourly weather forecast";
	// 
	// WeatherForecastServiceForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(925, 544);
	this->Controls->Add(this->weatherForecastLbl);
	this->MaximumSize = System::Drawing::Size(943, 591);
	this->MinimumSize = System::Drawing::Size(943, 591);
	this->Name = L"WeatherForecastServiceForm";
	this->Text = L"WeatherForecastServiceForm";
	this->ResumeLayout(false);
	this->PerformLayout();

}
