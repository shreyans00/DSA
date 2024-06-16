#include <bits./stdc++.h>
using namespace std;

bool cycle_dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (cycle_dfs(it, adj, vis, dfsvis))
                return true;
        }
        else if (dfsvis[it])
            return true;
    }
    dfsvis[node] = 0;
    return false;
}

bool cycle(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    vector<int> dfsvis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (cycle_dfs(i, adj, vis, dfsvis))
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int main()
{
    int n = 6;
    vector<int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);

    if (cycle(n, adj))
        cout << "cycle";
    else
        cout << "no cycle";
}