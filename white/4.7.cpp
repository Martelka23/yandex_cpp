#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int m, n;
    ifstream input("input.txt");
    int num;
    input >> n >> m;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(10);
            input >> num;
            input.ignore(1);
            cout << num;
            if (j != m - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}