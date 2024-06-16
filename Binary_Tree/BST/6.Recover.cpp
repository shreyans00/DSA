#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void calcPointers(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root == NULL)
        return;
    // Inorder hai to pehle call lgayenge root ke left subtre ki taraf
    calcPointers(root->left, first, mid, last, prev);

    // yahan check krenge violation ho rha hai ya nhi aur agr ho rha hai to pehle baar ya dusri baar
    if (*prev && root->data < (*prev)->data)
    {
        if (!*first) // agr first time violate ho rhi hogi to first null hoga
        {
            *first = *prev;
            *mid = root;
        }
        else              // second time violation
            *last = root; // ye sirf case 1 ke liye aaega
    }
    *prev = root; // root prev bnke jayega apne right subtree ke liye
    calcPointers(root->right, first, mid, last, prev);
}

void restore(node *root)
{

    node *first = NULL, *mid = NULL, *last = NULL, *prev = NULL;
    calcPointers(root, &first, &mid, &last, &prev);

    // Case 1
    if (first && last)
        swap((first->data), (last->data));

    // Case 2  // agr last null hi rh gya
    else if (first && mid)
        swap((first->data), (mid->data));
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    node *root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    // root->right->left = new node(6);
    root->right->right = new node(13);

    inorder(root);
    restore(root);
    cout << endl;
    inorder(root);
    return 0;
}