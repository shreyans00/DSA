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
#define pr(a) cout << a << endl;

const int mod = 1e9 + 7;

int f(int v[], int sm, int n)
{
    if (n == 1)
    {
        if (sm % v[n - 1] == 0)
            return sm / v[n - 1];
        return 1e9;
    }
    if (sm >= v[n - 1])
        return min(1 + f(v, sm - v[n - 1], n), f(v, sm, n - 1));
    else
        return f(v, sm, n - 1);
}

void solve()
{
    int coin[] = {2, 2, 3};
    int sum = 3;
    // int coin[] = {1, 2, 3, 7, 1, 5};
    // int sum = 18;
    int n = sizeof(coin) / sizeof(coin[0]);
    // int ans = f(coin, sum, n);

    // vvi t(n + 1, vi(sum + 1, 0));

    vi prev(sum + 1, 0);
    loop(i, 1, n + 1)
    {
        loop(j, 0, sum + 1)
        {
            if (i == 1)
            {
                if (j % coin[i - 1] == 0)
                    prev[j] = j / coin[i - 1];
                else
                    prev[j] = 1e9;
            }
            else if (j >= coin[i - 1])
                prev[j] = min(prev[j], 1 + prev[j - coin[i - 1]]);
        }
    }

    int ans = prev[sum];

    if (ans >= 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}