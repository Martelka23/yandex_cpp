#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(begin(v), end(v), [](int x, int y) {return abs(x) < abs(y);});
    for (const int& x : v)
        cout << x << " ";
    return 0;
}