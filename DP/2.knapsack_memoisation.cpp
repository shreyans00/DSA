#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, int wt[], int val[], int **t)
{
    if (w == 0 || n == 0)
        return 0;
    if (t[n][w] != -1)
        return t[n][w];
    if (wt[n - 1] <= w)
        return t[n][w] = max(val[n - 1] + knapsack(n - 1, w - wt[n - 1], wt, val, t), knapsack(n - 1, w, wt, val, t));
    else
        return t[n][w] = knapsack(n - 1, w, wt, val, t);
}
int main()
{
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int w = 10;
    int t[102][1002];
    memset(t, -1, sizeof(t));
    cout << knapsack(4, w, wt, val, t);
    cout << t[4][w];
}
