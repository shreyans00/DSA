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

void flatten(node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if (root->left != NULL) // agr left subtree mai elements hai, agr nhi hai to sirf right ke liye krenge
    {
        flatten(root->left);      // sbse pehle left wale subtree ko flatten kr denge
        node *temp = root->right; // right subtree store kr lenge temp mai
        root->right = root->left; // root ke right ki jagah root ka flattened left daal denge
        root->left = NULL;        // root ka left null kr denge, left mai kuch nhi chahiye hme

        // To calculate tail of pehle wala left subtree
        node *t = root->right;   // ye root ka right whi hai jo pehle root ka left tha
        while (t->right != NULL) // agr kisi bhi point pe null ho gya to wo hai right tail
        {
            t = t->right; // finally jo t nikal ke aayega wo ho jayega tail
        }
        t->right = temp; // tail ke right mai hmne daal diya temp, jo pehle root ka right tha
    }
    flatten(root->right); // aab right subtree ke liye call krenge
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
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    flatten(root);
    inorder(root);

    return 0;
}