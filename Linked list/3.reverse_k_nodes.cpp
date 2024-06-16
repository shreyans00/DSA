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

node *reverse(node *&head, int k = 2) // here k=2 means 2 nodes reverse at a time
{
    if (head == NULL)
    {
        return NULL;
    }
    node *newhead = reverse(head->next->next);
    node *prev = head->next;
    prev->next = head;
    head->next = newhead;
    return prev;
}

node *reverse_k(node *&head, int k) // saare nodes ko reverse krenge, but ek baar mai k nodes ko
{
    if (head == NULL)
        return NULL;

    node *prev = NULL, *current = head, *Next;
    int count = 0;
    while (count < k && current != NULL) // jb tk count k se chota hai && beech mai hi current null nhi ho tb tk reverse krte jao
    {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
        count++;
    }
    if (Next != NULL) // agr next null nhi hai to fir k nodes ko ek saath reverse kro
        head->next = reverse_k(Next, k);

    return prev; // ye newhead bn jayega
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

    // node *newhead = reverse(head);
    // display(newhead);

    int k = 3;
    node *newhead2 = reverse_k(head, k);
    display(newhead2);
}