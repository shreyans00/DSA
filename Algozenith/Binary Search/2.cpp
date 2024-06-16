#include <bits./stdc++.h>
using namespace std;

int n, q;
vector<int> a;

bool func(int i)
{
    return (a[i] > a[i + 1] && a[i] > a[i - 1]);
}

void bin1(int l, int h, int k)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == k)
            cout << mid << " ";
        else if (a[mid] > k)
            h = mid - 1;
        else
            l = mid + 1;
    }
}

void bin2(int l, int h, int k)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (a[mid] == k)
            cout << mid << " ";
        else if (a[mid] > k)
            l = mid + 1;
        else
            h = mid - 1;
    }
}

void solve()
{
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        int k;
        cin >> k;
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (a[mid] == k)
                cout << mid << " ";
            else if (func(mid))
            {
                bin1(l, mid - 1, k);
                bin2(mid + 1, h, k);
            }
            else
                l = mid + 1;
        }
        cout << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}