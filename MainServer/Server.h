#pragma once

#include<string>
#include <vector>
#include <Windows.h>

#include "ServiceDetails.h"

class Server
{
public:
	Server();

	void run();

	void displayServices() const;

	void getUserDetails();

private:
	void loadServicesFromFile(const std::string filename);

private:
	HANDLE hPipe;
	const wchar_t* pipeName = L"\\\\.\\pipe\\UserDetailsPipe";
	std::vector<ServiceDetails> services;
};

