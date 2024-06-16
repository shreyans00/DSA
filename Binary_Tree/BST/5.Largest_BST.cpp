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

struct info
{
    int size, max, min, msize;
    bool isBST;
};

info largestBST(node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, 1};

    if (root->left == NULL && root->right == NULL) // root node is leaf
        return {1, root->data, root->data, 1, 1};

    // Call left subtree & right subtree aur wahan se info leke aayenge
    info leftInfo = largestBST(root->left);
    info rightInfo = largestBST(root->right);

    info curr; // aab current root ki info nikalenge
    curr.size = (1 + leftInfo.size + rightInfo.size);

    // Ab dekhenge kya current node pe BST bn rha hai
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, root->data);
        curr.max = max(rightInfo.max, root->data);

        curr.msize = curr.size;
        curr.isBST = 1;
        return curr;
    }
    curr.msize = max(leftInfo.msize, rightInfo.msize);
    curr.isBST = 0;
    return curr;
}

int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);
    // root->left->right = new node(10);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    cout << largestBST(root).msize; // 15 & 30    or    20 & 5
    return 0;
}