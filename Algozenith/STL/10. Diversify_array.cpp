#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int fact(int n)
{
    if (n == 0 or n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

void solve()
{
    int n;
    ll k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> st;
    int totFreq = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.count(a[i]))
            totFreq++;
        else
            st.insert(a[i]);
    }
    ll comb = fact(n) / (fact(n - 2) * 2);
    ll ans;
    if (totFreq > k)
        ans = comb - totFreq + k;
    else
        ans = comb;
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
    {
        solve();
    }
}