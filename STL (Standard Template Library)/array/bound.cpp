// lower_bound : finds the left-most elements >=val in a sorted array, basically returns number of elements smaller than val
// upper_bound : finds the left-most elements >val
// Only difference between the two is "=" sign

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 5, 5, 8, 11, 14};
    int val = 8;
    cout << distance(a, lower_bound(a, a + 8, val)) << endl;
    cout << lower_bound(a, a + 8, 20) - a << endl;
    // can be called in either of the above 2 ways

    cout << distance(a, upper_bound(a, a + 8, val)) << endl;
    cout << upper_bound(a, a + 8, 7) - a << endl;
    return 0;
}