#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n, k;
    cin >> n >> k;
    ll a[n];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    Method 1 O(n * log k)
        multiset<int>
            ms;
    for (int i = 1; i <= k; i++)
        ms.insert(a[i]);
    // it automatically arranged starting k elements in ascending order, so last element has maxm value

    for (int i = 1; i <= n - k + 1; i++)
    {
        cout << *(ms.rbegin()) << " ";
        ms.erase(ms.find(a[i]));
        if (i < n - k + 1)
            ms.insert(a[i + k]);
    }
    cout << "\n";

    // Method 2     O(n)   not working
    // deque<int> dq;
    // for (int i = 1; i <= k; i++) // add element
    // {
    //     while (!dq.empty() && dq.back() < a[i])
    //         dq.pop_back();
    //     dq.push_back(a[i]);
    //     // if the element at the back of the queue is smaller than the current element removes all those elements and then insert the element.
    // }

    // for (int i = 1; i <= n - k + 1; i++)
    // {
    //     cout << dq.front() << " ";
    //     assert(!dq.empty());
    //     if (dq.front() == a[i + k])
    //         dq.pop_front();
    //     if (i < n - k + 1)
    //     {
    //         for (int i = 1; i <= k; i++)
    //         {
    //             while (!dq.empty() && dq.back() < a[i])
    //                 dq.pop_back();
    //             dq.push_back(a[i]);
    //         }
    //     }
    // }
    // cout << "\n";

    // Method 3
    // for (int i = 1; i <= (n - k + 1); i++)
    // {
    //     ll maxm = INT_MIN;
    //     for (int j = i; j <= (i + k - 1); j++)
    //     {
    //         maxm = max(maxm, a[j]);
    //     }
    //     cout << maxm << " ";
    // }
    // cout << endl;

    // Method 4
    // ll b[n];
    // if (k >= 3)
    // {
    //     b[1] = max(a[1], max(a[2], a[3]));
    //     for (int i = 2; i <= n - k + 1; i++)
    //     {
    //         if (a[i + 2] > b[i - 1])
    //         {
    //             b[i] = a[i + 2];
    //         }
    //         else if (b[i - 1] > a[i - 1])
    //         {
    //             b[i] = b[i - 1];
    //         }
    //         else
    //         {
    //             b[i] = max(max(a[i], a[i + 1]), a[i + 2]);
    //         }
    //     }
    // }
    // else if (k == 1)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         b[i] = a[i];
    //     }
    // }
    // else
    // {
    //     b[1] = max(a[1], a[2]);
    //     for (int i = 2; i <= n - k + 1; i++)
    //     {
    //         if (a[i + 1] > a[i - 1])
    //         {
    //             b[i] = max(a[i + 1], a[i]);
    //         }
    //         else
    //         {
    //             if (a[i] > a[i - 1])
    //             {
    //                 b[i] = a[i];
    //             }
    //             else
    //             {
    //                 b[i] = max(a[i], a[i + 1]);
    //             }
    //         }
    //     }
    // }
    // for (int i = 1; i <= n - k + 1; i++)
    // {
    //     cout << b[i] << " ";
    // }
    // cout << endl;
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