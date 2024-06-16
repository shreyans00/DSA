#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve()
{
    int n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
    {
        int m;
        cin >> m;
        qu[i] = m;
    }
    // Method 1
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    while (q--)
    {
        int m;
        cin >> m;
        int ans = -1;
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] <= m)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans + 1 << "\n";
    }

    // Method 2
    // ll b[n], qu[q], sum = 0;
    // sort(a, a + n);
    // for (int i = 0; i < n; i++)
    // {
    //     sum += a[i];
    //     b[i] = sum;
    // }
    // for (int i = 0; i < q; i++)
    //     cout << upper_bound(b, b + n, qu[i]) - b << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}