#include <bits./stdc++.h>
using namespace std;

void topoSortDfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
            topoSortDfs(it, adj, vis, st);
    }
    st.push(node); // once dfs over for current node, we push it into stack
}

vector<int> topologicalSort(int n, vector<int> adj[])
{
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            topoSortDfs(i, adj, vis, st);
    }
    vector<int> topo(n);
    for (int i = 0; i < n; i++)
    {
        topo[i] = st.top();
        st.pop();
    }
    return topo;
}

int main()
{
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    vector<int> topo = topologicalSort(6, adj);
    for (auto x : topo)
        cout << x << " ";
}

// We can also do like this bt then ans print in opposite order

// void topoSortDfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
// {
//     vis[node] = 1;
//     st.push(node);
//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//             topoSortDfs(it, adj, vis, st);
//     }
//     cout << st.top() << " ";
//     st.pop();
// }

// void topologicalSort(int n, vector<int> adj[])
// {
//     vector<int> vis(n, 0);
//     stack<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         if (!vis[i])
//             topoSortDfs(i, adj, vis, st);
//     }
// }

// int main()
// {
//     vector<int> adj[6];
//     adj[5].push_back(2);
//     adj[5].push_back(0);
//     adj[4].push_back(0);
//     adj[4].push_back(1);
//     adj[3].push_back(1);
//     adj[2].push_back(3);

//     topologicalSort(6, adj);
// }