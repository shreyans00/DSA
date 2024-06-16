// rearranges the range to form the next lexicographically greater permutation (not all permutation)
// returns false when the elements are in non-increasing order

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    do
    {
        for (int i = 0; i < 5; i++)
        {
            cout << a[i] << (i == 4 ? '\n' : ' ');
        }
    } while (next_permutation(a, a + 5));
    return 0;
}