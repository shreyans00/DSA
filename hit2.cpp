#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n, m;
vector<vector<int>> g;
vector<int> col;
bool f = 0;

void dfs(int node)
{
    if (f)
        return;
    col[node] = 1;
    for (auto v : g[node])
    {
        if (col[v] == 0)
            dfs(v);
        else if (col[v] == 1)
        {
            f = 1;
            return;
        }
    }
    col[node] = 2;
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    col.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 0)
            dfs(i);
    }
    if (f)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}