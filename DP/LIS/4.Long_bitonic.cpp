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
// #define sort(arr) sort(arr.begin(), arr.end())
#define rsort(arr) sort(arr.rbegin(), arr.rend())
#define work cout << "working" << endl;
#define pr(a) cout << a << endl;

int solve()
{
    vi v = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = v.size();

    vi t1(n + 1, 1), t2(n + 1, 1);
    loop(i, 0, n)
    {
        int mx = 1;
        loop(j, 0, i)
        {
            if (v[i] > v[j] && 1 + t1[j] > t1[i])
            {
                t1[i] = max(mx, 1 + t1[j]);
                mx = t1[i];
            }
        }
    }

    rloop(i, n - 1, 0)
    {
        int mx = 1;
        rloop(j, n - 1, i + 1)
        {
            if (v[i] > v[j] && 1 + t2[j] > t2[i])
            {
                t2[i] = max(mx, 1 + t2[j]);
                mx = t2[i];
            }
        }
    }
    int mx = 1;
    loop(i, 0, n)
        mx = max(mx, t1[i] + t2[i] - 1);
    return mx;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pr(solve());
    return 0;
}