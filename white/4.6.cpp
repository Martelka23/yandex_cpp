#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    ifstream input("input.txt");
    double line;
    while (input >> line)
    {
        cout << fixed << setprecision(3);
        cout << line << endl;
    }
    return 0;
}