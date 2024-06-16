#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;           // uss node ka data
    struct node *left;  // left child ki taraf point krega
    struct node *right; // right child ki taraf point krega

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int search(int inorder[], int start, int end, int curr) // function to search posn of curr in inorder array
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1; // but ye kabhi hoga nhi
}

node *buildTree(int postorder[], int inorder[], int start, int end) // represent hone wale tree ka node
// start & end represent start & end of inorder array
{
    static int idx = postorder.size() - 1;
    if (start > end) // base condition
    {
        return NULL;
    }
    int curr = postorder[idx]; // sbse pehle dekhenge index pe kaun sa element hai
    idx--;
    node *Curr_Node = new node(curr);
    if (start == end) // inorder mai ek hi element bacha hai, no left and right child
    {
        return Curr_Node;
    }
    int pos = search(inorder, start, end, curr); // function to search posn of curr in inorder array
    Curr_Node->right = buildTree(postorder, inorder, pos + 1, end);
    Curr_Node->left = buildTree(postorder, inorder, start, pos - 1);

    return Curr_Node; // jis node ko hmne build kiya hai usse return kr rhe hai
}

void inorderPrint(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    node *root = buildTree(postorder, inorder, 0, 4);
    cout << "We build the tree from postorder and inorder, let's check inorder: ";
    inorderPrint(root);

    return 0;
}