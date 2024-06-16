#include <bits/stdc++.h>
using namespace std;

void insertfunc(vector<int> &v, int last)
{
    if (v.size() == 0 || last > v.back())
    {
        v.push_back(last);
        return;
    }
    int temp = v.back();
    v.pop_back();
    insertfunc(v, last);
    v.push_back(temp);
}

void sortit(vector<int> &v)
{
    if (v.size() == 1)
        return;
    int last = v.back();
    v.pop_back();
    sortit(v);
    insertfunc(v, last);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sortit(v);
    for (auto x : v)
        cout << x << " ";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}