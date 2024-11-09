#pragma once

#include <string>

class Subscriber
{
public:
    std::string name;
    std::string email;

    Subscriber(const std::string& name, const std::string& email);
};

