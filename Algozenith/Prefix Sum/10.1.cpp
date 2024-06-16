#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

void solve()
{
    int n, q, l, r;
    cin >> n >> q;
    int a[n];
    cin >> a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        if (l == 1)
        {
            if (a[r - 1] > 0)
                cout << a[r - 1] % mod << endl;
            else
                cout << mod + a[r - 1] % mod << endl;
        }
        else
        {
            int ans = a[r - 1] - a[l - 2];
            if (ans > 0)
                cout << ans % mod << endl;
            else
                cout << mod + ans % mod << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}