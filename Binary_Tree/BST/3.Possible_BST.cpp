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

vector<node *> constructTrees(int st, int en)
// This function stores roots of differnt BSTs
// start = 1 and end = n
{
    vector<node *> v; // to store different BSTs
    if (st > en)
    {
        v.push_back(NULL);
        return v;
    }

    for (int i = st; i <= en; i++) // construct BST for lower levels & usse as a left & right child use krke required BST nikalenge
    {
        vector<node *> leftSubtrees = constructTrees(st, i - 1); // left mai ith value se km honi chahiye, so end val is (i-1)
        vector<node *> rightSubtrees = constructTrees(i + 1, en);

        // Aab Catalan wala loop chalayenge jisme saare possible leftSubtrees ko saare possible rightSubtrees ke saath combine kr rhe hai ith node mai aur iss tarah hm ek larger BST value ko compute krke v vector mai store krenge
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                node *right = rightSubtrees[k];
                node *nd = new node(i); // construct krenge new node i(current node) ko
                nd->left = left;
                nd->right = right;
                v.push_back(nd); // nd node mai i val hai aur left & right subtrees ke pointers
            }
        }
    }
    return v;
}

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

int main()
{
    vector<node *> totTrees = constructTrees(1, 3);
    for (int i = 0; i < totTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preorder(totTrees[i]);
        cout << endl;
    }
    return 0;
}