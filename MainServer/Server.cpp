#include <iostream>
#include <fstream>
#include <sstream>

#include "Subscriber.h"
#include "ServiceDetails.h"
#include "Server.h"

Server::Server()
	: hPipe(INVALID_HANDLE_VALUE)
{ 
    loadServicesFromFile("services.txt");
}

void Server::run()
{
    std::cout << "Starting server..." << std::endl; // log

    while (true)
    {
        hPipe = CreateNamedPipe(
            pipeName,                     // Ім'я пайпу
            PIPE_ACCESS_DUPLEX,           // Доступ до пайпу як на запис, так і на читання
            PIPE_TYPE_BYTE | PIPE_WAIT,   // Передача даних байтами
            10,                           // Максимум 10 клієнтів
            1024,                         // Розмір буфера для вихідних даних
            1024,                         // Розмір буфера для вхідних даних
            0,                            // Таймаут
            NULL);                        // Дефолтний дескриптор безпеки

        if (hPipe == INVALID_HANDLE_VALUE)
        {
            std::cerr << "Failed to create named pipe. Error: " << GetLastError() << std::endl; // log
            return;
        }

        std::cout << "Server is running. Waiting for client connection..." << std::endl; // log

        BOOL connected = ConnectNamedPipe(hPipe, NULL) ? TRUE : (GetLastError() == ERROR_PIPE_CONNECTED);
        if (!connected)
        {
            std::cerr << "Failed to connect to pipe. Error: " << GetLastError() << std::endl; // log
            CloseHandle(hPipe);
            continue; 
        }

        std::cout << "Client connected!" << std::endl; // log

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
        std::cerr << "Pipe is not initialized or client is not connected." << std::endl; // log
        return;
    }

    char buffer[1024];
    DWORD bytesRead;

    std::cout << "Receiving user details..." << std::endl; 

    BOOL success = ReadFile(
        hPipe,          // Дескриптор пайпу
        buffer,         // Буфер для читання
        sizeof(buffer), // Розмір буфера
        &bytesRead,     // Кількість прочитаних байтів
        NULL);          // Без оверлапінгу

    if (!success || bytesRead == 0)
    {
        std::cerr << "Failed to read from pipe. Error: " << GetLastError() << std::endl; // log 
        CloseHandle(hPipe);
        return;
    }

    buffer[bytesRead] = '\0'; 
    std::cout << "User details received: " << buffer << std::endl; // log

    std::istringstream iss(buffer);
    std::string subName;
    std::string subEmail;

    if (iss >> subName >> subEmail) {
        Subscriber subscriber(subName, subEmail);

    }
}

void Server::loadServicesFromFile(const std::string filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string name;
    std::string description;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;

        size_t dotPos = line.find('. ');
        if (dotPos != std::string::npos)
        {
            name = line.substr(dotPos + 1);
        }

        if (std::getline(file, line))
        {
            description = line;

            // Додаємо сервіс до списку, в залежності від назви
            if (name.find("Hourly Weather Forecast") != std::string::npos)
            {
                services.push_back(ServiceDetails(name, description));  // Додаємо сервіс прогнозу погоди
            }
            else if (name.find("Minute-by-Minute Stock Price") != std::string::npos)
            {
                services.push_back(ServiceDetails(name, description));  // Додаємо сервіс для акцій
            }
            else if (name.find("Daily Exchange Rate") != std::string::npos)
            {
                services.push_back(ServiceDetails(name, description));  // Додаємо сервіс для курсу валют
            }
        }
    }

    file.close();
}

