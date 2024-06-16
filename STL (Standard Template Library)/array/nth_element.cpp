// Use of nth_element(quick select algorithm) : rearranges in such a way that the element at the nth position is at its right position if we sort the list.
// Average case: O(n)      Worst Case: O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {14, 11, 3, 4, 2, 5, 1, 25};
    nth_element(a, a + 3, a + 7); // nth_element(l,nth,r)
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}