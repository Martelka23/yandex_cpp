#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool f(int x)
{
    return x % 2;
}

int main()
{
    vector<int> vec;
    auto vector_begin = begin(vec);
    auto vector_end = end(vec);

    string str;
    auto string_begin = begin(str);
    auto string_end = end(str);

    set<int> s;
    auto set_begin = begin(s);
    auto set_end = end(s);

    auto res = is_heap(string_begin, string_end);
    auto res = is_heap(set_begin, set_end);
    
    return 0;
}