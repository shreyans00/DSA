// Merge 2 sorted linked list

// To find intersection point of 2 linked lists

#include <iostream>
#include <cmath>
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

node *merge(node *&head1, node *&head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *dummyNode = new node(-1); //dummy head (very important step)
    node *newhead = dummyNode;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            // newhead->data = temp1->data;     no need of this, it automatically takes its value using pointer
            newhead->next = temp1;
            temp1 = temp1->next;
            newhead = newhead->next;
        }
        else
        {
            newhead->next = temp2;
            temp2 = temp2->next;
            newhead = newhead->next;
        }
    }
    while (temp1 != NULL)
    {
        newhead->next = temp1;
        temp1 = temp1->next;
        newhead = newhead->next;
    }

    while (temp2 != NULL)
    {
        newhead->next = temp2;
        temp2 = temp2->next;
        newhead = newhead->next;
    }

    return dummyNode->next;
}

node *mergeRecursive(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main()
{
    node *head1 = NULL;
    int arr[] = {1, 3, 5, 7};
    for (int i = 0; i < 4; i++)
    {
        insert_tail(head1, arr[i]);
    }

    node *head2 = NULL;
    int arr2[] = {2, 4, 5, 6, 9};
    for (int i = 0; i < 5; i++)
    {
        insert_tail(head2, arr2[i]);
    }

    // node *mer = merge(head1, head2);
    // display(mer);

    node *merRec = mergeRecursive(head1, head2);
    display(merRec);
}