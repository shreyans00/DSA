#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> v;
vector<pair<int, int>> tree;

void build(int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = {v[st] % 2 == 1, v[st] % 2 == 0};
        return;
    }
    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    tree[node] = {tree[2 * node].first + tree[2 * node + 1].first,
                  tree[2 * node].second + tree[2 * node + 1].second};
}

void update(int node, int st, int en, int pos, int x)
{
    if (st == en)
    {
        if (x % 2 == 1 && v[st] % 2 == 0)
            tree[node] = {tree[node].first + 1, tree[node].second - 1};
        else if (x % 2 == 0 && v[st] % 2 == 1)
            tree[node] = {tree[node].first - 1, tree[node].second + 1};
        return;
    }
    int mid = (st + en) / 2;
    if (pos <= mid)
        update(2 * node, st, mid, pos, x);
    else
        update(2 * node + 1, mid + 1, en, pos, x);
    tree[node] = {tree[2 * node].first + tree[2 * node + 1].first,
                  tree[2 * node].second + tree[2 * node + 1].second};
}

pair<int, int> query(int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return {0, 0};
    if (st >= l && en <= r)
        return tree[node];
    int mid = (st + en) / 2;
    pair<int, int> left = query(2 * node, st, mid, l, r), right = query(2 * node + 1, mid + 1, en, l, r);
    return {left.first + right.first, left.second + right.second};
}

void solve()
{
    int n;
    cin >> n;
    v.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int q;
    cin >> q;
    build(1, 0, n - 1);
    while (q--)
    {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 0)
            update(1, 0, n - 1, x - 1, y);
        else if (c == 1)
            cout << query(1, 0, n - 1, x - 1, y - 1).second << endl;
        else
            cout << query(1, 0, n - 1, x - 1, y - 1).first << endl;
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