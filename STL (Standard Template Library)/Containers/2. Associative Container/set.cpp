// Set is like an "always sorted" array (binary search tree actually)
// Operations : insert, count(gives occurrence of a number), erase
// insert/erase : O(log n)
// Initialize with unsorted sequence : O(n log n)
// Initialize with sorted sequence : O(n)

#include <bits./stdc++.h>
using namespace std;

int main()
{
    set<int> s = {1, 12, 9, 3};

    s.insert(3); // no use of inserting this as set doesn't have repeating elements
    s.insert(2);
    s.insert(7);
    cout << *s.begin() << endl;
    cout << *s.rbegin() << endl; // it is in sorted form only

    cout << s.size() << '\n';

    s.erase(s.find(9)); // s.find(a) returns an iterator which points to the element after the deleted one
    // s.erase(s.find(8)); // If the element is not found, then the iterator points to the position just after the last element in the set
    s.erase(3); // erase the element 3 from the set & returns an iterator which points to the element after the deleted one

    for (auto i : s)
    {
        cout << i << " "; // it always print in a shorted order
    }
    cout << '\n';

    cout << s.count(3) << "\n\n"; // count either returns 0 or 1 (since set terminate duplicates), but in multiset, it return the frequency

    // Declaring pair for returning value of set containing set iterator & bool
    pair<set<int>::iterator, bool> ptr;
    ptr = s.insert(5);
    cout << ptr.second << endl; // return true(1) if new inserted & false(0) if already present
    cout << s.insert(5).second << endl
         << endl;

    vector<int> v{1, 3, 5, 7, 9, 11};
    set<int> st(v.begin(), v.end()); // O(n) bcoz the range is already sorted
    int val = 7;
    auto it = st.lower_bound(val);
    if (it != st.end())
    {
        // prints the smallest key>=x;
        cout << *it << endl;
    }
    else
    {
        // x is greater than every key
        cout << "None" << endl;
    }
}