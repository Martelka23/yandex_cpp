#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Learner {
 private:
  set<string> dict;

 public:
  int Learn(const vector<string>& words) {
    int count_of_words_before = dict.size();
    for (const auto& word : words)
      dict.insert(word);
    
    return dict.size() - count_of_words_before;
  }

  vector<string> KnownWords() { 
    vector<string> dict_vector;
    for (const string& word : dict)
      dict_vector.push_back(word);
    return dict_vector;
  }
};
