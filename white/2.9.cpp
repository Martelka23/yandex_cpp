#include <iostream>
#include <string>
#include <vector>
using namespace std;

void worry(vector<bool>& v, int i)
{
    v[i] = true;
}

void quiet(vector<bool>& v, int i)
{
    v[i] = false;
}

void come(vector<bool>& v, int i)
{
    if (i > 0)
        v.resize(v.size() + i, false);
    else
        v.resize(v.size() + i);
}

void worry_count(const vector<bool>& v)
{
    int count = 0;
    for (bool x : v)
        if (x)
            count++;
    cout << count << endl;
}

int main()
{
    vector<bool> people;
    string command;
    int x;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "WORRY_COUNT")
            worry_count(people);
        else
        {
            cin >> x;
            if (command == "WORRY")
                worry(people, x);
            else if (command == "QUIET")
                quiet(people, x);
            else if (command == "COME")
                come(people, x);
        }
    }

    return 0;
}