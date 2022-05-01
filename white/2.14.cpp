#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<int, vector<string>> numbers;
    map<vector<string>, int> stops;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        vector<string> tmp_string;
        for (int j = 0; j < k; j++)
        {
            string stop;
            cin >> stop;
            tmp_string.push_back(stop);
        }
        if (stops.count(tmp_string))
        {
            cout << "Already exists for " << stops[tmp_string] + 1 << endl;
        } else
        {
            int num = numbers.size();
            cout << "New bus " << num + 1 << endl;
            numbers[num] = tmp_string;
            stops[tmp_string] = num;
        }
        
    }
    return 0;
}