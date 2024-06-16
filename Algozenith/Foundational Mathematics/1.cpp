// unable to solve myself

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c % gcd(a, b) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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