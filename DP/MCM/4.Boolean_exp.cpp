#include <bits./stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
const int mod = 1e9 + 7;

ll f(string &s, int i, int j, bool istrue, vector<vvi> &t) // istrue tell whether we are looking for true or false, t[n+2][n+2][2]
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (istrue)
            return (s[i] == 'T'); // if s[i]==T & we are looking for true, so it is giving 1 way to make it true
        else
            return (s[i] == 'F');
    }
    if (t[i][j][istrue] != -1)
        return t[i][j][istrue];
    ll ways = 0;
    for (int k = i + 1; k < j; k += 2)
    {
        ll lT = f(s, i, k - 1, 1, t), lF = f(s, i, k - 1, 0, t), rT = f(s, k + 1, j, 1, t), rF = f(s, k + 1, j, 0, t);

        if (s[k] == '|')
            ways = istrue ? (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod : (ways + (rF * lF) % mod) % mod;

        else if (s[k] == '&')
            ways = istrue ? (ways + (lT * rT) % mod) % mod : (ways + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;

        else
            ways = istrue ? (ways + (lT * rF) % mod + (rT * lF) % mod) % mod : (ways + (lT * rT) % mod + (lF * rF) % mod) % mod;
    }
    return t[i][j][istrue] = ways;
}

int main()
{
    string exp = "T|F^T";
    int n = exp.size();
    vector<vvi> t(n + 2, vvi(n + 2, vi(2, -1)));
    cout << f(exp, 0, n - 1, 1, t);
    return 0;
}