// binary search in non-decreasing sorted array
// If random iterator is there: O(log n), otherwise O(n)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 5, 5, 8, 11, 14};
    int val = 8;
    cout << binary_search(a, a + 8, val) << endl;

    return 0;
}