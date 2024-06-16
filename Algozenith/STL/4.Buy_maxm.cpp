#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++)
    {
        m -= a[i];
        if (m >= 0)
            ans++;
        else
            break;
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
    {
        solve();
    }
}