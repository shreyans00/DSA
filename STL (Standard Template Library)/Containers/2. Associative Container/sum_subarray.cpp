// We use prefix sum concept

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> arr, prefix;

void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    prefix.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        prefix[i] = arr[i];
        if (i)
            prefix[i] += prefix[i - 1];
    }
    ll sum = 0;
    cin >> sum;
    ll ans = 0;
    map<ll, ll> mp;
    mp[0]++;
    for (int j = 0; j < n; j++)
    {
        ans += mp[prefix[j] - sum];
        mp[prefix[j]]++;
    }
    cout << ans << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
}