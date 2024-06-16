// Hash table implementation
// Not sorted, unordered, can't perform binary search
// Average: O(1)   Worst: O(n)
// When size>=no. of buckets(load factor=1), capacity increases(~2x) & all the elements are rehashed

// In order to use unordered_set/map, classes must have hash function implemented (compiler implement for int, double, string, but not for pair, so have to create custom hashes for them)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3] = {1, 2, 3};
    cout << &a[0] << endl;
    a[0] = 6;
    cout << &a[0] << endl;
    a = {2, 3, 4};
    cout << &a[0] << endl;
}
