#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

void add(map<string, set<string>>& words)
{
    string word1, word2;
    cin >> word1 >> word2;
    words[word1].insert(word2);
    words[word2].insert(word1);
}

void count(map<string, set<string>>& words)
{
    string word;
    cin >> word;
    cout << words[word].size() << endl;
}

void check(map<string, set<string>>& words)
{
    string word1, word2;
    cin >> word1 >> word2;
    if (words[word1].count(word2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main()
{
    map<string, set<string>> words;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "ADD")
        {
            add(words);
        } else if (command == "COUNT")
        {
            count(words);
        } else if (command == "CHECK")
        {
            check(words);
        }
    }

    return 0;
}