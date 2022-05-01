#include <iostream>
using namespace std;

int main()
{
    string minimum;
    string str;
    cin >> minimum;
    for (int i = 0; i < 2; i++)
    {
        cin >> str;
        if (str < minimum)
            minimum = str;
    }
    cout << minimum << endl;

    return 0;
}