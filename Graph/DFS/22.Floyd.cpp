#include <bits/stdc++.h>
using namespace std;

#define V 6 // No of vertices

void floyd_warshall(int graph[V][V]) // V=6 here
{
    int dist[V][V]; // to store min distance b/w one node to another

    // copy graph to dist
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            dist[i][j] = graph[i][j];

    // Find all pairs shortest path by trying all possible paths
    for (int k = 0; k < V; ++k)         // Try all intermediate nodes (isse hokr jayega i to j node)
        for (int i = 0; i < V; ++i)     // Try for all possible starting position
            for (int j = 0; j < V; ++j) // Try for all possible ending position
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) // SKIP if k is unreachable from i or j is unreachable from k
                    continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); // update if new distance is shorter via k
            }

    // Check for negative edge weight cycle
    for (int i = 0; i < V; ++i)
        if (dist[i][i] < 0) // d[i][j] ki value 0 se km nhi ho skti
        {
            cout << "Negative edge weight cycle is present\n";
            return;
        }

    // Print Shortest Path Graph (Values printed as INT_MAX defines there is no path)
    for (int i = 1; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
            cout << i << " to " << j << " distance is " << dist[i][j] << "\n";
        cout << "=================================\n";
    }
}

int main()
{
    int graph[V][V] = {{0, 1, 4, INT_MAX, INT_MAX, INT_MAX}, // we don't know dist => INT_MAX
                       {INT_MAX, 0, 4, 2, 7, INT_MAX},
                       {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                       {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                       {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0}};

    floyd_warshall(graph); // TIME COMPLEXITY: O(V^3)

    return 0;
}
