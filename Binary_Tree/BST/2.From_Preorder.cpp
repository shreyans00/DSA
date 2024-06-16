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

node *construct(int preorder[], int &preorderIdx, int key, int min, int max, int n)
// preorderIdx preorder ka curr index bta rha hai,  n=no.of nodes, key=jisko insert krna hai
// hm key ko daalte jayenge using recursion from preorder array using preorder idx
// Initially, min=INT_MAX, max=INT_MIN
{
    if (preorderIdx >= n) // agr preorder ka curr indx n ho gya to aab preorder array mai kuch nhi bacha
        return NULL;

    node *root = NULL; // jbse pehle ek khali root bna lete hai

    if (key < max && key > min)
    {
        root = new node(key); // root mai key daal do
        preorderIdx++;        // index aage badho

        // preorder se construct kr rhe h to pehle left mai dalke dekhenge
        if (preorderIdx < n) // agr preorderIdx increment krne ke baad bhi n se km hai
            root->left = construct(preorder, preorderIdx, preorder[preorderIdx], min, key, n);

        if (preorderIdx < n) // root->left ke wjah se preoderIdx bdha hoga to check kr lena badhne ke baad bhi n se km hai n
            root->right = construct(preorder, preorderIdx, preorder[preorderIdx], key, max, n);
    }

    return root;
}

void preorderfun(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorderfun(root->left);
    preorderfun(root->right);
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int preorderIdx = 0;
    node *root = construct(preorder, preorderIdx, preorder[0], INT_MIN, INT_MAX, 5);
    preorderfun(root);
    return 0;
}