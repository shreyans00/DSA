#include <bits/stdc++.h>
using namespace std;

#define int long long
/******************* Segment Tree Start Here ************************/
// This code is written for Range Minimum Query
// define node according to question
// change merge function according to question

vector<int> arr;
vector<node> segt;

struct node
{
    int mx, lf, rg, tsm;
    node(int new_mx = 0, int new_lf = 0, int new_rg = 0, int new_tsm = 0)
    {
        mx = new_mx, lf = new_lf, rg = new_rg, tsm = new_tsm;
    }
};

node merge(node a, node b)
{
    node temp;
    int c = 0;
    temp.mx = max({a.mx, b.mx, a.rg + b.lf, c});
    temp.lf = max({a.lf, a.tsm + b.lf, c});
    temp.rg = max({b.rg, b.tsm + a.rg, c});
    temp.tsm = a.tsm + b.tsm;
    return temp;
}

void build(int index, int l, int r)
{
    if (l == r)
    {
        int mxx = max(arr[l], 0LL);
        segt[index] = node(mxx, mxx, mxx, arr[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    segt[index] = merge(segt[2 * index], segt[2 * index + 1]);
}

void update(int index, int l, int r, int pos, int val)
{
    if (l == r)
    {
        int mxx = max(val, 0LL);
        segt[index] = node(mxx, mxx, mxx, val);
        // arr[pos] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(index * 2, l, mid, pos, val);
    else
        update(index * 2 + 1, mid + 1, r, pos, val);
    segt[index] = merge(segt[2 * index], segt[2 * index + 1]);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    segt.resize(4 * n);
    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(1, 0, n - 1);
    while (m--)
    {
        int k, x;
        cin >> k >> x;
        update(1, 0, n - 1, k - 1, x);
        cout << segt[1].mx << endl;
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