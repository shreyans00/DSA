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

int f(vi &v, int i, int prev, vvi &t)
{
    if (i == v.size())
        return 0;
    if (t[i][prev + 1] != -1)
        return t[i][prev + 1];
    if (v[i] > v[prev] || prev == -1)
        return t[i][prev + 1] = max(f(v, i + 1, i, t) + 1, f(v, i + 1, prev, t));
    return t[i][prev + 1] = f(v, i + 1, prev, t);
}

// int nxt_grtr(vi v2, int k)
// {
//     int l = 0, r = v2.size() - 1, ans = v2.size();
//     while (l <= r)
//     {
//         int mid = l + (r - l) / 2;
//         if (v2[mid] >= k)
//         {
//             ans = mid;
//             r = mid - 1;
//         }
//         else
//             l = mid + 1;
//     }
//     return ans;
// }

int solve()
{
    vi v = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = v.size();

    // Method 1

    // vvi t(n + 1, vi(n + 1, -1));
    // return f(v, 0, -1, t);

    // Method 2

    // vvi t(n + 1, vi(n + 1, 0));
    // rloop(i, n - 1, 0)
    // {
    //     rloop(j, i - 1, -1) // prev hmesa -1 se i-1 tk hoga
    //     {
    //         // coordinate shifting (j-coordinate+1) should be there
    //         if (j == -1 || v[i] > v[j])
    //             t[i][j + 1] = max(t[i + 1][i + 1] + 1, t[i + 1][j + 1]);
    //         else
    //             t[i][j + 1] = t[i + 1][j + 1];
    //     }
    // }
    // return t[0][-1 + 1];

    // Method 3

    // vi prev(n + 1, 0), cur(n + 1, 0);
    // rloop(i, n - 1, 0)
    // {
    //     loop(j, -1, i) // prev hmesa -1 se i-1 tk hoga
    //     {
    //         // coordinate shifting (j-coordinate+1) should be there
    //         if (j == -1 || v[i] > v[j])
    //             cur[j + 1] = max(prev[i + 1] + 1, prev[j + 1]);
    //         else
    //             cur[j + 1] = prev[j + 1];
    //     }
    //     prev = cur;
    // }
    // return prev[-1 + 1];

    // Method 4

    // vi prev(n + 1, 0);
    // rloop(i, n - 1, 0)
    // {
    //     loop(j, -1, i) // prev hmesa -1 se i-1 tk hoga
    //     {
    //         // coordinate shifting (j-coordinate+1) should be there
    //         if (j == -1 || v[i] > v[j])
    //             prev[j + 1] = max(prev[i + 1] + 1, prev[j + 1]);
    //         else
    //             prev[j + 1] = prev[j + 1];
    //     }
    // }
    // return prev[-1 + 1];

    // Method 5

    // vi temp(n, 1);
    // loop(i, 0, n)
    // {
    //     int mx = 1;
    //     loop(j, 0, i)
    //     {
    //         if (v[i] > v[j])
    //         {
    //             temp[i] = max(mx, 1 + temp[j]);
    //             mx = temp[i];
    //         }
    //     }
    // }
    // int mx = 1;
    // loop(i, 0, n)
    //     mx = max(mx, temp[i]);
    // return mx;

    // Method 6 (Binary Search)

    vi v2;
    loop(i, 0, n)
    {
        if (v2.empty())
        {
            v2.pb(v[i]);
            continue;
        }
        // either write a function to find 1st pos which is not smaller than v[i] or use lower bound
        // int pos = nxt_grtr(v2, v[i]);
        int pos = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
        if (pos == v2.size())
            v2.pb(v[i]);
        else
            v2[pos] = v[i];
    }
    return v2.size();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pr(solve());
    return 0;
}