#include <bits/stdc++.h>
using namespace std;

void dfsrecur(int node, vector<int> adj[], vector<bool> &vis, vector<int> &dfsSeq)
// recursive function for going in depth
{
    dfsSeq.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            dfsrecur(it, adj, vis, dfsSeq);
        // apne adj node ke andr jake mark visited & dfsSeq mai push krta jayega
    }
}

vector<int> dfs(int n, vector<int> adj[])
{
    vector<bool> vis(n + 1, 0); // array to mark a node is visited or not
    vector<int> dfsSeq;         // store the final dfs array

    for (int i = 1; i <= n; i++) // travel all components, if already marked, do i++
    {
        if (!vis[i]) // if not visited, andr jao
            dfsrecur(i, adj, vis, dfsSeq);
    }
    return dfsSeq;
}

signed main()
{
    int n, m; // n-no. of nodes,  m-no. of edges
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> v = dfs(n, adj);
    for (auto x : v)
        cout << x << " ";
}
