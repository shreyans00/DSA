// To check the validity of a triangle with given angles

#include <bits / stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c == 180) and a > 0 and b > 0 and c > 0)
    {
        cout << "YES";
    }
    else
        cout << "NO";
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