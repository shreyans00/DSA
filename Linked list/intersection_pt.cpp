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

void make_intersection(node *&head1, node *&head2, int pos)
{
    // My method
    node *temp = head1;
    node *temp2 = head2;
    int reach = 1;
    while (--pos)
    {
        temp = temp->next;
        // reach++;
    }
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp->next;

    // Apna cllg method
    // node *temp1 = head1;
    // while (--pos)
    // {
    //     temp1 = temp1->next;
    // }

    // node *temp2 = head2;
    // while (temp2->next != NULL)
    // {
    //     temp2 = temp2->next;
    // }

    // temp2->next = temp1;
}

int intersection(node *head1, node *head2)
{
    // My method
    int diff = abs(length(head1) - length(head2));
    int pos = 1;
    node *temp = head1;
    node *temp2 = head2;
    while (pos <= diff)
    {
        temp = temp->next;
        pos++;
    }
    while (temp != NULL || temp2 != NULL)
    {
        if (temp->next == temp2->next)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
        temp2 = temp2->next;
    }

    // Apna cllg method
    // int l1 = length(head1);
    // int l2 = length(head2);
    // int d = 0;
    // node *ptr1;
    // node *ptr2;
    // if (l1 > l2)
    // {
    //     d = l1 - l2;
    //     ptr1 = head1;
    //     ptr2 = head2;
    // }
    // else
    // {
    //     d = l2 - l1;
    //     ptr1 = head2;
    //     ptr2 = head1;
    // }

    // while (d)
    // {
    //     ptr1 = ptr1->next;
    //     if (ptr1 == NULL)
    //     {
    //         return -1;
    //     }
    //     d--;
    // }

    // while (ptr1 != NULL && ptr2 != NULL)
    // {
    //     if (ptr1 == ptr2)
    //     {
    //         return ptr1->data;
    //     }
    //     ptr1 = ptr1->next;
    //     ptr2 = ptr2->next;
    // }

    // return -1;
}

int main()
{
    node *head1 = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insert_tail(head1, arr[i]);
    }

    node *head2 = NULL;
    int arr2[] = {9, 10};
    for (int i = 0; i < 2; i++)
    {
        insert_tail(head2, arr2[i]);
    }

    make_intersection(head1, head2, 3);
    display(head1);
    display(head2);

    cout << intersection(head1, head2);
}