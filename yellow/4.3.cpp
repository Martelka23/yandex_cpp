#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> words;
    string::const_iterator it = begin(s);
    string::const_iterator start_word = it;
    while (it != end(s))
    {
        if (*it == ' ')
        {
            words.push_back({start_word, it});
            ++it;
            start_word = it;
        }
        ++it;
    }
    words.push_back({start_word, it});
    
    return words;

}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}
