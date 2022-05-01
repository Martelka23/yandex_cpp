#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, count = 0;
    vector<int> answer;
    cin >> n;
    do
    {
        answer.push_back(n % 2);
        n /= 2;
        count++;
    } while (n > 0);
    for (auto i = count - 1; i >= 0; i--)
    {
        cout << answer[i];
    }
    
    return 0;
}