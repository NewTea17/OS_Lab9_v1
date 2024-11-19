#include <iostream>
#include <fstream>
#include <sstream>
#include "Subscriber.h"
#include "ServiceDetails.h"
#include "Server.h"

Server::Server()
    : hPipe(INVALID_HANDLE_VALUE)
{
}

void Server::run()
{
    std::cout << "Starting server..." << std::endl;

    while (true)
    {
        hPipe = CreateNamedPipe(
            pipeName,
            PIPE_ACCESS_DUPLEX,
            PIPE_TYPE_BYTE | PIPE_WAIT,
            10,
            1024,
            1024,
            0,
            NULL);

        if (hPipe == INVALID_HANDLE_VALUE)
        {
            std::cerr << "Failed to create named pipe. Error: " << GetLastError() << std::endl;
            return;
        }

        std::cout << "Server is running. Waiting for client connection..." << std::endl;

        BOOL connected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
        if (!connected)
        {
            std::cerr << "Failed to connect to pipe. Error: " << GetLastError() << std::endl;
            CloseHandle(hPipe);
            continue;
        }

        std::cout << "Client connected!" << std::endl;

        // Отримуємо дані користувача
        getUserDetails();
    }
}

void Server::displayServices() const
{
    std::cout << "Available Services:" << std::endl;
    std::cout << std::endl;

    for (const auto& service : services)
    {
        std::cout << "Service Name: " << service.getName() << std::endl;
        std::cout << "Description: " << service.getDescription() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << std::endl;
    }
}

void Server::getUserDetails()
{
    if (hPipe == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Pipe is not initialized or client is not connected." << std::endl;
        return;
    }

    char buffer[1024];
    DWORD bytesRead;

    std::cout << "Receiving user details..." << std::endl;

    BOOL success = ReadFile(
        hPipe,
        buffer,
        sizeof(buffer),
        &bytesRead,
        NULL);

    if (!success || bytesRead == 0)
    {
        std::cerr << "Failed to read from pipe. Error: " << GetLastError() << std::endl;
        CloseHandle(hPipe);
        return;
    }

    buffer[bytesRead] = '\0';
    std::cout << "User details received: " << buffer << std::endl;

    std::istringstream iss(buffer);
    std::string subName, subEmail, command;

    // Очікуємо команду, ім'я та email користувача
    if (iss >> command >> subName >> subEmail) {
        // Спочатку зберігаємо інформацію про користувача
        storeUserDetails(subName, subEmail);

        // Потім обробляємо команду для підписки чи відписки
        if (command == "SUBSCRIBE_WEATHER")
        {
            processSubscription("usersOfWeatherService.txt", subName, true);
        }
        else if (command == "UNSUBSCRIBE_WEATHER")
        {
            processSubscription("usersOfWeatherService.txt", subName, false);
        }
        else
        {
            sendResponse("ERROR: Unknown command");
        }
    }
}

void Server::storeUserDetails(const std::string& subName, const std::string& subEmail)
{
    HANDLE hFile = CreateFile(
        L"users.txt",
        FILE_APPEND_DATA,
        FILE_SHARE_READ,
        NULL,
        OPEN_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to open or create users.txt. Error: " << GetLastError() << std::endl;
        return;
    }

    std::string userData = subName + " " + subEmail + "\r\n";
    DWORD bytesWritten;

    BOOL success = WriteFile(
        hFile,
        userData.c_str(),
        userData.length(),
        &bytesWritten,
        NULL);

    if (!success)
    {
        std::cerr << "Failed to write to users.txt. Error: " << GetLastError() << std::endl;
    }
    else
    {
        std::cout << "User details saved to users.txt." << std::endl;
    }

    CloseHandle(hFile);
}

void Server::processSubscription(const std::string& filename, const std::string& userName, bool subscribe)
{
    std::ifstream inputFile(filename);
    std::ostringstream updatedContent;
    bool found = false;

    if (inputFile.is_open())
    {
        std::string line;
        while (std::getline(inputFile, line))
        {
            if (line == userName)
            {
                found = true;
                if (!subscribe)
                {
                    continue; // Пропускаємо користувача, якщо він відписується
                }
            }
            updatedContent << line << "\n";
        }
        inputFile.close();
    }

    if (subscribe && !found)
    {
        updatedContent << userName << "\n";
    }

    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << updatedContent.str();
        outputFile.close();
        sendResponse("SUCCESS: Subscription processed");
    }
    else
    {
        sendResponse("ERROR: Failed to process subscription");
    }
}

void Server::sendResponse(const std::string& response)
{
    DWORD bytesWritten;
    BOOL success = WriteFile(
        hPipe,
        response.c_str(),
        response.size(),
        &bytesWritten,
        NULL);

    if (!success || bytesWritten != response.size())
    {
        std::cerr << "Failed to write response to pipe. Error: " << GetLastError() << std::endl;
    }
    else
    {
        std::cout << "Response sent to client: " << response << std::endl;
    }

    FlushFileBuffers(hPipe);
    DisconnectNamedPipe(hPipe);
    CloseHandle(hPipe);
}
