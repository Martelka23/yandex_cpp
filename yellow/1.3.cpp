#include <iostream>
using namespace std;

int main()
{
    unsigned n;
    uint64_t sum = 0;
    int r;
    cin >> n >> r;
    for (unsigned i = 0; i < n; i++)
    {
        int64_t w, h, d;
        cin >> w >> h >> d;
        sum += w * h * d * r;
    }
    cout << sum << endl;

    return 0;
}