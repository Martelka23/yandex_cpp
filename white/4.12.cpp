#include <iostream>
#include <sstream>
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
    int x = a.Numerator() * b.Denominator();
    int y = a.Denominator() * b.Numerator();
    Rational answer(x, y);
    return answer;
}

istream& operator>>(istream& stream, Rational& a)
{
    if (!stream)
        return stream;
    int x, y;
    stream >> x;
    stream.ignore(1);
    if (!stream)
        return stream;
    stream >> y;
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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}