#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int64_t sum = 0;
    vector<int> all;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        sum += temp;
        all.push_back(temp);
    }
    int64_t middle = sum / n;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (all[i] > middle)
            ans.push_back(i);
    cout << ans.size() << endl;
    for (const int& x : ans)
        cout << x << " ";
    return 0;
}