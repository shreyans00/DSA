// Program to find a unique number in an array where all numbers except one, are present twice

#include <iostream>
using namespace std;

int unique(int a[], int n)
{
    int xorsum = 0;
    for (int i = 0; i < n; i++)
        xorsum = xorsum ^ a[i];
    return xorsum;
}

/*
    Let any number be n, then n^n = 0
    So those who repeated twice have total xorsum=0 
    and only unique number left in xorsum
*/

int main()
{
    int a[] = {2, 4, 6, 3, 4, 6, 2};
    cout << unique(a, 7) << endl;
    return 0;
}