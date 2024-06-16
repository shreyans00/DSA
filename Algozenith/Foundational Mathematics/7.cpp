// Unable to solve myself

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int mod = 1e9 + 7;

void solve()
{
    ll a, b;
    cin >> a >> b;
    string s = "";

    if (a < 0 && b > 0)
    {
        s += "-";
        a = -a;
    }
    if (b < 0 && a > 0)
    {
        s += "-";
        b = -b;
    }

    float deci = a % b;
    if (deci == 0)
    {
        s += to_string(a / b);
        cout << s << endl;
        return;
    }
    s += to_string(a / b);
    s += '.';
    unordered_map<ll, int> pos;
    ll posn = -1;
    while (deci)
    {
        if (pos.find(deci) != pos.end())
        {
            posn = pos[deci];
            break;
        }
        ll temp = deci * 10; // we try to take first decimal part & neglect other for this loop & can be counter in further loops
        s += to_string(temp / b);
        pos[deci] = (int)s.length();
        deci = temp % b; // to find next decimal
    }

    if (posn != -1)
    {
        int leng = (int)s.length();
        s = s.substr(0, posn - 1) + "(" + s.substr(posn - 1, leng - posn + 1) + ")";
    }

    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}