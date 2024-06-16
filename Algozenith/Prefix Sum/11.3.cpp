#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;
ll power(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y / 2, x = (x * x) % mod;
    }
    return res % mod;
}
const int N = 1000001;
ll powerK[N];
ll arr[N];
ll prefixSum[N];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, q, k;
    cin >> n >> q >> k;
    powerK[0] = 1;
    for (int i = 1; i <= n; i++)
        powerK[i] = k * powerK[i - 1] % mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] * powerK[i] % mod;
        if (arr[i] < 0)
            arr[i] += mod;
    }
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
        if (prefixSum[i] >= mod)
            prefixSum[i] -= mod;
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll ans = prefixSum[r] - prefixSum[l - 1];
        if (ans < 0)
            ans += mod;
        ans = ans * power(powerK[l], mod - 2) % mod;
        cout << ans << "\n";
    }
}
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// int mod = 1e9 + 7;
// ll power(ll x, ll y)
// {
//     ll res = 1;
//     while (y)
//     {
//         if (y & 1)
//             res = (res * x) % mod;
//         y = y / 2, x = (x * x) % mod;
//     }
//     return res % mod;
// }

// void solve()
// {
//     int n, q, k;
//     cin >> n >> q >> k;
//     ll a[n + 1], powerK[n + 1];
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];
//     powerK[1] = 1;
//     for (int i = 1; i < n; i++)
//         powerK[i + 1] = k * powerK[i] % mod;
//     for (int i = 1; i < n; i++)
//     {
//         a[i] = (a[i] * powerK[i]) % mod;
//         // a[i + 1] = ((a[i + 1] % mod) + ((a[i] % mod) * (power(k, i) * mod) % mod)) % mod;
//         if (a[i] < 0)
//             a[i] += mod;
//     }
//     a[0] = 0;
//     for (int i = 1; i <= n; i++)
//         a[i] += a[i - 1];
//     for (int i = 1; i <= n; i++)
//     {
//         int l, r;
//         cin >> l >> r;

//         ll ans = a[r] - a[l - 1];
//         if (ans < 0)
//             ans += mod;
//         ans = ans * (power(k, mod - 2)) % mod;
//         // cout << (pow(k, -l) * (a[r] - a[l - 1]) + mod) % mod << endl;
//         cout << ans << endl;
//     }
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     solve();
// }
