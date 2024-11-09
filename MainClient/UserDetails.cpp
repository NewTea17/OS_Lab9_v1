#include "UserDetails.h"

UserDetails::UserDetails()
    : name("Unknown user name"), email("Unknown user email")
{ }

UserDetails::UserDetails(String^ name, String^ email)
    : name(name), email(email)
{ }
