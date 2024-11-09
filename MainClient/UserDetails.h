#pragma once

using namespace System;

ref class UserDetails
{
public:
	String^ name;
	String^ email;

	UserDetails();

	UserDetails(String^ name, String^ email);
};

