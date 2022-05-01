#include <iostream>
#include <algorithm>
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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}