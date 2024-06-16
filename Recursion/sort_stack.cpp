#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int topp)
{
    if (st.empty() || st.top() <= topp)
    {
        st.push(topp);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, topp);
    st.push(temp);
}

void sortit(stack<int> &st)
{
    if (st.size() == 1)
        return;
    int topp = st.top();
    st.pop();
    sortit(st);
    insert(st, topp);
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
    sortit(st);
    for (int i = 0; i < n; i++)
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