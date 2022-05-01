#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
    typename set<T>::iterator it = find_if(begin(elements), end(elements), [border](const T& x) {return x > border;});
    if (it != end(elements) && *it == border)
        ++it;
    vector<T> answer = {it, end(elements)};
    return answer;
}

int main() {
    for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
        cout << x << " ";
    }
    cout << endl;

    string to_find = "Python";
    cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
    return 0;
}
