#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m; // n-no. of nodes,  m-no. of edges
    cin >> n >> m;
    vector<int> adj[n + 1];
    // At every index we can store vector, in case of weight, we need to store pair(adj. node & weight of that edge)
    // like int adj[n+1]  At every index, we store integer

    for (int i = 0; i < m; i++)
    {
        int x, y;      // x & y are vertices & inke bich mai edge hai
        cin >> x >> y; // need to take weight as well in case of weighted graph

        // x ki adjacency list mai y ko push kr denge & vice-versa
        adj[x].push_back(y); // in case of directed, we need to use one only
        adj[y].push_back(x); // in case of weighed, need to push_back{x,wt}
    }
    cout << "Adjacency list of above graph is: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        // vector<int>::iterator it;
        for (auto it : adj[i])
            cout << it << " ";
        cout << endl;
    }
}

/*   Example
7 7
1 2
1 3
2 4
2 5
2 6
2 7
3 7
*/