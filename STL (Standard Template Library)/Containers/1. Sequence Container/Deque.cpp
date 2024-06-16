/*
Deque (Double ended queue)
- push and pop from the back as well as front : O(1)
- random access to any element : O(1)
- insert and delete from front
- Header file: <deque>
- supoorts both max heap & min heap
- getMax O(1), getMin O(1), deleteMax O(log n), deleteMin O(log n), size O(1), isEmpty O(1)

We can try two heaps (min heap and max heap). We maintain a pointer of every max heap element in min heap. To get minimum element, we simply return root. To get maximum element, we return root of max heap. To insert an element, we insert in min heap and max heap both. The main idea is to maintain one to one correspondence, so that deleteMin() and deleteMax() can be done in O(Log n) time.
*/

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq{6, 8, 9};
    dq.push_back(1);
    dq.push_front(3);

    for (auto i : dq)
        cout << i << " ";
    cout << endl;

    // Can also access the elements through
    cout << dq[2] << endl;

    dq.pop_back();
    dq.pop_front();

    for (auto i : dq)
        cout << i << " ";
    cout << endl;

    cout << dq.size() << endl;
}