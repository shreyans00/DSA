#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

int v, e;
vector<int> adj[101];
vector<bool> vis(v + 1, 0);
vector<int> bfseq;
vector<int> par(v + 1, -1);
queue<int> q;
vector<int> idg;
vecto<int> topo;

int main()
{
    cin >> v >> e;
    for (int i = 0; i < v; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    for (int i = 1; i <= v; i++)
    {
        for (auto x : adj[i])
            idg[x]++;
    }
    for (int i = 1; i <= v; i++)
    {
        if (!idg[i])
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        topo.push_back(cur);
        for (auto x : adj[cur])
        {
            idg[x]--;
            if (!idg[x])
            {
                q.push(x);
            }
        }
    }

    return 0;
}