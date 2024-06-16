// Program to find maxm of taking k consecutive elements

// Multiset  is just a container like stack, where you can push elements, diff is that it has definite order,
// e.g. we use greater <int> here, which signifies whatever we insert in multiset it will be stored in descending order, i.e. first element will be the largest one.

#include <bits./stdc++.h>
#include <deque>
using namespace std;

int main()
{
    // Method 1
    // int a[] = {1, 3, -1, -3, 5, 3, 6, 7};
    // int k = 3;
    // int c = 0;
    // int siz = sizeof(a) / sizeof(a[0]);
    // for (int i = 0; i < siz - 2; i++, c = c - k + 2)
    // {
    //     int max = a[c];
    //     for (int l = 0; l < k - 1; l++)
    //     {
    //         c++;
    //         if (a[c] > max)
    //         {
    //             max = a[c];
    //         }
    //     }
    //     cout << max << endl;
    // }

    // Method 2
    // Time complexity: nlog(n)
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    // multiset<int, greater<int>> s;
    // vector<int> ans;
    // for (int i = 0; i < k; i++)
    // {
    //     s.insert(a[i]);
    // }
    // ans.push_back(*s.begin());
    // for (int i = k; i < n; i++)
    // {
    //     s.erase(s.lower_bound(a[i - k]));
    //     s.insert(a[i]);
    //     ans.push_back(*s.begin());
    // }
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }

    // Method 3 (best)
    // Time Complexity: O(1)
    deque<int> q;    // we will be adding indices to deque, not elements
    vector<int> ans; // ans - maximum of each window
    // for first k elements
    for (int i = 0; i < k; i++)
    {
        while (!q.empty() && a[q.back()] < a[i])
        /*so the above line means, if the current element is greater 
          than the last index pushed to the deque*/
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    //push this to our answer but remember don't do q.front() as we are dealing with indices.
    ans.push_back(a[q.front()]);
    for (int i = k; i < n; i++)
    {
        if (q.front() == i - k)
        {
            q.pop_front();
        }
        while (!q.empty() and a[q.back()] < a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}