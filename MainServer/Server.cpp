#include <iostream>
#include "Server.h"

Server::Server()
    : hPipe(INVALID_HANDLE_VALUE)
{ }

void Server::run()
{
    std::cout << "Starting server..." << std::endl;

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
        hPipe,          // Дескриптор пайпу
        buffer,         // Буфер для читання
        sizeof(buffer), // Розмір буфера
        &bytesRead,     // Кількість прочитаних байтів
        NULL);          // Без оверлапінгу

    if (!success || bytesRead == 0)
    {
        std::cerr << "Failed to read from pipe. Error: " << GetLastError() << std::endl;
        CloseHandle(hPipe);
        return;
    }

    buffer[bytesRead] = '\0';
    std::cout << "User details received: " << buffer << std::endl;
}

