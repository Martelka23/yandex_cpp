#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    map<string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
    for (auto& i : m)
        if (i.second % 2 == 0)
            m.erase(i.first);

    for (auto i : m)
        cout << i.first << ' ' << i.second << endl;
        
    return 0;
}