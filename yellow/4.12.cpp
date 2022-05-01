#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// Составление строки
string MakeString(const vector<int>& a)
{
  string s = "";
  bool first = true;
  for (const int& x : a) {
    if (first) {
      s += to_string(x);
      first = false;
    }
    else 
      s += " " + to_string(x);
  }

  return s;
}

// Поменять местами
void swap(vector<int>& a, int i, int j)
{
  int s = a[i];
  a[i] = a[j];
  a[j] = s;
}

bool NextSet(vector<int>& a, int n)
{
  int j = n - 2;
  while (j != -1 && a[j] >= a[j + 1]) j--;
  if (j == -1)
    return false; // больше перестановок нет
  int k = n - 1;
  while (a[j] >= a[k]) k--;
  swap(a, j, k);
  int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
  while (l<r)
    swap(a, l++, r--);
  return true;
}

int main() 
{
  int n;
  vector<string> answer;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++)
    a[i] = i + 1;

  answer.push_back(MakeString(a));

  while (NextSet(a, n))
    answer.push_back(MakeString(a));

  sort(begin(answer), end(answer), [](const string& s1, const string& s2) { return s1 > s2; });

  for (const string& s : answer)
    cout << s << endl;

  return 0;
}