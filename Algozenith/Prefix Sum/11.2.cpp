// Nice question

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1e9 + 7;

void solve()
{
    int n, m, q, count = 0;
    cin >> n >> m >> q;
    pair<ll, int> a[n + 1];
    vector<ll> s;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a[i].first;
        a[i].second = 0;
    }

    for (int i = 1; i < m + 1; i++)
    {
        int l, r;
        cin >> l >> r;
        a[l].second++;
        if (r != n)
            a[r + 1].second--;
    }
    for (int i = 1; i < n + 1; i++)
        a[i + 1].second += a[i].second;
    for (int i = 1; i < n + 1; i++)
    {
        while (a[i].second--)
            s.push_back(a[i].first);
    }
    sort(s.begin(), s.end());

    while (q--)
    {
        int k;
        cin >> k;
        if (k > s.size())
            cout << -1 << " ";
        else
            cout << s[k - 1] << " ";
    }
    cout << endl;
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
