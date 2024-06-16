#include <bits/stdc++.h>
using namespace std;

int subset_sum_diff(int *arr, int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
        range += arr[i];
    bool t[n + 1][range + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < (range + 1) / 2 + 1; j++)
        {
            if (i == 0 & j != 0)
                t[i][j] = 0;
            else if (j == 0)
                t[i][j] = 1;
            else if (arr[i - 1] <= j)
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
            else
                t[i][j] = t[i - 1][j];
        }
    }
    int diff = INT_MAX;
    for (int i = range / 2; i >= 0; i--)
    {
        if (t[n][i] == 1)
        {
            diff = range - 2 * i;
            break;
        }
    }
    return diff;
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << subset_sum_diff(arr, n);
}
