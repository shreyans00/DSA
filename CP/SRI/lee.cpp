#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n;
vector<vector<int>> g;
vector<bool> vis;
int ans;

void dfs(int cur, int nvis, int cursm)
{
    if (nvis == n - 1)
    {
        if (g[cur][0] != 0)
            ans = min(ans, cursm + g[cur][0]);
        return;
    }
    vis[cur] = 1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && g[cur][i] != 0)
        {
            dfs(i, nvis + 1, cursm + g[cur][i]);
        }
    }
    vis[cur] = 0;
}

void solve()
{
    cin >> n;
    g.clear();
    g.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    }
    vis.clear();
    vis.resize(n, 0);
    vis[0] = 1;
    ans = 1e9;
    dfs(0, 0, 0);
    if (ans == 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
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