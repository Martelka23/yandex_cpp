#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

// Получение следующей фразы при вводе
string GetNext(string& input)
{
    string answer = "";
    while (!input.empty())
    {
        if (input[0] == ' ')
        {
            input.erase(0, 1);
            return answer;
        }
        answer += input[0];
        input.erase(0, 1);
    }
    return answer;
}

// Преобразование даты при вводе
string PrettyDate(string s)
{
    bool check = false;
    string old_date = s;
    for (int i = 0; i < (int)s.size(); i++)
        if (s[i] == '-' && check)
        {
            s[i] = ' ';
            check = false;
        } else if (!check && '0' <= s[i] && s[i] <= '9')
        {
            check = true;
        }
    if (!check)
        throw invalid_argument("Wrong date format: " + old_date);
    
    return s;
}
// Преобразование даты при выводе
string OutputDate()
{
    string answer;

    return answer;
}
// Преобразование строки в число
// int ToInt(string s)
// {
//     int answer = 0;
//     for (int i = 0; i < (int)s.size(); i++)
//         answer = answer * 10 + atoi(s[i]);

//     return answer;
// }

// Подсчет количества вхождений элемента в векторе
bool VCheck(const vector<string>& v, const string& s)
{
    for (const string& x : v)
        if (x == s)
            return true;
    return false;
}

// Класс даты
class Date {
public:
    Date(string& date)
    {
        string s;
        string old_date = date;
        // Преобразование даты
        date = PrettyDate(date);
        // Проверка и запись года
        s = GetNext(date);
        if ((s[0] < '0' || s[0] > '9') && s[0] != '-' && s[0] != '+')
            throw invalid_argument("Wrong date format: " + old_date);
        for (int i = 1; i < (int)s.size(); i++)
            if (s[i] < '0' || s[i] > '9')
                throw invalid_argument("Wrong date format: " + old_date);
        year = stoi(s);
        // Проверка и запись месяца
        s = GetNext(date);
        if ((s[0] < '0' || s[0] > '9') && s[0] != '-' && s[0] != '+')
            throw invalid_argument("Wrong date format: " + old_date);
        for (int i = 1; i < (int)s.size(); i++)
            if (s[i] < '0' || s[i] > '9')
                throw invalid_argument("Wrong date format: " + old_date);
        month = stoi(s);
        if (month <= 0 || month > 12)
            throw invalid_argument("Month value is invalid: " + to_string(month));
        // Проверка и запись дня
        s = GetNext(date);
        if ((s[0] < '0' || s[0] > '9') && s[0] != '-' && s[0] != '+')
            throw invalid_argument("Wrong date format: " + old_date);
        for (int i = 1; i < (int)s.size(); i++)
            if (s[i] < '0' || s[i] > '9')
                throw invalid_argument("Wrong date format: " + old_date);
        day = stoi(s);
        if (day <= 0 || day > 31)
            throw invalid_argument("Day value is invalid: " + to_string(day));

    }
    // Получение переменных
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }
    void PrintDate() const
    {
        cout << setfill('0') << setw(4) << year << "-" << setw(2) << month << "-" << setw(2) << day << setfill(' ');
    }
    string GetDate() const
    {
        return to_string(year) + '-' + to_string(month) + '-' + to_string(day);
    }
private:
    int year, month, day;
};

// Оператор сравнения
bool operator<(const Date& lhs, const Date& rhs)
{
    if (lhs.GetYear() != rhs.GetYear())
        return lhs.GetYear() < rhs.GetYear();
    if (lhs.GetMonth() != rhs.GetMonth())
        return lhs.GetMonth() < rhs.GetMonth();
    if (lhs.GetDay() != rhs.GetDay())
        return lhs.GetDay() < rhs.GetDay();
    return false;
}

// Класс базы данных
class Database {
public:
    // Добавление события
    void AddEvent(const Date& date, const string& event)
    {
        if (!info[date].count(event))
            info[date].insert(event);
    }

    // Удаление события
    bool DeleteEvent(const Date& date, const string& event)
    {
        bool deleted = info[date].count(event);
        info[date].erase(event);

        return deleted;
    }

    // Удаление даты
    int  DeleteDate(const Date& date)
    {
        int n = info[date].size();
        info.erase(date);

        return n;
    }

    // Поиск событий по дате
    void Find(const Date& date) const
    {
        if (info.count(date))
            for (const string& x : info.at(date))
                cout << x << endl;
    }

    // Вывод всех событий на экран
    void Print() const
    {
        for (const auto& event : info)
        {
            for (const string s : event.second)
            {
                event.first.PrintDate();
                cout << " " << s << endl;
            }
        }
    }

private:
    // Словарь со всеми событиями
    map<Date, set<string>> info;
};

int main() {
    Database db;

    string input;
    while (getline(cin, input)) 
    {
        if (input.empty())
            continue;
        string command = GetNext(input);

        // Добавление события
        if (command == "Add")
        {   
            string s = GetNext(input);
            try
            {
                db.AddEvent(Date(s), input);
            } catch (exception& ex)
            {
                cout << ex.what() << endl;
                return 1;
            }
        } 
        // Удаление события или даты
        else if (command == "Del")
        {
            string s = GetNext(input);
            try
            {
                Date date(s); 
                
                if (input.empty())
                {
                    // Удаление события
                    int n = db.DeleteDate(date);
                    cout << "Deleted " << n << " events" << endl;
                }
                else
                {
                    // Удаление по дате
                    if (db.DeleteEvent(date, input))
                        cout << "Deleted successfully" << endl;
                    else
                        cout << "Event not found" << endl;
                }
            } catch (exception& ex)
            {
                cout << ex.what() << endl;
                // continue;
                return 1;
            }
        }
        // Поиск событий по дате
        else if (command == "Find")
        {
            string s = GetNext(input);
            try
            {
                db.Find(Date(s));
            } catch (invalid_argument& ex)
            {
                cout << ex.what() << endl;
                return 1;
            }
        }
        // Вывод всех событий на экран
        else if (command == "Print")
        {
            db.Print();
        }
        // Неправильная команда
        else
        {
            cout << "Unknown command: " << command << endl;
        }
    }

    return 0;
}