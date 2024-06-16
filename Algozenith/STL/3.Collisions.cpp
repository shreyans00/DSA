#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    map<ll, ll> mp;
    while (n--)
    {
        ll x, u;
        cin >> x >> u;
        mp[x * u]++;
    }
    while (m--)
    {
        int y, v;
        cin >> y >> v;
        if (mp.count(y * v))
        {
            mp[y * v]--;
            ans++;
            if (mp[y * v] == 0)
            {
                mp.erase(y * v);
            }
        }
    }
    cout << ans << "\n";
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