// Implementation of a max heap (arrange the elements in ascending order)

#include <bits/stdc++.h>
#include <queue>
#include <functional>
using namespace std;

struct student
{
    string name;
    int height;
    bool operator<(const student &o) const
    {
        return height > o.height;
    }
};

int main()
{
    priority_queue<int> pq;
    // normally it arranges in ascending order (maxm heap)
    pq.push(2);
    pq.push(1);
    pq.push(3);
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    // To implement minm heap (arrange the elements in descending order)

    // Method 1
    priority_queue<string, vector<string>, greater<string>> pq2;
    // "greater"(custom comparison function) is used to arrange the elements in descending order (minm heap)
    pq2.push("Grape");
    pq2.push("Apple");
    pq2.push("Banana");
    cout << pq2.top() << endl;

    // Method 2
    priority_queue<int> pq3;
    pq3.push(-2);
    pq3.push(-1);
    pq3.push(-3);
    int actual = -pq3.top();
    cout << actual << endl;

    // Method 3
    priority_queue<student> pq4;
    pq4.push(student{"Ram", 75});
    pq4.push(student{"Sita", 70});
    cout << pq4.top().height << endl;
}