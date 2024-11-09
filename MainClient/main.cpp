#include <iostream>
#include "UserDetailsForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	MainClient::UserDetailsForm userDetailsForm;
	Application::Run(% userDetailsForm);
}