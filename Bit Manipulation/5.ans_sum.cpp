#include <bits./stdc++.h>
using namespace std;

int fact(int num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * fact(num - 1);
}

int nCr(int N, int r)
{
    return fact(N) / (fact(N - r) * fact(r));
}

int main()
{
    int n;
    cin >> n;
    int cnt[31];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < 31; j++)
        {
            if ((x >> j) & 1)
                cnt[j]++;
        }
    }
    long long int ans = 0;
    for (int i = 0; i < 31; i++)
    {
        long long temp;
        if (cnt[i] >= 2)
            temp = 1LL * nCr(cnt[i], 2);
        ans += temp * (1LL << i);
    }
    cout << ans << endl;
}