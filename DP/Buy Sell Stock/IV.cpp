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

int f(vi &v, int i, int tr, vvi &t, int k) // tr: transaction,
// & use krne se time complexity km ho jata hai, new copy nhi bnti
{
    if (i == v.size() || tr == 2 * k)
        return 0;
    if (t[i][tr] != -1)
        return t[i][tr];
    if (tr % 2 == 0) // buy
        return t[i][tr] = max(f(v, i + 1, tr + 1, t, k) - v[i], f(v, i + 1, tr, t, k));
    else // sell
        return t[i][tr] = max(f(v, i + 1, tr + 1, t, k) + v[i], f(v, i + 1, tr, t, k));
}

void solve()
{
    vi v = {7, 1, 5, 3, 6, 4};
    int k = 2;
    int n = v.size();
    // vvi t(n + 1, vi(2 * k, -1));
    // pr(f(v, 0, 0, t, k));

    // vvi t(n + 1, vi(2 * k + 1, 0)); // 2*k+1 krna 2*k nhi wrna runtime error aaega

    vi ahead(2 * k + 1, 0);
    rloop(i, n - 1, 0)
    {
        loop(j, 0, 2 * k) // loop reverse kr diye, ek array mai optimise ke liye
        {
            if (j % 2 == 0)
                ahead[j] = max(ahead[j + 1] - v[i], ahead[j]);
            else
                ahead[j] = max(ahead[j + 1] + v[i], ahead[j]);
        }
    }
    pr(ahead[0]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}