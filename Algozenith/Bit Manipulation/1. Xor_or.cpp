// Unable to solve myself
// Very nice question

#include <bits./stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n;
    int presum[n][31];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 31; j++)
        {
            presum[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int cnt = 0;
        while (a > 0)
        {
            presum[i][cnt] = a % 2; // store binary form of each number row-wise
            a /= 2;
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 31; j++)
            presum[i][j] += presum[i - 1][j]; // prefixsum values of each column
    }
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        double tot = (r - l + 1.0) / 2;
        long long x1 = 0, x2 = 0, x3 = 0;
        for (int i = 0; i < 31; i++)
        {
            int p = presum[r][i] - presum[l - 1][i];
            if (p < tot)
                x1 += (1LL << i); // 2^i
            if (p != (r - l + 1)) // ek bhi 0 hai to 2^i se multiply kr do, us jagah 1 bit lga do
                x2 += (1LL << i);
            if (p) // ek bhi 1 hai to 2^i se multiply kr do, us jagah 1 bit lga do
                x3 += (1LL << i);
        }
        long long ans = x1 + x2 + x3;
        cout << ans << endl;
    }
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