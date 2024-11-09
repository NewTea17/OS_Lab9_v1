#pragma once
#include <Windows.h>

class Server
{
public:
	Server();

	void run();

	void getUserDetails();

private:
	HANDLE hPipe;
	const wchar_t* pipeName = L"\\\\.\\pipe\\UserDetailsPipe";
};

