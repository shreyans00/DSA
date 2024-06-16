#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve()
{
    int n;
    cin >> n;
    multiset<int> s;
    for (int i = 1, j = 0; j < n; j++)
    {
        int val;
        cin >> val;

        if (val > i)
            s.insert(val);
        while (!s.empty() and *(s.begin()) <= i)
            s.erase(s.begin());
        if (s.size() > i)
            i++;
        cout << i << " ";
    }
    cout << "\n";
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