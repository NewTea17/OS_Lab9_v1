#include "UserDetails.h"

UserDetails::UserDetails()
    : name("Unknown user name"), email("Unknown user email")
{ }

UserDetails::UserDetails(String^ name, String^ email)
    : name(name), email(email)
{ }

// ����� ��� �������� �������� �������� �����
bool UserDetails::isValid() {
    // ����������, �� ��'� �� � �������
    if (String::IsNullOrEmpty(name)) {
        return false;
    }

    // ����������, �� email �� � ������� � ������� �������� ������� email
    String^ emailPattern = R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)";

    if (String::IsNullOrEmpty(email) || !Regex::IsMatch(email, emailPattern)) {
        return false;
    }

    return true; // ���� �� �������� �������, ������ ��� ���������� ��������
}