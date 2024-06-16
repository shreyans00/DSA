// Program to check which is equilateral, isosceles & scalene

#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a > 0 and b > 0 and c > 0) and (a + b > c and b + c > a and c + a > b) and (abs(a - b) < c and abs(b - c) < a and abs(c - a) < b))
    {
        if (a == b and b == c)
            cout << 1;
        else if ((a == b and b != c) or (b == c and a != b) or (a == c and b != a))
            cout << 2;
        else if (a != b and b != c and c != a)
            cout << 3;
    }
    else
        cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}