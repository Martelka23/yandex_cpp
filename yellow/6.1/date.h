#pragma once

#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

// Класс даты
class Date
{
public:
    Date(const int& y, const int& m, const int& d);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;

private:
    const int year;
    const int month;
    const int day;
};

// Парсинг даты из потока
Date ParseDate(istream& is);
// Вывод даты в поток
ostream& operator<<(ostream& os, const Date& date);
// Сравнение дат
bool operator<(const Date& a, const Date& b);