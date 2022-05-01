#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

long int gcd(long int a, long int b)
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

// Наименьшее общее кратное
long int NOK(long int a, long int b)
{ 
    return a * b / gcd(a, b); 
}

class Rational {
public:
    Rational()
    {
        num = 0;
        denom = 1;
    }
    Rational(long int numerator, long int denominator)
    {
        if (numerator == 0)
        {
            num = 0;
            denom = 1;
        } else if (numerator * denominator > 0)
        {
            long int nod = gcd(abs(numerator), abs(denominator));
            num = abs(numerator) / nod;
            denom = abs(denominator) / nod;
        } else if (numerator * denominator < 0)
        {
            long int nod = gcd(abs(numerator), abs(denominator));
            num = - abs(numerator) / nod;
            denom = abs(denominator) / nod;
        }
    }

    long int Numerator() const
    {
        return num;
    }
    long int Denominator() const
    {
        return denom;
    }

private:
    long int num;
    long int denom;
};

Rational operator+(Rational a, Rational b)
{
    int nok = NOK(a.Denominator(), b.Denominator());
    int x = a.Numerator() * nok / a.Denominator() + b.Numerator() * nok / b.Denominator();
    Rational answer(x, nok);
    return answer;
}

Rational operator-(Rational a, Rational b)
{
    int nok = NOK(a.Denominator(), b.Denominator());
    int x = a.Numerator() * nok / a.Denominator() - b.Numerator() * nok / b.Denominator();
    Rational answer(x, nok);
    return answer;
}

Rational operator*(Rational a, Rational b)
{
    long int x = a.Numerator() * b.Numerator();
    long int y = a.Denominator() * b.Denominator();
    Rational answer(x, y);
    return answer;
}

Rational operator/(Rational a, Rational b)
{
    long int x = a.Numerator() * b.Denominator();
    long int y = a.Denominator() * b.Numerator();
    Rational answer(x, y);
    return answer;
}

bool operator==(Rational a, Rational b)
{
    int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() == b.Numerator() * nok / b.Denominator();
}

int main() {
    {
        Rational a(9, 3);
        Rational b(3, 9);
        Rational c = a * b;
        bool equal = c == Rational(1, 1);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}