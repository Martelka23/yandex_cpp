#include <iostream>
#include <vector>
using namespace std;

bool IsPalindrom(string s) {
    for (size_t i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

vector<string> PalindromFilter(vector<string> old_vector, size_t minLength)
{
    vector<string> new_vector;
    for (auto x : old_vector)
    {
        if (IsPalindrom(x) && x.size() >= minLength)
            new_vector.push_back(x);
    }
    return new_vector;
}