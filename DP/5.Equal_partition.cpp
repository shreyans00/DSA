#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int *arr, int n, int sum)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < sum + 1; j++)
        {
            if (i == 0 && j != 0)
                t[i][j] = 0;
            else if (j == 0)
                t[i][j] = 1;
            else if (arr[i - 1] <= j)
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4};
    int sum = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
        sum += arr[i];
    if (sum % 2 == 0)
        cout << subset_sum(arr, 5, sum / 2);
    else
        cout << 0;
}
