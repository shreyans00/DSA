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

node *reverse(node *&head) // this function doesn't made changes on the head, so we can still have head and can use further  -->> preferred
{
    node *prev = NULL, *current = head, *Next;
    while (current != NULL)
    {
        Next = current->next; // current ke baad wale element ko hmne store kr liya
        current->next = prev; // current ka next aab prev ko point krega taki reverse ho jaye
        prev = current;       // prev current ko point krega taki hm current ko aage badha ske
        current = Next;       // current ko aage badha diya
    }
    return prev; // prev newhead bn jayega at last, aur hm head se hi to pura Linked link access krte hai
}

void reverse2(node *&head) // this function made changes on the head
{
    node *prev = NULL, *current = head, *Next;
    while (current != NULL)
    {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;
    }
    head = prev;
    return;
}

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL) // ya to list khali ho ya to ek element ho
        return head;

    node *newhead = reverseRecursive(head->next); // newhead points to the last element
    // head ka next ke baad reverse to recursion ne krke de diya
    // kisi bhi recursive call ke baad newhead ko position change nhi hoga
    head->next->next = head; // head ke baad ko hm wapas head pr hi point kra denge, link ka tension mt lo reverse ho chuka hai list
    head->next = NULL;       // head aab null ko point krega
    return newhead;
}

int main()
{
    node *head = NULL;

    insert_tail(head, 1);
    insert_tail(head, 2);
    insert_tail(head, 3);
    display(head);

    // node *newhead = reverse(head);
    // display(newhead);
    // node *backhead = reverse(newhead); // to get the previous one
    // display(backhead);

    // reverse2(head);
    // display(head);
    // reverse2(head);   // to get the previous one
    // display(head);

    node *newhead2 = reverseRecursive(head);
    display(newhead2);
}

/*
    1  -->   2   -->   3  -->   4
    |                           |
    |                           |
   head                       newhead

head stores the address of 1, head->next stores the address of 2 and head->next->next stores the address of 3

*/