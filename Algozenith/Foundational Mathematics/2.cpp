#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int gcdd = gcd(a[0], a[1]);
    for (int i = 1; i < n - 1; i++)
    {
        if (gcd(a[i], a[i + 1]) == 1)
        {
            cout << "No" << endl;
            return;
        }
        else if (gcdd >= gcd(a[i], a[i + 1]) && gcdd % gcd(a[i], a[i + 1]) == 0)
        {
            gcdd = gcd(a[i], a[i + 1]);
        }
        else if (gcdd < gcd(a[i], a[i + 1]) && gcd(a[i], a[i + 1]) % gcdd == 0)
        {
            continue;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
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