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
#define vb vector<bool>
#define vli vector<long int>
#define vlli vector<long long int>
#define pi pair<int, int>
#define ppi pair<int, pair<int, int>>
#define vpii vector<pair<int, int>>
#define vpli vector<pair<long int, long int>>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
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
#define pr(a) cout << a << endl;

const int mod = 1e9 + 7;

int f(vi v, int i, bool b, int c, vector<vvi> t)
{
    if (c == 2 || i == v.size())
        return 0;
    if (t[i][b][c] != -1)
        return t[i][b][c];
    // Buy
    if (b)
        return t[i][b][c] = max(f(v, i + 1, 0, c, t) - v[i], f(v, i + 1, 1, c, t)); // we can't do c+1 here
    // Sell
    return t[i][b][c] = max(f(v, i + 1, 0, c, t), f(v, i + 1, 1, c + 1, t) + v[i]); // have to do c+1 here
}

void solve()
{
    vi v = {7, 1, 5, 3, 6, 4};
    int n = v.size();
    // vector<vvi> t(n + 1, vvi(2, vi(3, -1)));
    // pr(f(v, 0, 1, 0, t));
    // vector<vvi> t(n + 1, vvi(2, vi(3, 0)));

    vvi ahead(2, vi(3, 0)), cur(2, vi(3, 0));
    rloop(i, n - 1, 0) // n ki jrurat nhi kyunki uski value 0 hogi
    {
        loop(j, 0, 2)
        {
            rloop(k, 1, 0) // 2 bhi jrurat nhi kyunki wo value 0 hogi
            {
                if (j)
                    cur[j][k] = max(ahead[0][k] - v[i], ahead[1][k]);
                else
                    cur[j][k] = max(ahead[0][k], ahead[1][k + 1] + v[i]);
            }
            ahead = cur;
        }
    }
    pr(ahead[1][0]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}