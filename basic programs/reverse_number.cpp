// Program to reverse a number

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp = 0;
    cin >> n;
    while (n > 0)
    {
        temp = temp * 10 + n % 10;
        n = n / 10;
    }
    cout << temp << endl;
    return 0;
}