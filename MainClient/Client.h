#pragma once

#include <string>
#include <Windows.h>

#include "UserDetails.h"

ref class Client
{
public:
	Client();
	~Client();

	void setUserDetails(const UserDetails^ user);
	const UserDetails^ getUserDetails();

	void sendUserDetails();

	bool isUserRegistered(const std::string& userName);

	bool isUserInFile(const std::string& userName, const std::string& filename);

private:
	UserDetails^ userDetails;
	HANDLE hPipe;
	const wchar_t* pipeName = L"\\\\.\\pipe\\UserDetailsPipe";
};

