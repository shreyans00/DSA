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

// Case 1
void printSubtree(node *root, node *target, int k)
{
    if (root == NULL || k < 0)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubtree(root->left, target, k - 1);
    printSubtree(root->right, target, k - 1);
}

// Case 2
int nodeAtk(node *root, node *target, int k) // int le rhe hai target se root ka dist nikalne ke liye, upar jaane ke liye
{
    if (root == NULL)
        return -1;
    if (root == target) // tb hm aur upar ja hi nhi skte
    {
        printSubtree(root, target, k);
        return 0;
    }

    int dl = nodeAtk(root->left, target, k); // root ke left se target ka dist
    if (dl != -1)                            // curr node(root) ke left mai hai target
    {
        if (dl + 1 == k) // hm jis curr node pr hai wo target se k-1 dist pr hai
            cout << root->data << " ";
        else
            printSubtree(root->right, target, (k - (dl + 1)) - 1);
        // agr target node root ke left mai milta hai to hm call root ke right mai lgayenge
        // -2 becoz hm directly root pe nhi root->right pe call lga rhe hai, also hmne root ke left subchild se root tk ka diff travel kiya to usme bhi 1 add ho gya
        return dl + 1;
    }

    int dr = nodeAtk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << " ";
        else
            printSubtree(root->left, target, k - dr - 2);
        return dr + 1;
    }

    return -1;
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

    nodeAtk(root, root->left, 1);
    return 0;
}