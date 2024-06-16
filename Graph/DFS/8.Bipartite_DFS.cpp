#include <bits/stdc++.h>
using namespace std;

bool bipartite_dfs(int node, vector<int> adj[], vector<int> &color)
{
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!bipartite_dfs(it, adj, color))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}

bool bipartite(int n, vector<int> adj[])
{
    vector<int> color(n, -1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartite_dfs(i, adj, color))
                return false;
        }
    }
    return true; // 2 hi color kafi hai
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (bipartite(n, adj))
        cout << "Bipartite";
    else
        cout << "Not bipartite";
}
