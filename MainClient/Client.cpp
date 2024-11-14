#include <fstream>
#include <iostream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "Client.h"

Client::Client()
    : userDetails(nullptr)
{
    hPipe = CreateFileW(pipeName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hPipe == INVALID_HANDLE_VALUE) {
        throw gcnew System::InvalidOperationException("Cannot connect to pipe");
    }
}

Client::~Client()
{
    if (hPipe != INVALID_HANDLE_VALUE) {
        CloseHandle(hPipe);
    }
}

void Client::setUserDetails(const UserDetails^ user)
{
    if (user != nullptr) {
        userDetails = gcnew UserDetails(user->name, user->email);
    } else {
        userDetails = nullptr;
    }
}

const UserDetails^ Client::getUserDetails()
{
    return userDetails;
}

void Client::sendUserDetails()
{
    if (hPipe == INVALID_HANDLE_VALUE) {
        throw gcnew System::InvalidOperationException("Pipe isn't opened!");
    }

    msclr::interop::marshal_context context;
    std::string username = context.marshal_as<std::string>(userDetails->name);
    std::string userEmail = context.marshal_as<std::string>(userDetails->email);

    std::string message = username + " " + userEmail;
    DWORD bytesWritten;

    BOOL success = WriteFile(hPipe, message.c_str(), message.length(), &bytesWritten, NULL);
    if (!success) {
        throw gcnew System::InvalidOperationException("Cannot send user details to server!");
    }
}

bool Client::isUserRegistered(const std::string& userName)
{
    if (
        isUserInFile(userName, "usersOfWeatherService.txt") ||
        isUserInFile(userName, "usersOfStocksService.txt") ||
        isUserInFile(userName, "usersOfCurrencyService.txt")
        ) {
        return true;
    }

    return false;
}

bool Client::isUserInFile(const std::string& userName, const std::string& filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw gcnew System::InvalidOperationException("Cannot open file!");
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == userName) {
            file.close();
            return true; 
        }
    }

    file.close();
    return false;
}
