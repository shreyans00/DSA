#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs(int x, int y, int cnt, int bc, vector<vector<int>> &v)
{
    if (y == 0)
    {
        ans = max(ans, cnt);
        return;
    }
    if (v[y - 1][x] == 1)
        dfs(x, y - 1, cnt + 1, bc, v);
    else if (v[y - 1][x] == 0)
        dfs(x, y - 1, cnt, bc, v);
    else if (bc > 0)
        dfs(x, y - 1, cnt, bc - 1, v);

    if (x > 1)
    {
        if (v[y - 1][x - 1] == 1)
            dfs(x - 1, y - 1, cnt + 1, bc, v);
        else if (v[y - 1][x - 1] == 0)
            dfs(x - 1, y - 1, cnt, bc, v);
        else if (bc > 0)
            dfs(x - 1, y - 1, cnt, bc - 1, v);
    }

    if (x < 4)
    {
        if (v[y - 1][x + 1] == 1)
            dfs(x + 1, y - 1, cnt + 1, bc, v);
        else if (v[y - 1][x + 1] == 0)
            dfs(x + 1, y - 1, cnt, bc, v);
        else if (bc > 0)
            dfs(x + 1, y - 1, cnt, bc - 1, v);
    }
}

int main()
{
    int tc;
    cin >> tc;
    for (int k = 1; k <= tc; k++)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(5, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 5; j++)
                cin >> v[i][j];
        }
        ans = 0;
        dfs(2, n, 0, 5, v);
        cout << "#" << k << " " << ans << endl;
    }
}