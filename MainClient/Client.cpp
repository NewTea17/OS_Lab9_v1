#include "Client.h"

Client::Client()
    : userDetails(nullptr), hPipe(INVALID_HANDLE_VALUE)
{ }

Client::~Client()
{
    if (hPipe != INVALID_HANDLE_VALUE) 
    {
        CloseHandle(hPipe);
    }
}

void Client::setUserDetails(const UserDetails^ user)
{
    if (user != nullptr)
    {
        userDetails = gcnew UserDetails(user->name, user->email);
    }
    else
    {
        userDetails = nullptr;
    }
}

const UserDetails^ Client::getUserDetails()
{
    return userDetails;
}
