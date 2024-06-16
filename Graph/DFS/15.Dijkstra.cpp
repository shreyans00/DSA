#include <bits./stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<pair<int, int>> adj[], int src)
{
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        int node_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int d = node_dist + it.first;
            if (d < dist[it.second])
            {
                dist[it.second] = d;
                pq.push(it);
            }
        }
    }
    return dist;
}

void addedge(vector<pair<int, int>> adj[], int x, int y, int w)
{
    adj[x].push_back({w, y});
    adj[y].push_back({w, x});
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

    vector<int> v = dijkstra(n, adj, 0);
    for (auto x : v)
    {
        if (x == INT_MAX)
            cout << "Infinity ";
        else
            cout << x << " ";
    }
    cout << endl;
}