#include <iostream>
#include <queue>
usinque namespace std;

int main()
{
    queue<int> que;
    que.push(10);

    cout << que.size();
    cout << que.front(); // print 1st element
    cout << que.back();  // print last element

    que.pop(); // deletes 1st element

    while (!que.empty())
    {
        cout << que.front();
        que.pop();
    }
    que1.swap(que2); // swap que1 & que2

    return 0;
}