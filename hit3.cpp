#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define space " "
#define endl "\n"

const int mod = 1000000007;
const int inf = 1e18;
const double pi = acos(-1.0);
const int max1 = 100001;
const int max2 = 1000001;
const int max3 = 10000001;

// p-r 0 - 1
// r-s
// s-p
// p=0
// r=1
// s=2
int calc(int val, char scur)
{
    if (val == 0 && scur == 'R')
        return 1;
    if (val == 1 && scur == 'S')
        return 1;
    if (val == 2 && scur == 'P')
        return 1;
    return 0;
}

int n, k;
string str, sol;
int dp[1010][1010][3];

int rec(int level, int cnt, int prev)
{
    if (level == n)
    {
        return 0;
    }
    if (dp[level][cnt][prev] != -1)
    {
        return dp[level][cnt][prev];
    }
    int ans = calc(prev, str[level]) + rec(level + 1, cnt, prev);
    if (cnt > 0)
    {
        ans = max(ans, calc((prev + 1) % 3, str[level]) + rec(level + 1, cnt - 1, (prev + 1) % 3));
        ans = max(ans, calc((prev + 2) % 3, str[level]) + rec(level + 1, cnt - 1, (prev + 2) % 3));
    }
    return dp[level][cnt][prev] = ans;
}

void gensoln(int level, int cnt, int prev)
{
    if (level == n)
        return;
    int ans1 = -inf, ans2 = -inf, ans3 = -inf, ans;
    ans1 = calc(prev, str[level]) + rec(level + 1, cnt, prev);
    if (cnt > 0)
    {
        ans2 = calc((prev + 1) % 3, str[level]) + rec(level + 1, cnt - 1, (prev + 1) % 3);
        ans3 = calc((prev + 2) % 3, str[level]) + rec(level + 1, cnt - 1, (prev + 2) % 3);
    }
    ans = max(ans1, max(ans2, ans3));
    if (prev == 0)
    {
        if (ans == ans1)
        {
            sol.push_back('P');
            gensoln(level + 1, cnt, 0);
        }
        else if (ans == ans2)
        {
            sol.push_back('R');
            gensoln(level + 1, cnt - 1, 1);
        }
        else if (ans == ans3)
        {
            sol.push_back('S');
            gensoln(level + 1, cnt - 1, 2);
        }
    }
    else if (prev == 1)
    {
        if (ans == ans3)
        {
            sol.push_back('P');
            gensoln(level + 1, cnt - 1, 0);
        }
        else if (ans == ans1)
        {
            sol.push_back('R');
            gensoln(level + 1, cnt, 1);
        }
        else if (ans == ans2)
        {
            sol.push_back('S');
            gensoln(level + 1, cnt - 1, 2);
        }
    }
    else if (prev == 2)
    {
        if (ans == ans2)
        {
            sol.push_back('P');
            gensoln(level + 1, cnt - 1, 0);
        }
        else if (ans == ans3)
        {
            sol.push_back('R');
            gensoln(level + 1, cnt - 1, 1);
        }
        else if (ans == ans1)
        {
            sol.push_back('S');
            gensoln(level + 1, cnt, 2);
        }
    }
}

void solve()
{
    sol.clear();
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cin >> str;
    int ans1 = rec(0, k, 0);
    int ans2 = rec(0, k, 1);
    int ans3 = rec(0, k, 2);
    int ans = max(ans1, max(ans2, ans3));
    string sol1 = "zz", sol2 = "zz", sol3 = "zz";
    if (ans1 == ans)
    {
        sol.clear();
        gensoln(0, k, 0);
        sol1 = sol;
    }
    if (ans2 == ans)
    {
        sol.clear();
        gensoln(0, k, 1);
        sol2 = sol;
    }
    if (ans3 == ans)
    {
        sol.clear();
        gensoln(0, k, 2);
        sol3 = sol;
    }
    sol = min(sol1, min(sol2, sol3));
    cout << ans << endl;
    cout << sol << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t = 1;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}