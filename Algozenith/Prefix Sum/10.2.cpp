// Good question (took much time)

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

void solve()
{
    int n, k, q, l, r, count = 0;
    cin >> n >> k >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        a[l - 1]++;
        a[r]--;
    }
    for (int i = 0; i < n - 1; i++)
        a[i + 1] += a[i];

    for (int i = 0; i < n; i++)
        a[i] = (a[i] >= k);

    int pre[n];
    pre[0] = a[0];
    for (int i = 0; i < n - 1; i++)
        pre[i + 1] = pre[i] + a[i + 1];

    while (q--)
    {
        int L, R;
        cin >> L >> R;
        cout << pre[R - 1] - pre[L - 2] << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}