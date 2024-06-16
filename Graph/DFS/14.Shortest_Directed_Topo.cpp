#include <bits./stdc++.h>
using namespace std;

void topoSortdfs(int curr, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[curr] = 1;
    for (auto it : adj[curr])
    {
        if (!vis[it.first])
            topoSortdfs(it.first, adj, vis, st);
    }
    st.push(curr);
}

stack<int> topoSort(int n, vector<pair<int, int>> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            topoSortdfs(i, adj, vis, st);
    }
    return st;
}

vector<int> shortestDist(int src, int n, vector<pair<int, int>> adj[])
{
    stack<int> st = topoSort(n, adj);
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dist[node] != INT_MAX) // if the node has been reached previously
        {
            for (auto it : adj[node])
            {
                int d = it.second + dist[node];
                if (d < dist[it.first])
                    dist[it.first] = d;
            }
        }
    }
    return dist;
}

void addedge(vector<pair<int, int>> adj[], int x, int y, int w)
{
    adj[x].push_back({y, w});
}

int main()
{
    int n = 7;
    vector<pair<int, int>> adj[n];
    addedge(adj, 0, 1, 2);
    addedge(adj, 0, 4, 1);
    addedge(adj, 1, 3, 2);
    addedge(adj, 2, 3, 6);
    addedge(adj, 5, 3, 1);
    addedge(adj, 4, 2, 2);
    addedge(adj, 4, 5, 4);

    vector<int> v = shortestDist(0, n, adj);
    for (auto x : v)
    {
        if (x == INT_MAX)
            cout << "Infinity ";
        else
            cout << x << " ";
    }
    cout << endl;
}