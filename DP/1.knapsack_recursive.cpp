#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, int wt[], int val[])
{
    if (w == 0 || n == 0)
        return 0;
    if (wt[n - 1] <= w)
        return max(val[n - 1] + knapsack(n - 1, w - wt[n - 1], wt, val), knapsack(n - 1, w, wt, val));
    else
        return knapsack(n - 1, w, wt, val);
}
int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 10;
    cout << knapsack(4, w, wt, val);
}
