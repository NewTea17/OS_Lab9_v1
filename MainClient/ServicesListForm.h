#pragma once

namespace MainClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class ServicesListForm : public System::Windows::Forms::Form
	{
	public:
		ServicesListForm(void);

	protected:
		~ServicesListForm();

	private:
		System::ComponentModel::Container ^components;

		void InitializeComponent(void);

		System::Void ServicesListForm_Load(System::Object^ sender, System::EventArgs^ e);
	};
}
