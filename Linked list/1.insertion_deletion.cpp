#include <iostream>
using namespace std;

// In linked list, we have a head pointer pointing to 1st node(val+pointer which pointing to 2nd node) and so on.... and the last pointer points to null
// For adding elements, we take value from user and create a new node in function only which has that value but pointer to next value.
// Head is used to access any linked list, head ka pta rakho baki apne aap link bna rha hai

class node
{
public:
    int data;   // koi aur bhi data_type de skte hai
    node *next; // isse hm next element ko point krenge
    node(int val)
    {
        data = val;
        next = NULL; // by default koi bhi new node null ko point krega
    }
};

void insert_tail(node *&head, int val) // we take address of head pointer as we need to change it
{
    node *n = new node(val); // n is pointing to a new node with value=val

    if (head == NULL)
    {
        head = n; // head takes both value and address of n, everything is copied
        return;
    }

    node *temp = head;         // temp is pointing to very first node head, basically head is being copied to temp
    while (temp->next != NULL) // agar kisi position pe insert krna hota to loop pos-1 tk le jao, that's the only change alonwith this condition.
    {
        temp = temp->next;
    }
    // n->next = temp->next;   // Kisi position pr krna hai to ye code bhi hoga
    temp->next = n; // inserting the last node, temp->next has a pointer next pointing to n
                    // if we use temp instead, then its old value overrid with new one
}

void insert_head(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    n->next = head; // n ka next usko point krega jisko head point kr rha tha
    head = n;       // aur head n ko point krne lgega
}

int getNthNodeFromEnd(node *&head, long int n) // same as gettting (tot_count - n) from start
{
    node *temp = head;
    long int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++; // from this, we get total count of linked list
    }

    temp = head;
    long int st = count - n;
    while (st--)
    {
        temp = temp->next;
    }
    return temp->data;
}

void display(node *head) // we don't need address of head as we don't need to change it
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "Null" << endl;
}

void delete_head(node *&head)
{
    node *to_del = head;
    head = head->next; // sirf head ko head->next krne se head nhi htega pehle wale ko delete bhi krna hoga
    delete to_del;
}

void deletion(node *&head, int val) // delete a node with given val assuming distinct elements
{
    if (head == NULL)
        return;

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *to_del = temp->next;
    temp->next = temp->next->next;
    delete to_del;
}

int main()
{
    node *head = NULL;

    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    display(head);

    insert_head(head, 4);
    display(head);

    cout << getNthNodeFromEnd(head, 3) << endl;

    deletion(head, 2);
    display(head);

    delete_head(head);
    display(head);
}