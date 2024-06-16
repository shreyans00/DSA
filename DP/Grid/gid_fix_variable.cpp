#include <bits/stdc++.h>
using namespace std;
typedef long int li;
typedef long long int ll;
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)
// #define fa(arr,n) for(li i=0;i<n;i++){cin>>arr[i];}
// #define fv(vec,n) for(li i=0;i<n;i++) {li p;cin>>p;vec.pb(p)};
#define all(x) x.begin(), x.end()
#define lb(x, key) lower_bound(x.begin(), x.end(), key)
#define ub(x, key) upper_bound(x.begin(), x.end(), key)
#define endl "\n"
#define vi vector<int>
#define vli vector<long int>
#define vlli vector<long long int>
#define pi pair<int, int>
#define ppi pair<int, pair<int, int>>
#define vpii vector<pair<int, int>>
#define vpli vector<pair<long int, long int>>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define si set<int>
#define sli set<long int>
#define slli set<long long int>
#define rsi set<int, greater<int>>
#define rsli set<long int, greater<long int>>
#define rslli set<long long int, greater<long long int>>
#define usi unordered_set<int>
#define usli unordered_set<long int>
#define uslli unordered_set<long long int>
#define mii map<int, int>
#define mli map<long int, long int>
#define mlli map<long long int, long long int>
#define umii unordered_map<int, int>
#define umli unordered_map<long int, long int>
#define umlli unordered_map<long long int, long long int>
#define gcd(a, b) __gcd(a, b)
#define debug(x) cout << #x << ' ' << x << '\n'
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mpr make_pair
#define first ff
#define second ss
#define sort(arr) sort(arr.begin(), arr.end())
#define rsort(arr) sort(arr.rbegin(), arr.rend())
#define work cout << "working" << endl;

int f(vvi v, int x, int c)
{
    int n = v.size();
    if (x == n - 1)
        return v[x][c];
    if (c >= n || c < 0)
        return 0;

    return v[x][c] + max(f(v, x + 1, c - 1), max(f(v, x + 1, c), f(v, x + 1, c + 1)));
}

void solve()
{
    vvi v = {{1, 2, 10, 4}, {100, 3, 2, 500}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int mx = 0, n = v.size();
    loop(i, 0, n) mx = max(mx, f(v, 0, i));
    cout << mx << endl;
}

int f2(vvi v, int x, int c, vvi t)
{
    int n = v.size();
    if (x == n - 1)
        return t[x][c] = v[x][c];
    if (c >= n || c < 0)
        return 0;
    if (t[x][c] != -1)
        return t[x][c];

    return t[x][c] = v[x][c] + max(f2(v, x + 1, c - 1, t), max(f2(v, x + 1, c, t), f2(v, x + 1, c + 1, t)));
}

void solve2()
{
    vvi v = {{1, 2, 10, 4}, {100, 3, 2, 500}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int mx = 0, n = v.size();

    vvi t(n, vi(n, -1));
    loop(i, 0, n)
        mx = max(mx, f2(v, 0, i, t));
    cout << mx << endl;
}

int f3(vvi v)
{
    int n = v.size();
    vvi t(n, vi(n + 1, 0));
    loop(i, 0, n)
    {
        t[n - 1][i] = v[n - 1][i];
        t[i][-1] = 0;
        t[i][n] = 0;
    }
    rloop(i, n - 2, 0)
    {
        rloop(j, i, 0) {}
        t[i][j] = v[i][j] + max(t[i + 1][j - 1], max(t[i + 1][j + 1], t[i + 1][j]));
    }
    int mx = -1e9;
    loop(i, 0, n)
        mx = max(mx, t[0][i]);
    return mx;
}

void solve3()
{
    vvi v = {{1, 2, 10, 4}, {100, 3, 2, 500}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    int n = v.size();
    cout << f3(v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    solve2();
    solve3();
    return 0;
}