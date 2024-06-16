// Solve once

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int mod = 1e9 + 7;

ll fact(int n)
{
    ll fac = 1;
    for (int i = 2; i <= n; i++)
    {
        fac *= i;
    }
    return fac;
}

ll C(int n, int r)
{
    return fact(n) / (fact(n - r) * fact(r));
}

void solve()
{
    int n;
    cin >> n;
    ll ans = C(n, 4) % mod;
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