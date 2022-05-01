#include <iostream>
#include <string>
#include <vector>
using namespace std;

void add(vector<vector<string>>& tasks, int i, string s)
{
    tasks[i].push_back(s);
}

void dump(vector<vector<string>>& tasks, int i)
{
    cout << tasks[i].size() << " ";
    for (string s : tasks[i])
        cout << s << " ";
    cout << endl;
}

void next(vector<vector<string>>& tasks, int& i, const vector<int> days_in_month)
{
    if (days_in_month[i % 12] > days_in_month[(i + 1) % 12])
        for (int j = days_in_month[(i + 1) % 12]; j < days_in_month[i % 12]; j++)
            tasks[days_in_month[(i + 1) % 12] - 1].insert(end(tasks[days_in_month[(i + 1) % 12] - 1]), begin(tasks[j]), end(tasks[j]));
    tasks.resize(days_in_month[(++i) % 12]);
}

int main()
{
    // Объявление переменных
    vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int todays_month = 0;
    vector<vector<string>> tasks (days_in_month[todays_month]);
    int n;
    cin >> n;
    // Выполнение n команд
    for (int i = 0; i < n; i++)
    {
        // Ввод команды
        string command;
        cin >> command;
        
        if (command == "NEXT")
            next(tasks, todays_month, days_in_month);
        else
        {
            // Ввод числа
            int x;
            cin >> x;
            x--;
            if (command == "DUMP")
                dump(tasks, x);
            else if (command == "ADD")
            {
                string str;
                cin >> str;
                add(tasks, x, str);
            }
        }
    }
    return 0;
}