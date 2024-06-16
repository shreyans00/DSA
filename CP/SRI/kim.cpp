#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n, ans;
pair<int, int> src, des;
vector<pair<int, int>> cus;
vector<bool> vis(n + 1, 0);

int dist(pair<int, int> a, pair<int, int> b)
{
    int x1 = a.first, x2 = b.first, y1 = a.second, y2 = b.second;
    return abs(x1 - x2) + abs(y1 - y2);
}

void dfs(pair<int, int> cur, int nvis, int cursm)
{
    if (nvis == n)
    {
        ans = min(ans, cursm + dist(cur, des));
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            dfs(cus[i], nvis + 1, cursm + dist(cur, cus[i]));
            vis[i] = 0;
        }
    }
}

void solve(int t)
{
    cin >> n >> src.first >> src.second >> des.first >> des.second;
    cus.clear();
    cus.resize(n);
    vis.clear();
    vis.resize(n, 0);
    for (int i = 0; i < n; i++)
        cin >> cus[i].first >> cus[i].second;
    ans = 1e9;
    dfs(src, 0, 0);
    cout << "# " << t << " " << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 10;
    // cin >> _t;
    for (int i = 1; i <= _t; i++)
        solve(i);
    return 0;
}