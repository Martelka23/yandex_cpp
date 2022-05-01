#include <iostream>
using namespace std;

class Incognizable
{
public:
    Incognizable()
    {
        x = 1;
        y = 1;
    }
    Incognizable(int a)
    {
        x = a;
        y = 1;
    }
    Incognizable(int a, int b)
    {
        x = a;
        y = b;
    }
private:
    int x, y;
};