#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> v, tree;

void update(int node, int st, int en, int i, int j, int x)
{
    if (i > en || st > j)
        return;
    if (st >= i && en <= j)
    {
        tree[node] += x;
        return;
    }
    int mid = (st + en) / 2;
    update(2 * node, st, mid, i, j, x);
    update(2 * node + 1, mid + 1, en, i, j, x);
}

int query(int node, int st, int en, int i)
{
    if (st == en)
        return tree[node];
    int mid = (st + en) / 2;
    if (i <= mid)
        return tree[node] + query(2 * node, st, mid, i);
    else
        return tree[node] + query(2 * node + 1, mid + 1, en, i);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    v.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (q--)
    {
        int c;
        cin >> c;
        if (c == 1)
        {
            int i, j, x;
            cin >> i >> j >> x;
            i--, j--;
            update(1, 0, n - 1, i, j, x);
        }
        else
        {
            int i;
            cin >> i;
            i--;
            cout << v[i] + query(1, 0, n - 1, i) << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while (_t--)
        solve();
    return 0;
}