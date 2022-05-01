#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom(string str)
{
    string new_str;
    for (int i = str.size() - 1; i >= 0; i--)
        new_str += str[i];
    return new_str == str;
}