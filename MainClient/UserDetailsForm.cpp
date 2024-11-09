#include "UserDetailsForm.h"

MainClient::UserDetailsForm::UserDetailsForm(void)
{
	InitializeComponent();
}

MainClient::UserDetailsForm::~UserDetailsForm()
{
	if (components)
	{
		delete components;
	}
}

void MainClient::UserDetailsForm::InitializeComponent(void)
{
	this->SuspendLayout();
	// 
	// UserDetailsForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(1074, 518);
	this->Name = L"UserDetailsForm";
	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
	this->Text = L"UserDetailsForm";
	this->Load += gcnew System::EventHandler(this, &UserDetailsForm::UserDetailsForm_Load);
	this->ResumeLayout(false);

}

System::Void MainClient::UserDetailsForm::UserDetailsForm_Load(System::Object^ sender, System::EventArgs^ e)
{

}
