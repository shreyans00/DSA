#include <iostream>
using namespace std;
#define n 100

class queue
{
    int front, back;
    int *arr;

public:
    queue()
    {
        front = -1;
        back = -1;
        arr = new int[n];
    }

    void enqueue(int val)
    {
        if (back == n - 1)
        {
            cout << "queue overflow" << endl;
        }
        else
        {
            back++;
            arr[back] = val;
        }
        if (front = -1)
        {
            front++; // for inserting first element, both front and back increase but later on only back increase
        }
    }
    void dequeue()
    {
        if (front == -1 || front > back) // front>back when all items are pop out
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            front++;
        }
    }
    int peer()
    {
        if (front == -1 || front > back)
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front]; // element which pop
    }
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << q.peer() << endl;
    q.dequeue();
    cout << q.peer() << endl;
    q.dequeue();
    cout << q.empty() << endl;
    q.dequeue();
    q.dequeue();
    q.peer();
    cout << q.empty() << endl;
}