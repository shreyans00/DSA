#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

vector<int> tree, v;

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = v[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int pos, int x, int st, int en)
{
    if (st == en)
    {
        tree[node] = x;
        v[st] = x;
        return;
    }
    int mid = (st + en) / 2;
    if (pos <= mid)
        update(2 * node, pos, x, st, mid);
    else
        update(2 * node + 1, pos, x, mid + 1, en);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int l, int r, int node, int st, int en)
{
    if (st > r || en < l)
        return 0;
    if (st >= l && en <= r)
        return tree[node];
    int mid = (st + en) / 2;
    return query(l, r, 2 * node, st, mid) + query(l, r, 2 * node + 1, mid + 1, en);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    tree.resize(4 * n);
    build(1, 0, n - 1);
    while (q--)
    {
        int c, i, x;
        cin >> c >> i >> x;
        i--;
        if (c == 1)
            update(1, i, x, 0, n - 1);
        else
        {
            x--;
            cout << query(i, x, 1, 0, n - 1) << endl;
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