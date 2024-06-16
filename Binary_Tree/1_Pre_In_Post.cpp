/*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7

    Preorder: 1,2,4,5,3,6,7
    Inorder: 4,2,5,1,6,3,7
    Postorder: 4,5,2,6,7,3,1
*/

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;           // jo node create kiye uska data ka data
    struct node *left;  // left child ki taraf point krega
    struct node *right; // right child ki taraf point krega

    node(int val) // ye user se input lenge
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    struct node *root = new node(1); // root pointer point krega ek nyi node ki taraf jispe value store krenge 1
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}