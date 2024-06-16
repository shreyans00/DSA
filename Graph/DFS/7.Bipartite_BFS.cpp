#include <bits/stdc++.h>
using namespace std;

bool bipartite(int n, vector<int> adj[])
{
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (auto it : adj[curr])
                {
                    if (color[it] == -1)
                    {
                        q.push(it);
                        color[it] = 1 - color[curr]; // adjacent ka color alg kr denge
                    }
                    else if (color[it] == color[curr]) // adjacent nodes ka color same ho gya
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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
    if (bipartite(n, adj))
        cout << "Bipartite";
    else
        cout << "Not bipartite";
}
