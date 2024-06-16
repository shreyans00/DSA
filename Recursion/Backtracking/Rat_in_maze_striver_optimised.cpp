#include <bits/stdc++.h>
using namespace std;
typedef long int li;
typedef long long int ll;
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b; i >= a; i--)
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

void display(vs v)
{
    loop(i, 0, v.size())
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void f(vvi m, string s, vs &ans, int x, int y, vvi &vis, int di[], int dj[])
// int di[]={1,0,0,-1};
// int dj[]={0,-1,1,0};
{
    int n = m.size();
    if (x == n - 1 && y == n - 1)
    {
        ans.pb(s);
        return;
    }
    string s2 = "DLRU";
    loop(i, 0, 4)
    {
        int x1 = x + di[i];
        int y1 = y + dj[i];
        if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n && !vis[x1][y1] && m[x1][y1])
        {
            vis[x1][y1] = 1;
            f(m, s + s2[i], ans, x1, y1, vis, di, dj);
            vis[x1][y1] = 0;
        }
    }
}

void solve()
{
    int n = 4;
    vvi m = {{1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    string s = "";
    vs ans;
    vvi vis(n, vi(n, 0));
    int di[] = {1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    f(m, s, ans, 0, 0, vis, di, dj);
    display(ans);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}