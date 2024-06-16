
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{1, 4, 2, 8, 5, 7};
    // To use lower/upper bound, we need to sort first
    sort(v.begin(), v.end()); // 1 2 4 5 7 8
    vector<int>::iterator it1 = lower_bound(v.begin(), v.end(), 2);
    auto it2 = upper_bound(v.begin(), v.end(), 10);
    cout << distance(v.begin(), it1) << endl;
    cout << distance(v.begin(), it2) << endl;

    cout << *it2 << endl; // this give some strange value
    // So, check whether it2 is an end or not
    if (it2 != v.end() && *it2 == 10)
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
}
