#pragma once

namespace MainClient {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class ServiceForm : public System::Windows::Forms::Form
	{
	public:
		ServiceForm(void);
		ServiceForm(String^ userName);

	protected:
		~ServiceForm();

	private:
		String^ nameOfUser;
		System::Windows::Forms::Label^ ServicesLbl;

		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::PictureBox^ pictureBox2;
		System::Windows::Forms::PictureBox^ pictureBox3;

		System::Windows::Forms::PictureBox^ pictureWeather;
		System::Windows::Forms::PictureBox^ pictureStocks;
		System::Windows::Forms::PictureBox^ pictureExchange;

		System::Windows::Forms::Label^ weatherLbl;
		System::Windows::Forms::Label^ stockLbl1;
		System::Windows::Forms::Label^ exchangeLbl;

		System::Windows::Forms::Label^ stockLbl2;
		System::Windows::Forms::Button^ btnSub1;
		System::Windows::Forms::Button^ btnUnsub1;

		System::Windows::Forms::Button^ btnSub2;
		System::Windows::Forms::Button^ btnUnsub2;

		System::Windows::Forms::Button^ btnSub3;
		System::Windows::Forms::Button^ btnUnsub3;
	private: System::Windows::Forms::Label^ UsernameLbl;



		System::ComponentModel::Container ^components;


		void InitializeComponent(String^ nameOfUser);

		System::Void btnSub1_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnSub2_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void btnSub3_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnUnsub1_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void btnUnsub2_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btnUnsub3_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
