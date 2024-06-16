#include <bits/stdc++.h>
using namespace std;

void removeMid(stack<int> &st, int mid)
{
    if (st.size() == mid)
    {
        st.pop();
        return;
    }
    int topp = st.top();
    st.pop();
    removeMid(st, mid);
    st.push(topp);
}

void solve()
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        st.push(a);
    }
    if (st.empty())
    {
        cout << "stack is empty\n";
        return;
    }
    int mid = st.size() / 2 + 1;
    removeMid(st, mid);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}