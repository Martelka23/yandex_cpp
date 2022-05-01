#include "3.2.h"
#include <stdexcept>


PhoneNumber::PhoneNumber(const string &international_number)
{
    // Проверка номера
    if (international_number[0] != '+')
        throw invalid_argument("Number hasn't plus");
    int count_def = 0;
    for (const char& x : international_number)
        ++count_def;
    if (count_def < 2)
        throw invalid_argument("Number hasn't enough -");
    // Разбиение
    int i = 1;
    // Код страны
    string part = "";
    while (international_number[i] != '-' && i < international_number.size())
    {
        part += international_number[i];
        i++;
    }
    country_code_ = part;
    // Код города
    part = "";
    i++;
    while (international_number[i] != '-' && i < international_number.size())
    {
        part += international_number[i];
        i++;
    }
    city_code_ = part;
    // Локальный номер
    part = "";
    i++;
    while (i < international_number.size())
    {
        part += international_number[i];
        i++;
    }
    local_number_ += part;
    if (country_code_ == "" || city_code_ == "" || local_number_ == "")
        throw invalid_argument("Wrong number");
}

string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}