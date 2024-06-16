#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int gans;
void dfs(vector<vector<int>> &v, int n, int x, int y, int dx, int dy, vector<int> &vis, int curr)
{
    gans = min(gans, curr + abs(dx - x) + abs(dy - y));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            // Enter at entry point
            vis[i] = 1;
            int dist_1 = v[i][4] + curr + abs(v[i][0] - x) + abs(v[i][1] - y);
            dfs(v, n, v[i][2], v[i][3], dx, dy, vis, dist_1);
            vis[i] = 0;

            // Entry at exit point
            vis[i] = 1;
            int dist_2 = v[i][4] + curr + abs(v[i][2] - x) + abs(v[i][3] - y);
            dfs(v, n, v[i][0], v[i][1], dx, dy, vis, dist_2);
            vis[i] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        gans = INT_MAX;
        vector<vector<int>> v(n, vector<int>(5, 0));
        for (int i = 0; i < n; i++)
        {
            int a, b, c, d, s;
            cin >> a >> b >> c >> d >> s;
            v[i] = {a, b, c, d, s};
        }
        vector<int> vis(n, 0);
        dfs(v, n, xs, ys, xd, yd, vis, 0);
        cout << gans << endl;
    }

    return 0;
}