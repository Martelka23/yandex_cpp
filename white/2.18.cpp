#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main()
{
    map<int, set<string>> numbers;
    map<set<string>, int> stops;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        set<string> tmp_stops;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            string stop;
            cin >> stop;
            tmp_stops.insert(stop);
        }
        if (stops.count(tmp_stops))
            cout << "Already exists for " << stops[tmp_stops] + 1 << endl;
        else
        {
            int m = numbers.size();
            numbers[m] = tmp_stops;
            stops[tmp_stops] = m;
            cout << "New bus " << m + 1 << endl;
        }
    }
    return 0;
}