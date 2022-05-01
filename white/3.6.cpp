#include <iostream>
#include <string>
using namespace std;

class ReversibleString
{
public:
    string str;
    ReversibleString()
    {
        str = "";
    }
    ReversibleString(const string& s)
    {
        str = s;
    }
    void Reverse()
    {
        string answer = "";
        for (int i = (int)str.size() - 1; i >= 0; i--)
            answer += str[i];
        str = answer;
    }
    string ToString() const
    {
        return str;
    }
};

// int main() {
//   ReversibleString s("live");
//   s.Reverse();
//   cout << s.ToString() << endl;
  
//   s.Reverse();
//   const ReversibleString& s_ref = s;
//   string tmp = s_ref.ToString();
//   cout << tmp << endl;
  
//   ReversibleString empty;
//   cout << '"' << empty.ToString() << '"' << endl;
  
//   return 0;
// }