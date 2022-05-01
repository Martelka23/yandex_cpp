// класс Date, а также функцию ParseDate 
// и оператор вывода в поток для класса Date.
#include "date.h"

Date::Date(const int& y, const int& m, const int& d) : year(y), month(m), day(d) {}

int Date::GetYear() const { return year; }
int Date::GetMonth() const { return month; }
int Date::GetDay() const { return day; }


Date ParseDate(istream& is)
{
    int year, month, day;
    bool error = false;
    is >> ws;
    // Ввод года
    error += !(is >> year);
    error += (is.peek() != '-');
    is.ignore(1);
    // Ввод месяца
    error += !(is >> month);
    error += (is.peek() != '-');
    is.ignore(1);
    // Ввод дня
    error += !(is >> day);
    is.ignore(1);
    
    if (error)
        throw invalid_argument("Wrong Date input!");

    return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date)
{
    os << setfill('0') << setw(4) << date.GetYear() << "-"; // Вывод года
    os << setfill('0') << setw(2) << date.GetMonth() << "-"; // Вывод месяца
    os << setfill('0') << setw(2) << date.GetDay(); // Вывод дня

    return os;
}

bool operator<(const Date& a, const Date& b)
{
    return vector<int>{a.GetYear(), a.GetMonth(), a.GetDay()} <
      vector<int>{b.GetYear(), b.GetMonth(), b.GetDay()};
}