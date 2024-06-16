#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m, r, c, l;
        cin >> n >> m >> r >> c >> l;
        vector<vector<int>> v(n, vector<int>(m));
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> v[i][j];
        }
        queue<pair<int, int>> q;
        q.push({r, c});
        if (v[r][c] == 0)
        {
            cout << 0 << endl;
            continue;
        }
        vis[r][c] = 1;
        vector<pair<int, int>> adj[8];
        adj[1] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        adj[2] = {{-1, 0}, {1, 0}};
        adj[3] = {{0, -1}, {0, 1}};
        adj[4] = {{-1, 0}, {0, 1}};
        adj[5] = {{0, 1}, {1, 0}};
        adj[6] = {{0, -1}, {1, 0}};
        adj[7] = {{0, -1}, {-1, 0}};

        int ans = 0, len = 0;
        while (!q.empty())
        {
            int sz = q.size();
            if (len == l)
                break;
            len++;
            for (int i = 0; i < sz; i++)
            {
                ans++;
                int x = q.front().first, y = q.front().second;
                q.pop();
                int pipe = v[x][y];
                // cout << x << " " << y << " " << pipe << endl;
                for (auto it : adj[pipe])
                {
                    int nx = x + it.first, ny = y + it.second;
                    if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && v[nx][ny] != 0)
                    {
                        // cout << nx << " " << ny << endl;
                        bool f = 0;
                        for (auto ad : adj[v[nx][ny]])
                        {
                            if (ad.first == -it.first && ad.second == -it.second)
                            {
                                f = 1;
                                break;
                            }
                        }
                        if (f)
                        {
                            q.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}