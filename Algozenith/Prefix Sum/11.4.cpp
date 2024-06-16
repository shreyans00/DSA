#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n + 1], b[n + 1];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    while (q--)
    {
        int A, d, l, r;
        cin >> A >> d >> l >> r;
        // arr[i] = a-l*d + i*d
        a[l] += A - l * d;
        b[l] += d;
        if (r != n)
        {
            a[r + 1] -= A - l * d;
            b[r + 1] -= d;
        }
    }

    for (int i = 1; i < n; i++)
    {
        a[i + 1] += a[i];
        b[i + 1] += b[i];
    }
    for (int i = 1; i <= n; i++)
        a[i] = a[i] + i * b[i];
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
