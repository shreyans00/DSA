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
#define ppb pop_back
#define eb emplace_back
#define mpr make_pair
#define first ff
#define second ss
#define sort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.rbegin(), v.rend())
#define working cout << "working" << endl;
const int mod = 1e9 + 7;

void display(vvi v)
{
    loop(i, 0, v.size())
    {
        loop(j, 0, v[0].size())
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isValid(vvi v, int r, int c, int val)
{
    loop(i, 0, 9)
    {
        if (v[r][i] == val)
            return false;
        if (v[i][c] == val)
            return false;
        if (v[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == val)
            return false;
    }
    return true;
}

bool sudoko(vvi &v)
{
    loop(i, 0, v.size())
    {
        loop(j, 0, v[0].size())
        {
            if (v[i][j] == 0)
            {
                loop(val, 1, 10)
                {
                    if (isValid(v, i, j, val))
                    {
                        v[i][j] = val;
                        if (sudoko(v))
                            return true; // hme saare possible grids nhi nikalne, so jis value pe bhi sudoko(grid) true ho rha ho, whi return kr do
                        v[i][j] = 0;     // backtracking step
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solve()
{
    vvi grid = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                {5, 2, 0, 0, 0, 0, 0, 0, 0},
                {0, 8, 7, 0, 0, 0, 0, 3, 1},
                {0, 0, 3, 0, 1, 0, 0, 8, 0},
                {9, 0, 0, 8, 6, 3, 0, 0, 5},
                {0, 5, 0, 0, 9, 0, 6, 0, 0},
                {1, 3, 0, 0, 0, 0, 2, 5, 0},
                {0, 0, 0, 0, 0, 0, 0, 7, 4},
                {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (sudoko(grid))
    {
        display(grid);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}