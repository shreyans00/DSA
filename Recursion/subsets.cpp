// Need to do same with slide modification when asked print all subsets, print powerset, print all subsequences
// substring: continuous part of a string
// Subsequences: may not be continuous but should be in same order
// Subsets: may not be continuous and may not be in same order

#include <bits/stdc++.h>
using namespace std;

void subsets(string ip, string op, set<string> &s)
{
    if (ip.size() == 0)
    {
        // cout << op << " ";
        s.insert(op);
        return;
    }
    string op1 = op, op2 = op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    subsets(ip, op1, s);
    subsets(ip, op2, s);
    return;
}

void solve()
{
    string ip;
    set<string> s;
    cin >> ip;
    subsets(ip, "", s);
    for (auto x : s)
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