// Fast binary exponentiation for a^b.
// Here, mod is for keeping in check that number does not overflow.

// pow(a,b) O(log b), not O(b)

// int
int binExp(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = (1LL * ans * a) % mod1;
        }
        a = (1LL * a * a) % mod1;
        b /= 2;
    }
    return ans;
}

// long long
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

// long long
int binpow(int b, int p, int mod)
{
    int ans = 1;
    b %= mod;
    for (; p; p >>= 1)
    {
        if (p & 1)
            ans = ans * b % mod;
        b = b * b % mod;
    }
    return ans;
}