#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
    vector<int> n;
    for (int i = v.size() - 1; i >= 0; i--)
        n.push_back(v[i]);
    return n;
}