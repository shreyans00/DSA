#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(int val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "queue underflow" << endl;
        }
        node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peer()
    {
        if (front == NULL)
        {
            cout << "queue underflow" << endl;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            return 1;
        }
        return 0;
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