#include <iostream>
using namespace std;

int main()
{
    unsigned long int a, b;
    cin >> a >> b;
    if (b != 0)
    {
        cout << a / b << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    
    return 0;
}

