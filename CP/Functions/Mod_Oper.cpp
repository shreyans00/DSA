// Modulo Operations

int sign = (A < 0 && B > 0) || (A > 0 && B < 0) ? -1 : 1;

inline void add(int &a, int b)
{
    a += b;
    if (a >= mod1)
        a -= mod1;
}

inline void sub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += mod1;
}

inline int mul(int a, int b)
{
    return (int)((long long)a * b % mod1);
}

inline int power(int a, long long b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

inline int inv(int a)
{
    a %= mod1;
    if (a < 0)
        a += mod1;
    int b = mod1, u = 0, v = 1;
    while (a)
    {
        int t = b / a;
        b -= t * a;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    assert(b == 1);
    if (u < 0)
        u += mod1;
    return u;
}