#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct st
{
    multiset<int> ms;
    ll sum = 0;
    void add(int x)
    {
        ms.insert(x);
        sum += x;
    }
    void remove(int x)
    {
        if (ms.find(x) != ms.end())
        {
            ms.erase(ms.find(x));
            sum -= x;
        }
    }
    int minm()
    {
        if (ms.empty())
            return -1;
        return *(ms.begin());
    }
    int maxm()
    {
        if (ms.empty())
            return -1;
        return *(ms.rbegin());
    }
    ll summation()
    {
        return sum;
    }
};

signed main()
{
    int q;
    cin >> q;
    struct st qu;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            ll x;
            cin >> x;
            qu.add(x);
        }
        else if (t == 2)
        {
            ll x;
            cin >> x;
            qu.remove(x);
        }
        else if (t == 3)
        {
            char c;
            cin >> c;
            cout << qu.minm() << endl;
        }
        else if (t == 4)
        {
            char c;
            cin >> c;
            cout << qu.maxm() << endl;
        }
        else if (t == 5)
        {
            char c;
            cin >> c;
            cout << qu.summation() << endl;
        }
        else
        {
            assert(1 == 0);
        }
    }
}