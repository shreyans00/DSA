#include <bits./stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i <= b; i++)

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[] = {1, 5, 5, 5, 5, 63, 63, 626, 727, 256}, n = 6, x = 63;
    auto k = lower_bound(arr, arr + n, x) - arr;
    if (k < n && arr[k] == x)
    {
        cout << k << endl;
    }

    auto a = lower_bound(arr, arr + n, 5);
    auto b = upper_bound(arr, arr + n, 5);
    cout << b - a << "\n";

    auto r = equal_range(arr, arr + n, 5);
    cout << r.second - r.first << "\n";
}