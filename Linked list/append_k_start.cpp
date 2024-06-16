// Program to append last k nodes of linked list in starting

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

void insert_tail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node *append_k(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;
    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL) // tail wahan ruke jahan khatm ho rha ho linked list
    {
        if (count == l - k)
        {
            newTail = tail; // we fix newTail in its posn (see fig, apna cllg)
        }
        if (count == l - k + 1)
        {
            newHead = tail; // we fix newHead in its posn (see fig, apna cllg)
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main()
{
    node *head = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insert_tail(head, arr[i]);
    }
    display(head);

    node *newhead = append_k(head, 3);
    display(newhead);
}