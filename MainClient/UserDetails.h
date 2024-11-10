#pragma once
using namespace System::Text::RegularExpressions;

ref class UserDetails
{
public:
	System::String^ name;
	System::String^ email;

	UserDetails();

	UserDetails(System::String^ name, System::String^ email);

	bool isValid();
};

