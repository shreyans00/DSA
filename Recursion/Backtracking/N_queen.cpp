// Program to place N Queens in a N*N chessboard such that no two can attack each other

#include <iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n)
{
    // check for same column
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
            return false;
    }

    // check for left diagonal
    int row = x;
    int col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col--;
    }

    // check for right diagonal
    row = x;
    col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }
    return true; // In other cases it can be placed
}

bool nQueen(int **arr, int x, int n) // we don't need y  (as there is no need to go for other columns) and solArr (as we make changes on arr itself)
{
    if (x >= n) // all the rows are covered and queens have been placed successfully
        return true;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(arr, x, col, n))
        {
            arr[x][col] = 1;
            if (nQueen(arr, x + 1, n))
                return true;

            arr[x][col] = 0; // backtracking (jb aage wala kaam nhi kr rha ho to wapas piche chale jana)
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// My successful attempt
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

bool is_safe(int r, int c, vvi v)
{
    int n = v.size();
    loop(i, 0, n)
    {
        if (v[i][c] != 0)
            return false;
    }
    loop(i, 0, n)
    {
        if (v[r][i] != 0)
            return false;
    }
    int row = r;
    int col = c;
    while (row >= 0 && col >= 0)
    {
        if (v[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = r;
    col = c;
    while (row >= 0 && col >= 0)
    {
        if (v[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}

void f(int n, vvi v, int r)
{
    if (r == n)
    {
        display(v);
        return;
    }
    loop(i, 0, n)
    {
        if (is_safe(r, i, v))
        {
            v[r][i] = 1;
            f(n, v, r + 1);
            v[r][i] = 0;
        }
    }
}

void solve()
{
    int n = 4;
    vvi v(n, vi(n, 0));
    f(n, v, 0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}