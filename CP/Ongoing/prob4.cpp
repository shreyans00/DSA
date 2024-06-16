#include <bits/stdc++.h>
using namespace std;
#define inf 1e9

int v, e;
vector<int> adj[101];
vector<int> vis(101, 0);
vector<int> lvis(101, 0);
vector<int> seq;
vector<int> par(101, -1);
stack<int> s;

void dfss(int x)
{
    lvis[x] = 1;
    vis[x] = 1;
    for (auto y : adj[x])
    {
        if (!vis[y])
        {
            dfss(y);
        }
    }
    s.push(x);
}

int main()
{
    cin >> v >> e;

    for (int i = 0; i < v; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= v; i++)
    {
        if (!vis[i])
        {
            if (dfss(i))
            {
                cout << "yes\n";
                return 0;
            }
        }
    }
    cout << "no\n";
    return 0;
}