// No need to solve again

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    cout << ((n * n - 3 * n) / 2) % mod << endl;
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