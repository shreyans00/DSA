#include <bits./stdc++.h>
using namespace std;

// Isko samajhne ke liye pehle 12.Topological_sort_bfs dekho

class Solution
{
public:
    bool iscyclic(int n, vector<int> adj[])
    {
        queue<int> q;
        vector<int> indg(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
                indg[it]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (!indg[i])
                q.push(i);
        }
        vector<int> topo;
        int cnt = 0;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            // jo bhi hm topo mai daal rhe hai, wo sara topoSort ko satisfy kr rha hai
            // waise isme topo bnane ki jrurat nhi thi, topoSort nikalne ke liye bnate hai
            cnt++; // so cnt++ kr do
            for (auto it : adj[curr])
            {
                indg[it]--;
                if (!indg[it])
                    q.push(it);
            }
        }
        if (cnt == n) // agr cnt=n ho gya mtlb saare elements topo array mai aa gye
            return 0;
        return 1;
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
    if (obj.iscyclic(6, adj))
        cout << "cycle detected";
    else
        cout << "cycle not detected";
}