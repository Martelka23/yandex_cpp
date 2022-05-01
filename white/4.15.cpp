#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <set>
#include <map>
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

// Наименьшее общее кратное
int NOK(int a, int b)
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
    Rational(int numerator, int denominator)
    {
        Update(numerator, denominator);
    }
    void Update(int numerator, int denominator)
    {
        if (denominator == 0)
            throw invalid_argument("Error");
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
    int x = a.Numerator() * b.Numerator();
    int y = a.Denominator() * b.Denominator();
    Rational answer(x, y);
    return answer;
}

Rational operator/(Rational a, Rational b)
{
    if (b.Numerator() == 0)
        throw domain_error("Zero!");
    int x = a.Numerator() * b.Denominator();
    int y = a.Denominator() * b.Numerator();
    Rational answer(x, y);
    return answer;
}

istream& operator>>(istream& stream, Rational& a)
{
    int x, y;
    stream >> x >> y;
    a.Update(x, y);
    return stream;
}

ostream& operator<<(ostream& stream, const Rational& a)
{
    stream << a.Numerator() << "/" << a.Denominator();
    return stream;
}

bool operator==(Rational a, Rational b)
{
    int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() == b.Numerator() * nok / b.Denominator();
}

bool operator<(Rational a, Rational b)
{
    int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() < b.Numerator() * nok / b.Denominator();
}

bool operator>(Rational a, Rational b)
{
    int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() > b.Numerator() * nok / b.Denominator();
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}