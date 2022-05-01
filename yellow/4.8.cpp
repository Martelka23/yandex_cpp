#include <algorithm>
#include <iostream>
#include <math.h>
#include <set>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers, int border)
{
    auto lb = numbers.lower_bound(border);
    if (lb == numbers.begin())
        return lb;

    auto previous = prev(lb);
    if (lb == numbers.end())
        return previous;

    return (abs(*lb - border) < abs(*previous - border)) ? lb : previous;
    
    
}

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
