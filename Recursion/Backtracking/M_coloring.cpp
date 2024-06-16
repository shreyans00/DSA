#include <bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color[], bool graph[101][101], int n, int col)
{
    for (int k = 0; k < n; k++) // traverse all nodes
    {
        // since, hmne yahan adjacency matrix bnaya hai, so to check if there is an edge hm every other vertex ke saath g[i][j]==1 check krte hai
        // In adjacency list, only edges are present so no need to check if there's an edge
        // Here, we check k must not be node itself, graph of kth node is adj to node i.e,. there is an edge & color of that node is col
        if (k != node && graph[k][node] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(int node, int color[], int m, int N, bool graph[101][101])
{
    if (node == N)
        return true;

    for (int i = 1; i <= m; i++) // saare "m" combinations try kro curr node pr
    {
        if (isSafe(node, color, graph, N, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, N, graph))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N) // graph is adjacency matrix, not adjacency list
{
    int color[N] = {0};               // store color of N nodes
    if (solve(0, color, m, N, graph)) // 0th node se start kr rhe hai
        return true;
    return false;
}

int main()
{
    int N = 4;
    int m = 3;
    // we have created an adjacency matrix
    bool graph[101][101] = {(0, 1),
                            (1, 2),
                            (2, 3),
                            (3, 0),
                            (0, 2)};
    cout << graphColoring(graph, m, N);
}