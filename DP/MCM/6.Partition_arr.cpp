#include <bits./stdc++.h>
using namespace std;

int f(vector<int> &v, int i, int k, vector<int> &t) // k: total partition in arr
{
    int n = v.size();
    if (i == n)
        return 0;
    if (t[i] != -1)
        return t[i];
    int len = 0, mx = INT_MIN, ans = INT_MIN;
    for (int j = i; j < min(k + i, n); j++)
    {
        len++;
        mx = max(mx, v[j]);
        int sum = len * mx + f(v, j + 1, k, t); // len * mx gives total sum of that partition
        ans = max(ans, sum);
    }
    return t[i] = ans;
}

int main()
{
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    vector<int> t(num.size() + 1, -1);
    cout << f(num, 0, k, t);
}