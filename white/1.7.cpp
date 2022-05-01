#include <iostream>
using namespace std;

int main()
{
    string str;
    int count = 0;
    cin >> str;
    for (long unsigned int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'f')
            count++;
        if (count == 2)
        {
            cout << i << endl;
            return 0;
        }
    }
    if (count == 0)
        cout << -2 << endl;
    else
        cout << -1 << endl;

    return 0;
}