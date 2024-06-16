#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &v)
    {
        vector<int> ans;
        vector<int> adj[n];
        int sz = v.size();
        for (int i = 0; i < sz; i++)
        {
            adj[v[i][0]].push_back(v[i][1]);
            adj[v[i][1]].push_back(v[i][0]);
        }
        int mn = n;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            vector<int> dis(n, 0);
            vector<bool> vis(n, 0);
            dis[i] = 0;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                for (auto x : adj[cur])
                {
                    if (!vis[x])
                    {
                        q.push(x);
                        vis[x] = 1;
                        dis[x] = dis[cur] + 1;
                    }
                }
            }
            int mx = 0;
            for (int j = 0; j < n; j++)
                mx = max(mx, dis[j]);
            mp[i] = mx;
        }
        for (auto x : mp)
        {
            mn = min(mn, x.second);
            // cout << x.first << " " << x.second << endl;
        }
        for (auto x : mp)
        {
            if (x.second == mn)
                ans.push_back(x.first);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 4;
    vector<vector<int>> edges = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> minHeightTrees = solution.findMinHeightTrees(n, edges);
    cout << "\n";
    // Print the minimum height trees
    for (int i : minHeightTrees)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
