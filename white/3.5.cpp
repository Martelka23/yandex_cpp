#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

string ReturnVector(vector<string>& v)
{
    string answer = v[0];
    bool first = true;
    for (int i = 1; i < (int)v.size(); i++)
    {
        if (first)
        {
            answer += " (";
            first = false;
        }
        answer += v[i] + ", ";
    }
    if (v.size() > 1)
    {
        answer.erase(answer.size() - 1);
        answer[answer.size() - 1] = ')';
    }
    return answer;
}

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
    string GetFullNameWithHistory(int year)
    {
        // получить все имена и фамилии по состоянию на конец года year
        vector<string> name = GetAllLastNames(year);
        vector<string> surname = GetAllLastSurnames(year);
        if (name[0] == "false" && surname[0] == "false")
            return "Incognito";
        // auto elem = (*(--iter)).second;
        if (name[0] != "false" && surname[0] != "false")
            return ReturnVector(name) + " " + ReturnVector(surname);
        else if (name[0] != "false" && surname[0] == "false")
            return ReturnVector(name) + " with unknown last name";
        else if (name[0] == "false" && surname[0] != "false")
            return ReturnVector(surname) + " with unknown first name";
        return "Error";

    }
    vector<string> GetAllLastNames(int year)
    {
        vector<string> answer;
        auto item = info.end();
        do
        {
            --item;
            if ((*item).second.count("name") && (*item).first <= year && (answer.size() == 0 || answer[answer.size() - 1] != (*item).second["name"]))
                answer.push_back((*item).second["name"]);
        }
        while ((*item).first > (*info.begin()).first);
        if (!answer.size())
            answer.push_back("false");
        return answer;
    }
    vector<string> GetAllLastSurnames(int year)
    {
        vector<string> answer;
        auto item = info.end();
        do
        {
            --item;
            if ((*item).second.count("surname") && (*item).first <= year && (answer.size() == 0 || answer[answer.size() - 1] != (*item).second["surname"]))
                answer.push_back((*item).second["surname"]);
        }
        while ((*item).first > (*info.begin()).first);
        if (!answer.size())
            answer.push_back("false");
        return answer;
    }
private:
    // приватные поля
    map<int, map<string, string>> info;
};

// int main() {
//   Person person;
  
//   person.ChangeFirstName(1965, "Polina");
//   person.ChangeLastName(1967, "Sergeeva");
//   for (int year : {1900, 1965, 1990}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1970, "Appolinaria");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeLastName(1968, "Volkova");
//   for (int year : {1969, 1970}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeFirstName(1990, "Polina");
//   person.ChangeLastName(1990, "Volkova-Sergeeva");
//   cout << person.GetFullNameWithHistory(1990) << endl;
  
//   person.ChangeFirstName(1966, "Pauline");
//   cout << person.GetFullNameWithHistory(1966) << endl;
  
//   person.ChangeLastName(1960, "Sergeeva");
//   for (int year : {1960, 1967}) {
//     cout << person.GetFullNameWithHistory(year) << endl;
//   }
  
//   person.ChangeLastName(1961, "Ivanova");
//   cout << person.GetFullNameWithHistory(1967) << endl;
  
//   return 0;
// }
