#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++; // everytime node get visited, timer increased by 1, tin to yhi rhega, low change ho skta hai
    for (auto it : adj[node])
    {
        if (it == parent) // if wo adj(it), node ka parent hai to wahan nhi jana hai, dusre adj nodes ko check kro
            continue;

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);   // we update low[node]
            if (low[it] > tin[node])               // bridge condition
                cout << node << " " << it << endl; // yahan se bridges ko print kr rhe hai
        }
        else // agar wo pehle se visited hai
            low[node] = min(low[node], tin[it]);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1); // insertion time found during dfs
    vector<int> low(n, -1); // sbse lowest time of insetion kisi bhi adjacent node se aaye to
    vector<int> vis(n, 0);  // normal dfs ke liye
    int timer = 0;          // initial timer
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, -1, vis, tin, low, timer, adj); // dfs call
    }
}