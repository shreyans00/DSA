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
#define ff first
#define ss second
#define MP make_pair

#define debarr(a)                      \
    cerr << #a << ": ";                \
    for (int i = 0; i < a.size(); i++) \
        cerr << a[i] << " ";           \
    cerr << endl;

#define deb2arr(a)                            \
    cerr << #a << ": \n";                     \
    for (int i = 0; i < a.size(); i++)        \
    {                                         \
        for (int j = 0; j < a[0].size(); j++) \
            cerr << a[i][j] << " ";           \
        cerr << endl;                         \
    }

class prioritize
{
public:
    bool operator()(pii &p1, pii &p2)
    {
        return p1.ss > p2.ss; // to find smallest distance node at the end of the vector ie top of the pq
    }
};

int n, m;
vpii g[100100];

int dist[100100];
int vis[100100];

void dijkstra(int sc)
{
    loop(i, 1, n + 1)
    {
        dist[i] = 1e18;
        vis[i] = 0;
    }
    dist[sc] = 0;
    priority_queue<pii, vpii, prioritize> pq;
    pq.push(MP(sc, 0));
    while (!pq.empty())
    {
        pii fs = pq.top();
        pq.pop();
        if (!vis[fs.ff])
        {
            vis[fs.ff] = 1;
            for (auto v : g[fs.ff])
            {
                int neigh = v.ff;
                int wt = v.ss;
                if (dist[neigh] > dis[fs.ff] + wt)
                {
                    dist[neigh] = dis[fs.ff] + wt;
                    pq.push(MP(neigh, dist[neigh]));
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    loop(i, 0, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        g[b].pb({a, c});
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
    // cin >> tc;
    while (tc--)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
