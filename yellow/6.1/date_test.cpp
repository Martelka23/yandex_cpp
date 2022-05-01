#include "date.h"

#include <iostream>
#include <sstream>
using namespace std;

void TestParseCondition() {
    {
        istringstream is("2017-11-18");
        Date root = ParseDate(is);
        cout << root << endl;
    }
    {
        istringstream is("17-1-8");
        Date root = ParseDate(is);
        cout << root << endl;
    }
}

int main()
{
    TestParseCondition();

    return 0;
}