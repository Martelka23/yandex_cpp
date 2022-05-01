#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        map<char, int> sym1, sym2;
        cin >> a >> b;
        for (const char c : a)
            ++sym1[c];
        for (const char c : b)
            ++sym2[c];
        if (sym1 == sym2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}