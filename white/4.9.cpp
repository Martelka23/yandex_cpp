#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 1 && b == 1)
        return 1;
    while (a != b)
    {
        if (a % b == 0)
            return b;
        if (b % a == 0)
            return a;
        if (a > b)
            a -= a / b * b;
        else
            b -= b / a * a;
    }
    return a;
}

class Rational {
public:
    Rational()
    {
        num = 0;
        denom = 1;
    }
    Rational(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            num = 0;
            denom = 1;
        } else if (numerator * denominator > 0)
        {
            int nod = gcd(abs(numerator), abs(denominator));
            num = abs(numerator) / nod;
            denom = abs(denominator) / nod;
        } else if (numerator * denominator < 0)
        {
            int nod = gcd(abs(numerator), abs(denominator));
            num = - abs(numerator) / nod;
            denom = abs(denominator) / nod;
        }
    }

    int Numerator() const
    {
        return num;
    }
    int Denominator() const
    {
        return denom;
    }

private:
    int num;
    int denom;
};

int main() {
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}