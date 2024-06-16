#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

long long fact(int n)
{
    int fac = 1;
    for (int i = 2; i <= n; i++)
    {
        fac *= i;
    }
    return fac;
}

long long int C(int n, int r)
{
    return fact(n) / (fact(n - r) * fact(r));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    long long int tot = C(n + m, n) % mod;
    // long long int tot = (m - 1) * 2 + (n - 1) + (n - 1) * 2 + (m - 1);
    cout << tot % mod << endl;
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