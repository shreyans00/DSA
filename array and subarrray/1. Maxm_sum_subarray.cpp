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

    // Time complexity : O(n3)
    // The variables i and j fix the first and last index of the subarray, and the sum of values is calculated to the variable sum which is compared with the best so far.
    // This never gives a negative sum
    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += a[k];
                }
                best = max(best, sum);
            }
        }
    }
    cout << best << "\n";

    // Time complexity : O(n2)  by cummulative sum approach

    // int curr_sum[n + 1];
    // curr_sum[0] = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     curr_sum[i] = curr_sum[i - 1] + a[i - 1];
    // }

    // int maxsum = INT_MIN;
    // for (int j = 1; j <= n; j++)
    // {
    //     int sum = 0;
    //     for (int k = 0; k < j; k++)
    //     {
    //         sum = curr_sum[j] - curr_sum[k];
    //         maxsum = max(sum, maxsum);
    //     }
    // }

    // Time complexity : O(n2) by calculating the sum at the same time when the right end of the subarray moves

    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            maxsum = max(maxsum, sum);
        }
    }
    cout << maxsum << endl;
    return 0;
}

/* Test Cases:
8
-1 20 4 -3 5 2 -5 -40

8
-1 -2 -4 -3 -5 -2 -5 -2
*/