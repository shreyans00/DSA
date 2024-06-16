#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    map<long long int, int> mp;
    int i = 1;
    while (n--) // O(n log n)
    {
        long long int eleA;
        cin >> eleA;
        mp.insert({eleA, i++}); // O(log n)
    }
    while (m--)
    {
        long long int eleB;
        cin >> eleB;
        if (mp.find(eleB) != mp.end())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
            mp.insert({eleB, i++});
        }
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
    {
        solve();
    }
}