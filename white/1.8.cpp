#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    while (a != b)
    {
        if (a % b == 0)
        {
            cout << b << endl;
            return 0;
        }
        if (b % a == 0)
        {
            cout << a << endl;
            return 0;
        }
        if (a > b)
            a -= a / b * b;
        else
            b -= b / a * a;
    }
    cout << a << endl;

    return 0;
}