#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void new_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops)
{
    string name;
    int count;
    cin >> name >> count;
    for (int i = 0; i < count; i++)
    {
        string stop;
        cin >> stop;
        buses[name].push_back(stop);
    }
    for (const auto stop : buses[name])
        stops[stop].push_back(name);
}

void buses_for_stop(map<string, vector<string>>& stops, const string& sought_stop)
{
    if (stops[sought_stop].size() == 0)
        cout << "No stop";
    else
    {
        for (const auto bus : stops[sought_stop])
            cout << bus << " ";
    }
    cout << endl;
}

void stops_for_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops)
{
    string bus;
    cin >> bus;
    if (buses.count(bus) == 0)
        cout << "No bus" << endl;
    else
    {
        for (const auto stop : buses[bus])
        {
            bool once = false;
            cout << "Stop " << stop << ": ";
            for (const auto another_bus : stops[stop])
                if (another_bus != bus)
                {
                    once = true;
                    cout << another_bus << " ";
                }
            if (!once)
                cout << "no interchange";
            cout << endl;
        }
    }
}

void all_buses(map<string, vector<string>>& buses)
{
    if (buses.size() == 0)
        cout << "No buses" << endl;
    for (const auto bus : buses)
    {
        cout << "Bus " << bus.first << ": ";
        for (const auto stop : bus.second)
            cout << stop << " ";
        cout << endl;
    }
}

int main()
{
    map<string, vector<string>> buses;
    map<string, vector<string>> stops;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "NEW_BUS")
            new_bus(buses, stops);
        else if (command == "BUSES_FOR_STOP")
        {
            string sought_stop;
            cin >> sought_stop;
            buses_for_stop(stops, sought_stop);
        }
        else if (command == "STOPS_FOR_BUS")
            stops_for_bus(buses, stops);
        else if (command == "ALL_BUSES")
            all_buses(buses);
    }

    return 0;
}