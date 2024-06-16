#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n, m;
vector<bool> vis;
vector<bool> dfsvis;
vector<pair<int, int>> cy;

bool detect(int cur, int par, vector<int> g[])
{
    vis[cur] = 1;
    dfsvis[cur] = 1;
    for (auto x : g[cur])
    {
        if (!vis[x])
        {
            if (detect(x, cur, g))
                return true;
        }
        else if (dfsvis[x])
        {
            cy.push_back({x, cur});
            return true;
        }
    }
    dfsvis[cur] = 0;
    return false;
}

vector<int> res;
int gsm = 1e9;

void find(int s, int e, vector<int> g[], int ad, vector<int> val)
{
    if (s == e)
    {
        val.push_back(e);
        if (ad < gsm)
        {
            gsm = ad;
            res = val;
        }
        return;
    }
    vis[s] = 1;
    for (auto x : g[s])
    {
        if (!vis[x])
        {
            val.push_back(s);
            find(x, e, g, ad + s, val);
        }
    }
}

void solve()
{
    cin >> n >> m;
    vis.clear();
    vis.resize(n + 1, 0);
    vis.resize(n + 1, 0);
    vector<int> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            bool det = detect(i, -1, g);
            if (det)
            {
                cout << -1 << endl;
                return;
            }
        }
    }
    vis.clear();
    vis.resize(n + 1, 0);
    for (int i = 0; i < cy.size(); i++)
    {
        int ans = 1e9;
        vector<int> val;
        find(cy[i].first, cy[i].second, g, 0, val);
        cout << cy[i].first << " " << cy[i].second << endl;
    }
    if (gsm == 1e9)
    {
        cout << -1 << endl;
        return;
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while (_t--)
        solve();
    return 0;
}