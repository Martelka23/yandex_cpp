#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <locale>
using namespace std;

bool comp(string a, string b)
{
    string x, y;
    for (const char& c : a)
        x += (char)tolower(c);
    for (const char& c : b)
        y += (char)tolower(c);
    return x < y;
}

int main()
{
    vector<string> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        words.push_back(word);
    }
    sort(begin(words), end(words), comp);
    for (const string& x : words)
        cout << x << " ";

    return 0;
}