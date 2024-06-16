#include <bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y, int n)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int func(int n, int x, int y, int xx, int yy)
{
    int ans = 0;
    while (isvalid(x, y, n))
    {
        ans++;
        x += xx;
        y += yy;
    }
    return ans;
}

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int ans = 0;
    ans += func(n, x - 1, y, -1, 0);
    ans += func(n, x + 1, y, 1, 0);
    ans += func(n, x, y - 1, 0, -1);
    ans += func(n, x, y + 1, 0, 1);
    ans += func(n, x - 1, y - 1, -1, -1);
    ans += func(n, x - 1, y + 1, -1, 1);
    ans += func(n, x + 1, y - 1, 1, -1);
    ans += func(n, x + 1, y + 1, 1, 1);
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
        solve();
    return 0;
}

/*
    Method 2

void main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int st = 2 * n - 2;
    int diag = min(x - 1, y - 1) + min(x - 1, n - y) + min(y - 1, n - x) + min(n - x, n - y);
    cout << st + diag << endl;
}
*/
