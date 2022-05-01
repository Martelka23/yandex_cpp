#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    if (a != 0)
    {
        double d = b * b - 4 * a * c;
        if (d < 0)
            return 0;
        else
            d = sqrt(d);
        double x1 = (-b - d) / (2 * a), x2 = (-b + d) / (2 * a);
        if (x1 != x2)
            cout << x1 << " " << x2 << endl;
        else
            cout << x1 << endl;
    }
    else
    {
        if (b != 0)
        {
            double x1 = -c / b;
            cout << x1 << endl;
        }
    }
    
    return 0;
}