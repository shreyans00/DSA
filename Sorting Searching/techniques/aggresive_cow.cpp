#include <bits/stdc++.h>
using namespace std;

bool check(int a[], int n, int cows, int minDist)
{
    int cntCows = 1, lastPlacedCow = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] - lastPlacedCow >= minDist)
        {
            cntCows++;
            lastPlacedCow = a[i];
        }
    }
    return (cntCows >= cows);
}
int main()
{
    int n = 5, cows = 3;
    int a[] = {1, 2, 8, 4, 9};
    sort(a, a + n);

    int low = 1, high = a[n - 1] - a[0]; // maxm distance possible is a[n-1]-a[0], min is 1 (we identified the search space & is monotonic)

    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (check(a, n, cows, mid))
            low = mid + 1; // hmne isme cntCows jyada mil rha hai mtlb hm thora aage jake dekh skte hai kyunki largest min nikalna hai
        else
            high = mid - 1;
    }
    cout << "The largest minimum distance is " << high << endl;
}

