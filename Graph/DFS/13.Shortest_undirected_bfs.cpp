#include <bits./stdc++.h>
using namespace std;

vector<int> shortestDist(int n, vector<int> adj[], int src)
{
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[src] = 0; // dist from source to source is 0
    q.push(src);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto it : adj[curr])
        {
            int d = 1 + dist[curr]; // adding 1 to its parent distance from source
            if (d < dist[it])
            {
                q.push(it);
                dist[it] = d;
            }
        }
    }
    return dist;
}

void addedge(vector<int> adj[], int x, int y)
{
    adj[x].push_back(y);
    adj[y].push_back(x);
}

int main()
{
    int n = 9;
    vector<int> adj[n];
    addedge(adj, 0, 1);
    addedge(adj, 0, 3);
    addedge(adj, 1, 3);
    addedge(adj, 2, 1);
    addedge(adj, 2, 6);
    addedge(adj, 3, 4);
    addedge(adj, 4, 5);
    addedge(adj, 5, 6);
    addedge(adj, 6, 7);
    addedge(adj, 6, 8);
    addedge(adj, 7, 8);

    vector<int> v = shortestDist(n, adj, 0);
    for (auto x : v)
        cout << x << " ";
}