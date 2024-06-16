// Put n items with given weight and value in a knapsack of capacity W to get the maximum total value in the knapsack

#include <iostream>
using namespace std;

int knapsack(int n, int W, int val[], int wt[])
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapsack(n - 1, W, val, wt); // if weight of an item exceeds W, then we can't include that item
    }
    return max(knapsack(n - 1, W - wt[n - 1], val, wt) + val[n - 1], knapsack(n - 1, W, val, wt)); // max(value when item included, value when item not included)
}

int main()
{
    int weight[] = {10, 20, 30, 54, 50};
    int value[] = {100, 50, 150, 3000, 400};
    int Wmax = 50;
    cout << knapsack(5, Wmax, value, weight) << endl;
}