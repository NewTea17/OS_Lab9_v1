#include "ServicesListForm.h"

MainClient::ServicesListForm::ServicesListForm(void)
{
	InitializeComponent();
}

MainClient::ServicesListForm::~ServicesListForm()
{
	if (components)
	{
		delete components;
	}
}

void MainClient::ServicesListForm::InitializeComponent(void)
{
	this->SuspendLayout();
	// 
	// ServicesListForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1074, 518);
	this->Name = L"ServicesListForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"ServicesListForm";
	this->Load += gcnew System::EventHandler(this, &ServicesListForm::ServicesListForm_Load);
	this->ResumeLayout(false);

}

System::Void MainClient::ServicesListForm::ServicesListForm_Load(System::Object^ sender, System::EventArgs^ e)
{ }