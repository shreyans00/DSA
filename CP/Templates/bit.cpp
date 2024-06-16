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
#define pr(a) cout << a << endl;
#define pr2(a, b) cout << a << " " << b << endl;
#define pr3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pr4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define check cout << "working" << endl;
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

// All macros defined considering rightmost index/posn is 0
#define rightmostsetbit(n) log2(n & -n) // posn of rightmost set bit

#define getBit(n, pos) bool(n & (1 << pos)) // 0 or 1
#define setBit(n, pos) (n | (1 << pos))     // set it to 1 at specific pos
#define clearBit(n, pos) (n & ~(1 << pos))  // clear bit to 0 at specific pos
#define clearLastBit(n) (n & (n - 1))       // clear lowest/rightmost set bit to 0

#define msb(n) int32_t(log2(n)) // most significant bit posn (leftmost set bit), also it is the total number of bits in a number-1
#define flipEachBit(n) (n ^ ((1 << msb(n)) - 1))

#define clz __builtin_clz(n)            // remove leading zeros
#define ctz __builtin_ctz(n)            // remove trailing zeros
#define cntSetBit __builtin_popcount(n) // count total set bit

#define binString(n) bitset<32>(n).to_string() // store it in string s & use next macro to get binary representation
#define rlzString(s) s.erase(0, min(s.find_first_not_of('0'), s.size() - 1))

// binArr(n) bitset<32> bs(n)               bitset array of boolean only
// bs[index]
// No. of set bits                          bs.count();
// Tot no. of bits                          bs.size()
// No. of unset(0) bits                     bs.size()-bs.count()
// To check current bit is set or not       bs.test(ind)
// Returns true if atleast 1 bit is set     bs.any()
// Saare bit ko 1 kr dega                   bs.set()
// Saare bit ko 0 kr dega                   bs.reset()
// flip (1 hai to 0, 0 hai to 1)            bs.flip()

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
    int n;
    cin >> n;
    vi v(n);
    loop(i, 0, n)
    {
        cin >> v[i];
    }
}

int32_t main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
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