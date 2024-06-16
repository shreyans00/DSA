// Program to search an element in the 2D array with time complexity O(n)
// Condn: Array should be sorted row and column wise respectively

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; // rows,column
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int target;
    cin >> target;

    bool flag = 0;
    int r = 0, c = m - 1; // we can start from top right or bottom left corners only since one closest member should be greater and one should be lesser
    while (r < n && c >= 0)
    {
        if (a[r][c] == target)
        {
            flag = 1;
            break;
        }
        else if (a[r][c] > target)
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    if (flag == 1)
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }
}

/*
Test Case:
3 4

1 2 3 4
5 6 7 8
9 10 11 12
4

*/