// Program to calculate the frequency of a particular element in an array
// Time Complexity : O(n)

#include <bits./stdc++.h>
using namespace std;

int main()
{
    int a[] = {4, 2, 5, 4, 2, 4, 5, 4, 2};
    int i = 0, count = 0, val = 4;
    int n = sizeof(a) / sizeof(a[0]);
    while (i < n)
    {
        while (i < n and a[i] != val)
            i++;
        if (i < n)
        {
            count++;
            i++;
        }
    }
    cout << count << endl;
}