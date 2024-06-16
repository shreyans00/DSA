#include <bits./stdc++.h>
using namespace std;

void prim(int src, int n, vector<pair<int, int>> adj[]) // src=0
{
    vector<int> key(n, INT_MAX), parent(n, -1);
    vector<bool> mst(n, false);
    key[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    for (int i = 0; i < n - 1; i++) // for edges e=n-1
    {
        int u = pq.top().second; // we don't need that loop, O(log n) complexity now
        pq.pop();
        mst[u] = true;
        for (auto it : adj[u]) // for all adj, keep updating parent & key
        {
            int idx = it.first;
            int weight = it.second;
            if (mst[idx] == false && weight < key[idx])
                parent[idx] = u, key[idx] = weight, pq.push({key[idx], v}); // also, we need to push this pair
        }
    }
    for (int i = 1; i < n; i++)                  // not from i=0 since 0 is source node, should have any parent
        cout << parent[i] << " - " << i << "\n"; // Ordering of this gives mst
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

    prim(0, n, adj);
}