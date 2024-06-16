#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n, m; // n-no. of nodes,  m-no. of edges
    cin >> n >> m;

    // 2d vector initialised to 0
    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0)); // adjm[n+1][n+1]

    for (int i = 0; i < m; i++)
    {
        int x, y; // x & y are vertex & inke bich mai edge hai
        cin >> x >> y;
        adjm[x][y] = 1; // x se y bhi edge hai
        adjm[y][x] = 1; // y se x bhi edge hai
    }

    cout << "Adjacency matrix of above graph is: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adjm[i][j] << " ";
        cout << endl;
    }

    return 0;
}