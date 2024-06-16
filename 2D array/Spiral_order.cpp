// Program to prints the elements of 2-D array in spiral fashion

#include <iostream>
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
    int uprow = 0, lowrow = n - 1, rigcol = m - 1, lefcol = 0;
    while (lowrow >= uprow && rigcol >= lefcol) // with the help of this loop, after completing one round, round repeats
    {
        // for upper_row
        for (int col = lefcol; col <= rigcol; col++)
        {
            cout << a[uprow][col] << " ";
        }
        uprow++;

        // for right_column
        for (int row = uprow; row <= lowrow; row++)
        {
            cout << a[row][rigcol] << " ";
        }
        rigcol--;

        // for lower(last)_row
        for (int col = rigcol; col >= lefcol; col--)
        {
            cout << a[lowrow][col] << " ";
        }
        lowrow--;

        // for left_column
        for (int row = lowrow; row >= uprow; row--)
        {
            cout << a[row][lefcol] << " ";
        }
        lefcol++;
    }
}

/*
Test Case:
4
4 
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/