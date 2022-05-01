#include <iostream>
#include <vector>
#include <set>

using namespace std;

template <typename T>
void RemoveDuplicates(vector<T>& nums)
{
    set<T> s;
    for (T& x : nums)
        s.insert(x);
    nums.assign(begin(s), end(s));
}

int main() {
  vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
  RemoveDuplicates(v1);
  for (int x : v1) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
  RemoveDuplicates(v2);
  for (const string& s : v2) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
