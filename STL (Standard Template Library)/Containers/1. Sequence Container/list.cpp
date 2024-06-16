// Implements bidirectional linked list

#include <bits/stdc++.h>
#include <list>

using namespace std;

void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void display_reverse(list<int> &lst)
{
    for (auto it = lst.rbegin(); it != lst.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{

    list<int> list1; //empty list of 0 length

    // pushing elements front & back into the list
    list1.push_back(5);
    list1.push_back(7);
    list1.push_back(9);
    list1.push_back(1);
    list1.push_back(9);
    list1.push_front(8);
    list1.push_front(3);
    list1.push_front(1);
    list1.push_front(6);

    display(list1);
    display_reverse(list1);

    // Poping out elements from the list
    list1.pop_back();
    display(list1);
    list1.pop_front();
    display(list1);
    list1.remove(9); // remove all 9
    display(list1);

    // Sorting the list
    list1.sort();
    // can't use sort(l.begin(),l.end()) because l.begin() & l.end() return BiDirIt(Bi-Directional Iterators) instead of RndAccIt(Random Access Iterators)
    display(list1);

    // Reversing the list
    list1.reverse();
    display(list1);

    cout << endl;
    list<int> list2(3); //empty list of length 3
    list<int>::iterator it = list2.begin();
    *it = 7;
    it++;
    *it = 6;
    it++;
    *it = 9;
    it--;

    it = list2.insert(it, 12); //insert 12 before the element pointed by "it", returns an iterator pointing to the element inserted
    display(list2);

    it = list2.erase(it); // remove the element pointed by "it", returns an iterator pointing to the next element after it
    display(list2);

    // Time complexity of insert & erase is O(n)

    // Merging list 1 and 2
    list1.merge(list2);
    cout << "List after merging: ";
    display(list1);

    return 0;
}
