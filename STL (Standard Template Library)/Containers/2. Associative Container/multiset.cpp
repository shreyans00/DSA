// Same as set but can have same values
// fn : begin, end, size, max_size, empty, count, erase, find (same as set)

#include <bits./stdc++.h>
using namespace std;

void display(multiset<int, greater<int>> ms)
{
    multiset<int, greater<int>>::iterator itr;
    cout << "\nThe multiset ms is : \n";
    for (itr = ms.begin(); itr != ms.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    // empty multiset container: simply can make
    // multiset<int> ms;
    multiset<int, greater<int>> ms; // greater is used for descending order

    // insert elements in random order
    ms.insert(40);
    ms.insert(40);
    ms.insert(30);
    ms.insert(60);
    ms.insert(20);

    display(ms);
    cout << ms.count(40) << endl;

    // assigning the elements from ms to ms2
    multiset<int> ms2(ms.begin(), ms.end());

    // remove all elements up to element with value 40 in ms
    ms.erase(ms.begin(), ms.find(40));
    display(ms);

    // remove all elements with value 20 in ms
    int num = ms.erase(20);
    cout << num << " removed \n";
    display(ms);

    //lower bound and upper bound for multiset ms
    cout << *ms.lower_bound(40) << endl;
    cout << *ms.upper_bound(40) << endl;
}