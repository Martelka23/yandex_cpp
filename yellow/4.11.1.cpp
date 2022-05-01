#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string answer;
    cin >> answer;
    cin >> n;
    cin.ignore(1);
    for (int i = 0; i < n; i++)
    {
        string another;
        getline(cin, another);
        answer.insert(begin(answer), '(');
        answer += ") " + another;
    }
    cout << answer;

    return 0;
}