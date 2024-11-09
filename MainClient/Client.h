#pragma once

#include <Windows.h>
#include "UserDetails.h"

ref class Client
{
public:
	Client();
	~Client();

	void setUserDetails(const UserDetails^ user);
	const UserDetails^ getUserDetails();

private:
	UserDetails^ userDetails;
	HANDLE hPipe;
	const wchar_t* pipeName = L"\\\\.\\pipe\\UserDetailsPipe";
};

