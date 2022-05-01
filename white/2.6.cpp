#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v)
{
    vector<int> n = v;
    v.clear();
    for (int i = n.size() - 1; i >= 0; i--)
        v.push_back(n[i]);
}