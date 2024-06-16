#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
#define bitcount(x) __builtin_popcountll(x)
#define setbit(x, i) (x | (1LL << i))
#define unsetbit(x, i) (x & (~(1LL << i)))
#define flipbit(x, i) (x ^ (1LL << i))
#define checkbit(x, i) ((x >> i) & 1LL)
#define msb(x) (63 - (__builtin_clzll(x)))
#define lsb(x) ((__builtin_ctzll(x)))
#define itob(x) bitset<64>(x).to_string()

const int mod = 1e9 + 7;

void solve()
{
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
    return 0;
}