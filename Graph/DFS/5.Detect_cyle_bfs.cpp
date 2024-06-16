#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int n, vector<int> adj[])
{
    bool vis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1}); // {node, prev_node}, since 1st node of the component has no prev node, so -1
            vis[i] = 1;
            while (!q.empty())
            {
                int curr = q.front().first;
                int prev = q.front().second;
                q.pop();
                for (auto it : adj[curr])
                {
                    if (!vis[it])
                    {
                        q.push({it, curr});
                        vis[it] = 1;
                    }
                    else if (it != prev) // jo non-visited node hai ya to wo prev hoga ya to cycle bna dega
                        return 0;
                }
            }
        }
    }
    return 1;
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
    if (!detectCycle(n, adj))
        cout << "cycle exist";
    else
        cout << "cycle don't exist in any of the component";
}
