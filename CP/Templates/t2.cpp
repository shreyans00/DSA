#include <bits/stdc++.h>
using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

#define int long long
#define double long double
#define endl "\n"

#define vi vector<int>
#define vvi vector<vector<int>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pi pair<int, int>
#define vpii vector<pi>
#define ppi pair<int, pi>

#define vs vector<string>
#define vvs vector<vector<string>>

#define mii map<int, int>
#define umii unordered_map<int, int>

#define si set<int>
#define rsi set<int, greater<int>> // desc order
#define usi unordered_set<int>

#define all(x) x.begin(), x.end()
#define lb(x, key) lower_bound(all(x), key)
#define ub(x, key) upper_bound(all(x), key)
#define sort(arr) sort(arr.begin(), arr.end())
#define rsort(arr) sort(arr.rbegin(), arr.rend())
#define gcd(a, b) __gcd(a, b)

#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, b, a) for (int i = b; i >= a; i--)

#define prs(a) cout << a << " ";
#define pr1(a) cout << a << endl;
#define pr2(a, b) cout << a << " " << b << endl;
#define pr3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pr4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define debug(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << "=" << x << ", " << #y << "=" << y << endl;

#define pb push_back
#define pob pop_back

#ifndef ONLINE_JUDGE
#define debarr(a, n)            \
    cerr << #a << ":";          \
    for (int i = 0; i < n; i++) \
        cerr << a[i] << " ";    \
    cerr << endl;
#define debmat(mat, row, col)         \
    cerr << #mat << ":\n";            \
    for (int i = 0; i < row; i++)     \
    {                                 \
        for (int j = 0; j < col; j++) \
            cerr << mat[i][j] << " "; \
        cerr << endl;                 \
    }
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p)
{
    return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p)
{
    os << "[";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p)
{
    os << "[";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p)
{
    os << "[";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p)
{
    os << "[";
    for (auto &it : p)
        os << it << " ";
    return os << "]";
}
template <class T>
void dbs(string str, T t) { cerr << str << ":" << t << "\n"; }
template <class T, class... S>
void dbs(string str, T t, S... s)
{
    int idx = str.find(',');
    cerr << str.substr(0, idx) << ":" << t << ",";
    dbs(str.substr(idx + 1), s...);
}
#else
#define pr(...) \
    {           \
    }
#define debarr(a, n) \
    {                \
    }
#define debmat(mat, row, col) \
    {                         \
    }
#endif

int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (1LL * ans * a) % mod1;
        }
        a = (1LL * a * a) % mod1;
        b /= 2;
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    loop(i, 0, n)
    {
        loop(j, 0, m)
        {
            cin >> v[i][j];
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}