#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long int n;
    cin >> n;
    long long int sum = 0;
    long long int complementary;
    for (long long int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                sum += i;

            else
            {
                complementary = n / i;
                sum += i;
                sum += complementary;
            }
        }
    }
    sum -= n;

    if (sum == n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}