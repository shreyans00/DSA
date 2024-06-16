// Let's try to optimise it to O(n) by Kadane's Algorithm

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

    // Method 1
    int currsum = 0, maxsum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum += a[i];
        if (currsum < 0)
        {
            currsum = 0;
        }
        maxsum = max(maxsum, currsum);
    }
    if (maxsum == 0)
    {
        cout << "there is no positive element in the array" << endl;
    }
    else
    {
        cout << maxsum << endl;
    }

    // Method 2
    int best = 0, sum = 0;
    for (int k = 0; k < n; k++)
    {
        sum = max(a[k], sum + a[k]); // sum+a[k] krne se jyada milega ya uss subarr ko htakr ek naya bnaye jo a[k] se start hoga
        best = max(best, sum);
    }
    cout << best << "\n";

    return 0;
}