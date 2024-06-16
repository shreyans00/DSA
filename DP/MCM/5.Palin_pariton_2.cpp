#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

bool ispalin(string &s, int st, int en)
{
    while (st < en)
    {
        if (s[st] != s[en])
            return false;
        st++, en--;
    }
    return true;
}

int f(string &s, int i, vi &t)
{
    int n = s.size();
    if (i == n)
        return 0;
    if (t[i] != -1)
        return t[i];
    int mn = n; // maxm n partitions possible
    for (int j = i; j < n; j++)
    {
        if (ispalin(s, i, j)) // to check s is palindrome from idx i to j or not
        {
            int cnt = 1 + f(s, j + 1, t);
            mn = min(mn, cnt);
        }
    }
    return t[i] = mn;
}

int main()
{
    string str = "abacdbabakgg";
    vi t(str.size() + 1, -1);
    cout << f(str, 0, t) - 1; // -1 to remove end partition, ABC|
}
