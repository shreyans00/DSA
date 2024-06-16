#include <bits/stdc++.h>
using namespace std;

void parantheses(int n, vector<string> &v, string op, int open, int closed)
{
    if (open < closed)
        return;
    if (n == 0)
    {
        v.push_back(op);
        return;
    }
    string op1, op2;
    op1 = op + '(';
    op2 = op + ')';
    parantheses(n - 1, v, op1, open + 1, closed);
    parantheses(n - 1, v, op2, open, closed + 1);
    return;
}

void solve()
{
    int n;
    cin >> n;
    vector<string> v;
    parantheses(n, v, "", 0, 0);
    for (auto x : v)
        cout << x << "\n";
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