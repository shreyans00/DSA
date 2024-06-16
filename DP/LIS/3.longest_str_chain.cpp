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
const int mod = 1e9 + 7;

bool check(string &s1, string &s2)
{
    int n = s1.size();
    if (n != 1 + s2.size())
        return 0;
    int i = 0, k = 0;
    while (n--)
    {
        if (s1[i] == s2[k])
            i++, k++;
        else
            i++;
    }
    return (k == s2.size() && i == s1.size());
}

int f(vs &words, int i, int prev)
{
    if (i == words.size())
        return 0;
    if (prev == -1 || (check(words[i], words[prev])))
        return max(f(words, i + 1, prev), 1 + f(words, i + 1, i));
    return f(words, i + 1, prev);
}

bool cmp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}

int solve()
{
    vs words = {"x", "a", "b", "c", "cx", "ba", "bca", "bda", "bdca"};
    sort(words.begin(), words.end(), cmp);
    // return f(words, 0, -1);
    int n = words.size();

    vvi t(n + 1, vi(n + 1, 0));
    rloop(i, n - 1, 0)
    {
        rloop(j, i - 1, -1)
        {
            if (j == -1 || check(words[i], words[j])) // only change is check function
                t[i][j + 1] = max(t[i + 1][i + 1] + 1, t[i + 1][j + 1]);
            else
                t[i][j + 1] = t[i + 1][j + 1];
        }
    }
    return t[0][-1 + 1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    pr(solve());
    return 0;
}