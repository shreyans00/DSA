#include <bits/stdc++.h>
using namespace std;
typedef long int li;
typedef long long int ll;
#define loop(i, a, b) for (int i = a; i < b; i++)
#define rloop(i, a, b) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define lb(x, key) lower_bound(x.begin(), x.end(), key)
#define ub(x, key) upper_bound(x.begin(), x.end(), key)
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define si set<int>
#define mii map<int, int>
#define pi pair<int, int>
#define ppi pair<int, pair<int, int>>
#define vp vector<pair<int, int>>
#define gcd(a, b) __gcd(a, b)
#define debug(x) cout << #x << ' ' << x << '\n'
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define mpr make_pair
#define first ff
#define second ss
#define sort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.rbegin(), v.rend())
#define working cout << "working" << endl;
const int mod = 1e9 + 7;

void display(vvs v)
{
    loop(i, 0, v.size())
    {
        loop(j, 0, v[0].size()) cout << v[i][j] << " ";
        cout << endl;
    }
}

bool ispalin(string s)
{
    loop(i, 0, (s.size() / 2) + 1)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

void partioning(string s, int idx, vvs &v, vs &tmp)
// v: store tmp(vector jisme saare substrings palindrome hai)
{
    if (idx == s.size())
    {
        v.push_back(tmp); // ek division mil gya s ka jisme saare substrings palindrome hai
        return;
    }
    loop(i, idx, s.size()) // idx tk already dekh chuke hai, aage dekhte jao
    {
        if (ispalin(s.substr(idx, i - idx + 1))) // i-idx+1 : len of the substring
        {
            tmp.pb(s.substr(idx, i - idx + 1));
            partioning(s, idx + 1, v, tmp);
            tmp.ppb(); // temp clear kr do, agr milna hua hoga, to mil chuka hoga
        }
    }
}

void solve()
{
    string s = "aab";
    vvs v;
    vs tmp;
    partioning(s, 0, v, tmp);
    display(v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}