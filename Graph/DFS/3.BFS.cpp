#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> adj[])
{
    vector<int> vis(n + 1, 0); // array to mark a node is visited or not
    vector<int> bfsSeq;        // store the final bfs array

    for (int i = 1; i <= n; i++) // travel all components, if already marked, do i++
    {
        if (!vis[i]) // if not visited, andr jao
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;

            // Isme hm pehle curr_node and uske adj nodes ko pura push kr rhe hai, fir un adj nodes aur uske adj nodes ko dekh rhe hai
            while (!q.empty())
            {
                int curr_node = q.front();
                q.pop();
                bfsSeq.push_back(curr_node);

                for (auto it : adj[curr_node]) // "it" adjacent node hai curr_node ka
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfsSeq;
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

    vector<int> v = bfs(n, adj);
    for (auto x : v)
        cout << x << " ";
}
