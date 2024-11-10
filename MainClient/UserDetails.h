#pragma once
using namespace System;
using namespace System::Text::RegularExpressions;

ref class UserDetails
{
public:
	String^ name;
	String^ email;

	UserDetails();

	UserDetails(String^ name, String^ email);

	bool isValid();
};

