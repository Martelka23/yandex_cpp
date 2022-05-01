#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> strs;
    for (const auto x : m)
        strs.insert(x.second);
    
    return strs;
}