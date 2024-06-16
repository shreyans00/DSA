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

bool f(string &s1, string &s2, int n1, int n2)
{
    if (n1 == 0 && n2 == 0)
        return true;
    if (n1 == 0 && n2 > 0)
        return false;
    if (n2 == 0 && n1 > 0)
    {
        loop(k, 1, n1 + 1)
        {
            if (s1[k - 1] != '*')
                return false;
        }
        return true;
    }
    if (s1[n1 - 1] == '?' || s1[n1 - 1] == s2[n2 - 1])
        return f(s1, s2, n1 - 1, n2 - 1);
    if (s1[n1 - 1] == '*')
        return f(s1, s2, n1 - 1, n2) | f(s1, s2, n1, n2 - 1);
    return false;
}

void solve()
{
    string s1 = "**ab?cd*efg**hij";
    string s2 = "abmcdyuoefghij";
    int n1 = s1.size(), n2 = s2.size();
    // cout << f(s1, s2, n1, n2) << endl;

    // vvb t(n1 + 1, vb(n2 + 1, 0));

    vb prev(n2 + 1, 0), cur(n2 + 1, 0); // initially assume it is pointing to 0th & 1st row
    prev[0] = 1;

    loop(i, 1, n1 + 1)
    {
        // cur is the current row and cur's 0th column has to be assigned everytime
        cur[0] = 1;
        loop(k, 1, i + 1)
        {
            if (s1[k - 1] != '*')
            {
                cur[0] = 0;
                break;
            }
        }
        loop(j, 1, n2 + 1)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
                cur[j] = prev[j - 1];
            else if (s1[i - 1] == '*')
                cur[j] = prev[j] | cur[j - 1];
            else
                cur[j] = 0;
        }
        prev = cur;
    }
    pr(prev[n2]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}