// Program to find first N prime numbers

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long int N;
    cin >> N;
    int n = 1;
    while (N > 0)
    {
        bool flag = 0;
        if (n == 1)
        {
            flag = 1;
        }
        else if (n == 2)
        {
            flag = 0;
        }
        else
        {
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            cout << n << " ";
            N--;
        }
        n++;
    }
    return 0;
}