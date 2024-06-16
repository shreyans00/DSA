// Program to find the sum of all possible xor of 2 elements of an array
#include <bits./stdc++.h>
using namespace std;

int main()
{
    int n; // no. of elements
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt[32]; // (since 32 bit system)
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) // O(n)
    {
        int x = arr[i];
        for (int j = 0; j < 32; j++)
        {
            if (x & (1 << j))
                cnt[j]++; // count of total set bits in ith bit of x
        }
    }
    long long ans = 0;
    for (int j = 0; j < 32; j++)
    {
        // Each bit contribution = number of 1's * number of 0's * pow(2,j)
        long long bitContribution = 1LL * cnt[j] * (n - cnt[j]) * (1LL << j);
        ans += bitContribution;
    }
    cout << ans << endl;
}