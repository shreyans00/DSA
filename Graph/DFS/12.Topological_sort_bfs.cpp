#include <bits./stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topobfs(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indg(n, 0);
        for (int i = 0; i < n; i++) // calculating indegree of all nodes
        {
            for (auto it : adj[i])
                indg[it]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (!indg[i])
                q.push(i); // q mai push krdo jis node ka indegree 0 hai
        }
        vector<int> topo;
        while (!q.empty()) // normal bfs with slight modification
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for (auto it : adj[curr])
            {
                indg[it]--;
                if (!indg[it])
                    q.push(it);
            }
        }
        return topo;
    }
};

int main()
{
    vector<int> adj[6];
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[3].push_back(1);
    adj[2].push_back(3);

    Solution obj;
    vector<int> v = obj.topobfs(6, adj);
    for (auto x : v)
        cout << x << " ";
}