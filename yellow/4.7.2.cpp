#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// template <typename RandomIt>
// void Merge(RandomIt range1_begin, RandomIt range1_end, RandomIt range2_begin,
//     RandomIt range2_end, vector<typename RandomIt::value_type>& elems)
// {
//     RandomIt range_begin = begin(elems);
//     while (range1_begin != range1_end && range2_begin != range2_end)
//     {
//         if (*range1_begin <= *range2_begin)
//         {
//             range_begin = elems.erase(range_begin);
//             elems.insert(range_begin, *range1_begin);
//             ++range_begin;
//             ++range1_begin;
//         } else
//         {
//             range_begin = elems.erase(range_begin);
//             elems.insert(range_begin, *range2_begin);
//             ++range_begin;
//             ++range2_begin;
//         }
//     }
//     range_begin = elems.erase(range_begin, end(elems));
//     elems.insert(range_begin, range1_begin, range1_end);
//     elems.insert(range_begin, range2_begin, range2_end);
// }

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (range_end - range_begin >= 2)
    {
        vector<typename RandomIt::value_type> elems(range_begin, range_end);
        // vector<typename RandomIt::value_type> left_elems(range_begin, range_begin + (range_end - range_begin) / 3);
        // vector<typename RandomIt::value_type> middle_elems(range_begin + (range_end - range_begin) / 3, range_begin + (range_end - range_begin) / 3 * 2);
        // vector<typename RandomIt::value_type> right_elems(range_begin + (range_end - range_begin) / 3 * 2, range_end);
        RandomIt lb = begin(elems);
        RandomIt re = end(elems);
        RandomIt mb = lb + (re - lb) / 3;
        RandomIt rb = lb + (re - lb) / 3 * 2;
        MergeSort(lb, mb);
        MergeSort(mb, rb);
        MergeSort(rb, re);
        vector<typename RandomIt::value_type> tmp;
        merge(lb, mb, mb, rb, back_inserter(tmp));
        merge(begin(tmp), end(tmp), rb, re, range_begin);
        // copy(begin(elems), end(elems), range_begin);
    }
}


int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
