#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class SortedStrings 
{
public:
    void AddString(const string& s) 
    {
        strings.push_back(s);
    }
    vector<string> GetSortedStrings() 
    {
        // получить набор из всех добавленных строк в отсортированном порядке
        sort(begin(strings), end(strings));
        return strings;
    }
private:
    vector<string> strings;
};