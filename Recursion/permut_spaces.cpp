#include <bits/stdc++.h>
using namespace std;

void permutSpaces(string ip, string op)
{
    if (ip.size() == 0)
    {
        cout << op << "\n";
        return;
    }
    string op1, op2;
    op1 = op + ip[0];
    op2 = op + "_" + ip[0];
    ip.erase(ip.begin() + 0);
    permutSpaces(ip, op1);
    permutSpaces(ip, op2);
    return;
}

void solve()
{
    string ip, op = "";
    cin >> ip;
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    permutSpaces(ip, op);
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