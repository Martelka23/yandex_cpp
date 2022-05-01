#include <iostream>
#include <map>
using namespace std;

template <typename key, typename value>
value& GetRefStrict(map<key, value>& d, const key k)
{
    if (d.count(k))
        return d.at(k);
    else
        throw runtime_error("error");
}

int main()
{
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 0);
    item = "newvalue";
    cout << m[0] << endl; // выведет newvalue
    return 0;
}