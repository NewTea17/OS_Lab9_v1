#pragma once

#include <string>
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
    void storeUserDetails(const std::string& subName, const std::string& subEmail);  // Зберігає дані користувача
    void processSubscription(const std::string& filename, const std::string& userName, bool subscribe); // Обробляє підписку/відписку
    void sendResponse(const std::string& response);  // Відправляє відповідь користувачу

private:
    HANDLE hPipe;
    const wchar_t* pipeName = L"\\\\.\\pipe\\UserDetailsPipe";
    std::vector<ServiceDetails> services;
};
