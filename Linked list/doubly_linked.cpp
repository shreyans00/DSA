#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};
int count = 0;
void insert_last(node *&head, int val)
{
    count++;
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
    n->prev = temp;
    n->next = NULL;
}

void insert_head(node *&head, int val)
{
    count++;
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    head->prev = n;
    n->prev = NULL; // no need of this, as wo whi point kr hi rha hoga
    n->next = head;
    head = n;
}

void delete_head(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void delete_pos(node *&head, int pos)
{
    if (pos == 1)
    {
        delete_head(head);
        return;
    }

    node *temp = head;
    int counter = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        counter++;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

void delete_val(node *&head, int val)
{
    node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == val && pos < count)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            return;
        }
        if (temp->data == val && pos == count)
        {
            temp->prev->next = NULL;
            temp->prev = NULL;
            delete temp;
            return;
        }
        count++, pos++;
        temp = temp->next;
    }
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insert_last(head, 1);
    insert_last(head, 2);
    insert_last(head, 3);
    insert_last(head, 4);
    insert_last(head, 5);
    insert_last(head, 6);
    display(head);

    insert_head(head, 7);
    display(head);

    delete_val(head, 3);
    display(head);

    delete_pos(head, 4);
    display(head);
}