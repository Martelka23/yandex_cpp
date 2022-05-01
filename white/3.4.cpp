#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person 
{
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        info[year]["name"] = first_name;
        // if ((*--info.find(year)).second.count("surname") && info[year].count("surname") == 0)
        //     info[year]["surname"] = (*--info.find(year)).second["surname"];
    }
    void ChangeLastName(int year, const string& last_name) 
    {
        // добавить факт изменения фамилии на last_name в год year
        info[year]["surname"] = last_name;
        // if ((*--info.find(year)).second.count("name") && info[year].count("name") == 0)
        //     info[year]["name"] = (*--info.find(year)).second["name"];
    }
    string GetFullName(int year) 
    {
        // получить имя и фамилию по состоянию на конец года year
        // auto iter = info.upper_bound(year);
        string name = GetLastName(year);
        string surname = GetLastSurname(year);
        if (name == "false" && surname == "false")
            return "Incognito";
        // auto elem = (*(--iter)).second;
        if (name != "false" && surname != "false")
            return name + " " + surname;
        else if (name != "false" && surname == "false")
            return name + " with unknown last name";
        else if (name == "false" && surname != "false")
            return surname + " with unknown first name";
        return "Error";
    }

    string GetLastName(int year)
    {
        auto item = info.end();
        do
        {
            --item;
            if ((*item).second.count("name") && (*item).first <= year)
                return (*item).second["name"];
        }
        while ((*item).first > (*info.begin()).first);
        return "false";
    }
    string GetLastSurname(int year)
    {
        auto item = info.end();
        do
        {
            --item;
            if ((*item).second.count("surname") && (*item).first <= year)
                return (*item).second["surname"];
        }
        while ((*item).first > (*info.begin()).first);
        return "false";
    }
private:
    // приватные поля
    map<int, map<string, string>> info;
};

// int main() {
//     Person person;

//     person.ChangeFirstName(1965, "Polina");
//     person.ChangeLastName(1967, "Sergeeva");
//     for (int year : {1900, 1965, 1990}) {
//         cout << person.GetFullName(year) << endl;
//     }

//     person.ChangeFirstName(1970, "Appolinaria");
//     for (int year : {1969, 1970}) {
//         cout << person.GetFullName(year) << endl;
//     }

//     person.ChangeLastName(1968, "Volkova");
//     for (int year : {1969, 1970}) {
//         cout << person.GetFullName(year) << endl;
//     }

//     return 0;
// }
