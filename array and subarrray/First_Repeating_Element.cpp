// Program to find the index(start from 1) of first repeating element in the array with time complexity < O(n2)

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int N = 10; // the value of N can't be changed later
    int b[N];
    for (int i = 0; i < N; i++)
    {
        b[i] = -1;
    }
    int min_idx = -1;
    for (int i = 0; i < n; i++)
    {
        int m = a[i];
        if (b[m] != -1)
        {
            min_idx = i;
            break;
        }
        else
        {
            b[m] = i;
        }
    }
    if (min_idx == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_idx + 1 << endl;
    }
    return 0;
}

/* 
Test case:
6
5 8 4 8 5 4
*/