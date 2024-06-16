#include <iostream>
#include <cmath>
using namespace std;

bool Isprime(int a)
{
    if (a == 1)
        return 0;
    else if (a == 2)
        return 1;
    else
    {
        for (int i = 2; i < a; i++)
        {
            if (a % i == 0)
                return 0;
        }
    }
    return 1;
}

long long int gcd(long long int a, long long int b)
{
    // if (a == 0) // a=0 tb hoga jb a%b=0 ho jaye yani a completely divide ho jaye b se ya jb a<b ho jaye
    //     return b;
    // if (b == 0)
    //     return a;
    // return gcd(b, a % b);
    // if (a > b)
    //     return gcd(a % b, b);
    // else
    //     return gcd(a, b % a);

    // One line code:
    return b == 0 ? a : gcd(b, a % b);
}

long long int lcm(long long int a, long long int b) return (a * b) / gcd(a, b);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, gcd = 1;
        cin >> a >> b;

        for (int i = 2; i <= a && i <= b; i++)
        {
            if (i > gcd && a % i == 0 && b % i == 0)
                gcd = i;
        }
        cout << gcd << " ";

        // int lcm = (a * b) / gcd;
        // cout << lcm << endl;

        int mult1 = 1, mult2 = 1, i = 2;
        int a1 = a, b1 = b;
        while (i <= a || i <= b)
        {
            if (Isprime(i))
            {
                if (a % i == 0 && b % i != 0)
                {
                    mult1 *= i;
                    a /= i;
                }
                if (b % i == 0 && a % i != 0)
                {
                    mult2 *= i;
                    b /= i;
                }
                if (a % i != 0 && b % i != 0)
                    i++;
                if (a % i == 0 && b % i == 0)
                {
                    a /= i;
                    b /= i;
                }
            }
            else
                i++;
        }
        int lcm = a1 * mult2;
        cout << lcm << endl;
    }
    return 0;
}