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

void make_cycle(node *&head, int pos)
{
    node *slow = head;
    node *link; // this points to the same position so that it forms a link
    int count = 1;
    while (slow->next != NULL)
    {
        if (count == pos)
            link = slow; // ye pos ka address hm link mai daal denge

        slow = slow->next; // slow ko to end tk le jayenge
        count++;
    }
    slow->next = link; // slow->next ko null ko nhi point krake link se point kra denge
}

bool check_cycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next; // isko double speed se bhagayenge

        if (fast == slow)
            return true;
    }
    return false;
}

void remove_cycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow->next == fast->next);

    slow->next = NULL;
}

int main()
{
    node *head = NULL;

    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    insert_tail(head, 4);
    insert_tail(head, 5);
    insert_tail(head, 6);
    // display(head);

    make_cycle(head, 2);
    // display(head);
    cout << check_cycle(head) << endl;

    remove_cycle(head);
    cout << check_cycle(head) << endl;
}