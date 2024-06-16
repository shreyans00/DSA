#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1e9 + 7;

void solve()
{
    int n, q, k;
    cin >> n >> q >> k;
    int a[n + 1], b[n + 1];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    while (q--)
    {
        int A, l, r;
        cin >> A >> l >> r;
        // arr[i] = A.k^(i-L)
        a[l] += A;
        if (r != n)
            a[r + 1] -= A * pow(k, r - l + 1);
    }
    for (int i = 1; i < n + 1; i++)
        a[i] += a[i - 1] * k;

    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}
