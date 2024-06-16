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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

bool update(int node, int st, int en, int x)
{
    if (tree[node] < x)
        return 0;
    if (st == en)
    {
        tree[node] -= x;
        // v[st] -= x;
        return 1;
    }
    int mid = (st + en) / 2;
    if (update(2 * node, st, mid, x))
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    else if (update(2 * node + 1, mid + 1, en, x))
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    return 1;
}

int query(int node, int st, int en, int x)
{
    if (tree[node] < x)
        return -1;
    if (st == en)
        return st;
    int mid = (st + en) / 2;
    int left = query(2 * node, st, mid, x);
    if (left != -1)
        return left;
    return query(2 * node + 1, mid + 1, en, x);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    v.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    build(1, 0, n - 1);
    while (q--)
    {
        int x;
        cin >> x;
        cout << query(1, 0, n - 1, x) + 1 << " ";
        update(1, 0, n - 1, x);
    }
    cout << endl;
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