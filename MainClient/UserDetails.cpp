#include "UserDetails.h"

UserDetails::UserDetails()
    : name("Unknown user name"), email("Unknown user email")
{ }

UserDetails::UserDetails(System::String^ name, System::String^ email)
    : name(name), email(email)
{ }

bool UserDetails::isValid() {
    if (System::String::IsNullOrEmpty(name)) {
        return false;
    }

    System::String^ emailPattern = R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)";

    if (System::String::IsNullOrEmpty(email) || !Regex::IsMatch(email, emailPattern)) {
        return false;
    }

    return true; 
}