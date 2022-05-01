#include <iostream>
#include <string>
#include <map>
using namespace std;

void dump(const map<string, string>& capitals)
{
    if (capitals.size() == 0)
        cout << "There are no countries in the world" << endl;
    for (const auto country : capitals)
        cout << country.first << "/" << country.second << " ";
    cout << endl;
}

void about(map<string, string>& capitals, const string& country)
{
    if (capitals.count(country) == 0)
        cout << "Country " << country << " doesn't exist" << endl;
    else
        cout << "Country " << country << " has capital " << capitals[country] << endl;
}

void change_capital(map<string, string>& capitals, string country, string capital)
{
    if (capitals.count(country) == 0)
    {
        capitals[country] = capital;
        cout << "Introduce new country " << country << " with capital " << capital << endl;
    } else if (capitals[country] == capital)
        cout << "Country " << country << " hasn't changed its capital" << endl;
    else
    {
        cout << "Country " << country << " has changed its capital from " << capitals[country] << " to " << capital << endl;
        capitals[country] = capital;
    }
}

void rename(map<string, string>& capitals, const string& country, const string& new_name)
{
    if (capitals.count(country) == 0 || capitals.count(new_name) == 1)
        cout << "Incorrect rename, skip" << endl;
    else
    {
        capitals[new_name] = capitals[country];
        capitals.erase(country);
        cout << "Country " << country << " with capital " << capitals[new_name] << " has been renamed to " << new_name << endl;
    }
}

int main()
{
    int n;
    map<string, string> capitals;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "DUMP")
            dump(capitals);
        else if (command == "ABOUT")
        {
            string country;
            cin >> country;
            about(capitals, country);
        } else if (command == "CHANGE_CAPITAL")
        {
            string country, capital;
            cin >> country >> capital;
            change_capital(capitals, country, capital);
        } else if (command == "RENAME")
        {
            string country, new_name;
            cin >> country >> new_name;
            rename(capitals, country, new_name);
        }
    }

    return 0;
}