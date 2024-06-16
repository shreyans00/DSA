#include <bits./stdc++.h>
using namespace std;

bool detectCycle(int curr, int prev, vector<int> adj[], bool vis[])
{
    vis[curr] = 1;
    for (auto it : adj[curr])
    {
        if (!vis[it])
        {
            if (detectCycle(it, curr, adj, vis))
                return true;
        }
        else if (it != prev)
            return true;
    }
    return false;
}

bool dfs_cycle(int n, vector<int> adj[])
{
    bool vis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int prev = -1;
            if (detectCycle(n, prev, adj, vis))
                return true;
        }
    }
    return false;
}

int main()
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
    if (dfs_cycle(n, adj))
        cout << "cycle exist";
    else
        cout << "cycle don't exist in any of the component";
}

// #include <bits/stdc++.h>
// using namespace std;
// #define inf 1e9

// int v, e;
// vector<int> adj[101];
// vector<int> vis(101, 0);
// vector<int> seq;
// vector<int> par(101, -1);

// bool dfss(int x)
// {
//     vis[x] = 1;
//     seq.push_back(x);
//     for (auto y : adj[x])
//     {
//         par[y] = x;
//         if (!vis[y])
//         {
//             if (dfss(y))
//                 return 1;
//         }
//         else
//         {
//             if (par[x] != y)
//                 return 1;
//         }
//     }
//     return 0;
// }

// int main()
// {
//     cin >> v >> e;

//     for (int i = 0; i < v; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }
//     for (int i = 1; i <= v; i++)
//     {
//         if (!vis[i])
//         {
//             if (dfss(i))
//             {
//                 cout << "yes\n";
//                 return 0;
//             }
//         }
//     }
//     cout << "no\n";
//     return 0;
// }