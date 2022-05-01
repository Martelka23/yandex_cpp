#include <iostream>
using namespace std;
 int Factorial(int x)
 {
    int result = 1;
    if (x <= 1)
        return 1;
    for (int i = 2; i <= x; i++)
        result *= i;
    return result;
 }