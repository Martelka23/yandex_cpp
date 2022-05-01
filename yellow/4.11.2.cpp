#include <iostream>
#include <string>
#include <deque>

using namespace std;

void str_to_deq(const string& s, deque<char>& d)
{
    for (const char& x : s)
        d.push_back(x);
}

string deq_to_str(const deque<char>& d)
{
    string s;
    for (const char& x : d)
        s += x;

    return s;
}

int main()
{
    int n;
    string first;
    deque<char> answer;
    cin >> first;
    str_to_deq(first, answer);
    cin >> n;
    cin.ignore(1);
    char prev = '*';
    for (int i = 0; i < n; i++)
    {
        string another;
        getline(cin, another);
        if ((another[0] == '*' || another[0] == '/') && (prev == '+' || prev == '-'))
        {
            answer.push_front('(');
            answer.push_back(')');
        }
        answer.push_back(' ');
        str_to_deq(another, answer);
        prev = another[0];
    }
    cout << deq_to_str(answer);

    return 0;
}