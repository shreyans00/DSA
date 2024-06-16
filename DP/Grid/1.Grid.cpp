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
#define si set<int>
#define mii map<int, int>
#define pi pair<int, int>
#define ppi pair<int, pair<int, int>>
#define vp vector<pair<int, int>>
#define gcd(a, b) __gcd(a, b)
#define debug(x) cout << #x << ' ' << x << '\n'
#define pb push_back
#define eb emplace_back
#define mpr make_pair
#define first ff
#define second ss
#define sort(arr) sort(arr.begin(), arr.end())
#define rsort(arr) sort(arr.rbegin(), arr.rend())
#define working cout << "working" << endl;
const int mod = 1e9 + 7;

int f(int n, int m, vvi &t)
{
    if (n == 0 || m == 0)
        return 1;
    // if (t[m][n] != -1)
    //     return t[n][m];
    return t[m][n] = f(n - 1, m, t) + f(n, m - 1, t);
}

int f2(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    return f2(i - 1, j) + f2(i, j - 1);
}

int main()
{
    int m = 1, n = 1;
    vvi t(m, vi(n, -1));
    cout << f(n - 1, m - 1, t) << endl;
    cout << f2(n - 1, m - 1);
}
