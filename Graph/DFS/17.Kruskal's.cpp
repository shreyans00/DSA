#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u, v, wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b) // to sort according to weight
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent) // to find parent of u
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) // union components of u & v
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v]) // jiske parent ka rank jyada hai, usko sbka parent bnado
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++; // agr dono ke parent ka rank same hai to kisi ko bhi sbka parent bnake rank bdha do
    }
}

int main()
{
    int N = 5, m = 6;
    vector<node> edges;             // to store edges & weights in a struct vector
    edges.push_back(node(0, 1, 2)); // {u,v,wt}
    edges.push_back(node(0, 3, 6));
    edges.push_back(node(1, 0, 2));
    edges.push_back(node(1, 2, 3));
    edges.push_back(node(1, 3, 8));
    edges.push_back(node(1, 4, 5));
    edges.push_back(node(2, 1, 3));
    edges.push_back(node(2, 4, 7));
    edges.push_back(node(3, 0, 6));
    edges.push_back(node(3, 1, 8));
    edges.push_back(node(4, 1, 5));
    edges.push_back(node(4, 2, 7));
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++) // sb apna parent hoga initially
        parent[i] = i;
    vector<int> rank(N, 0);     // sbka initially rank 0 hoga
    int cost = 0;               // to find cost of spanning tree
    vector<pair<int, int>> mst; // edge between mst[i].first & mst[i].second
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent)) // to check if u & v have same parent or not
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});      // mst mai {u,v} edge daal do
            unionn(it.u, it.v, parent, rank); // u & v ke components jo jor do
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
}