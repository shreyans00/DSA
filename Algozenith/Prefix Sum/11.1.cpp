// Important question

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1e9 + 7;

void solve()
{
    ll n, q;
    cin >> n >> q;
    ll a[n + 1], b[n + 1];
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] * i % mod;
    }
    for (ll i = 1; i <= n; i++)
    {
        a[i + 1] += a[i];
        a[i] %= mod;
        b[i + 1] += b[i];
        b[i] %= mod;
    }

    while (q--)
    {
        int l, r;
        ll ans;
        cin >> l >> r;
        if (l == 1)
            ans = (b[r] + mod) % mod;
        else
            ans = ((b[r] - b[l - 1] + (1 - l) * (a[r] - a[l - 1])) % mod + mod) % mod;
        cout << ans << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}