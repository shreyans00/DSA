#include <bits./stdc++.h>
using namespace std;

bool func(int a[], int mid)
{
    if (a[mid] > a[mid - 1] && a[mid] > a[0])
        return 1;
    if (a[mid] > a[mid - 1] && a[mid] < a[0])
        return 0;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int lo = 0, hi = n - 1, ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1])
        {
            ans = mid;
            break;
        }
        else if (func(a, mid))
            lo = mid + 1;
        else if (!func(a, mid))
            hi = mid - 1;
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}