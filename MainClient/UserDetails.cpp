#include "UserDetails.h"

UserDetails::UserDetails()
    : name("Unknown user name"), email("Unknown user email")
{ }

UserDetails::UserDetails(String^ name, String^ email)
    : name(name), email(email)
{ }

// Метод для перевірки валідності облікових даних
bool UserDetails::isValid() {
    // Перевіряємо, що ім'я не є порожнім
    if (String::IsNullOrEmpty(name)) {
        return false;
    }

    // Перевіряємо, що email не є порожнім і відповідає простому формату email
    String^ emailPattern = R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)";

    if (String::IsNullOrEmpty(email) || !Regex::IsMatch(email, emailPattern)) {
        return false;
    }

    return true; // Якщо всі перевірки пройдені, облікові дані вважаються валідними
}