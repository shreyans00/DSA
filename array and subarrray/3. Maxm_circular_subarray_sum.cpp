// Max subarray sum = Total sum of array - Sum of non-contributing elements
// {4,-4,6,-6,10,-11,12}-sum=11     for non-contributing, {-4,4,-6,6,-10,11,-12}-sum=-11
//   max = 11 - (-11) = 11 + 11 = 22 (12+4-4+6-6+10)

#include <iostream>
#include <climits>
using namespace std;

// function to find maxm sum of a subarray
int kadane(int a[], int n)
{
    int maxsum = INT_MIN;
    int cursum = 0;
    for (int i = 0; i < n; i++)
    {
        cursum += a[i];
        if (cursum < 0)
        {
            cursum = 0;
        }
        maxsum = max(maxsum, cursum);
    }
    return maxsum;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int wrapsum, nonwrapsum;
    nonwrapsum = kadane(a, n);
    cout << nonwrapsum << " : nonwrapsum" << endl;

    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += a[i];
        a[i] = -a[i]; // to reverse the sign of each element of the array
    }
    cout << totalsum << " : totalsum" << endl;
    int noncontrsum = -kadane(a, n); // to find min sum of the subarray
    cout << noncontrsum << " : noncontrsum" << endl;
    wrapsum = totalsum - noncontrsum;
    cout << wrapsum << " : wrapsum" << endl;
    cout << max(wrapsum, nonwrapsum) << endl;
}

/*
Test Case:
7
-4 4 6 -6 10 -11 12
*/