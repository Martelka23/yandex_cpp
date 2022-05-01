#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <set>
#include <map>
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
        Update(numerator, denominator);
    }
    void Update(long int numerator, long int denominator)
    {
        if (denominator == 0)
            throw invalid_argument("Invalid argument");
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
    long int nok = NOK(a.Denominator(), b.Denominator());
    long int x = a.Numerator() * nok / a.Denominator() + b.Numerator() * nok / b.Denominator();
    Rational answer(x, nok);
    return answer;
}

Rational operator-(Rational a, Rational b)
{
    long int nok = NOK(a.Denominator(), b.Denominator());
    long int x = a.Numerator() * nok / a.Denominator() - b.Numerator() * nok / b.Denominator();
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
    if (b.Numerator() == 0)
        throw domain_error("Zero!");
    long int x = a.Numerator() * b.Denominator();
    long int y = a.Denominator() * b.Numerator();
    Rational answer(x, y);
    return answer;
}

Rational operator>>(istream& stream, Rational& s)
{
    long int x, y;
    stream >> x;
    if (stream.peek() != '/')
        throw runtime_error("invalid argument");
    stream.ignore(1);
    stream >> y;
    if (y < 0)
        throw runtime_error("invalid argument");
    Rational a(x, y);

    char op;
    stream >> op;

    long int x1, y1;
    stream >> x1;
    if (x1 == 0)
        throw runtime_error("Division by zero");
    if (stream.peek() != '/')
        throw runtime_error("invalid argument");
    stream.ignore(1);
    stream >> y1;
    if (y1 < 0)
        throw runtime_error("invalid argument");
    Rational b(x1, y1);

    if (op == '+')
        s = a + b;
    else if (op == '-')
        s = a - b;
    else if (op == '*')
        s = a * b;
    else if (op == '/')
        s = a / b;

    return s;
}

ostream& operator<<(ostream& stream, const Rational& a)
{
    stream << a.Numerator() << "/" << a.Denominator();
    return stream;
}

bool operator==(Rational a, Rational b)
{
    long int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() == b.Numerator() * nok / b.Denominator();
}

bool operator<(Rational a, Rational b)
{
    long int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() < b.Numerator() * nok / b.Denominator();
}

bool operator>(Rational a, Rational b)
{
    long int nok = NOK(a.Denominator(), b.Denominator());
    return a.Numerator() * nok / a.Denominator() > b.Numerator() * nok / b.Denominator();
}

int main() {
    Rational s;
    try
    {
        cin >> s;
        cout << s << endl;
    } catch (exception& ex)
    {
        cout << ex.what() << endl;
        return 1;
    }
    
    return 0;
}