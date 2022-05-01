#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    double sum = 0;
    cin >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        sum += x;
        temp[i] = x;
    }

    double middle = sum / n;
    int count = 0;
    vector<int> high_temp;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] > middle)
        {
            high_temp.push_back(i);
            count++;
        }
    }
    
    cout << count << endl;
    for (int x : high_temp)
        cout << x << " ";

    return 0;
}