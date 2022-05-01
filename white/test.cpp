#include <iostream>
#include <string>
#include <stdlib.h>
#include <format>
using namespace std;

int main()
{
    string s = format("test%dtest", 5);
    return 0;
}