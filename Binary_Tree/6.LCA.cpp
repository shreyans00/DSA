#include <bits./stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int val)
    {
        data = val, left = NULL, right = NULL;
    }
};

node *LCA(node *root, int n1, int n2) // n1 & n2 are val of 2 nodes
{
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2) // koi ek bhi mil gya to wo node return kr denge
        return root;

    node *left = LCA(root->left, n1, n2);
    node *right = LCA(root->right, n1, n2);

    // Aab hm check krenge abhi tk jo left & right se jo LCA nikl ke aaye hai, usme n1 & n2 mila ya nhi

    if (left != NULL && right != NULL) // agr hme n1 & n2 dono mil gya from left & right, to current root hi lCA hoga
        return root;

    if (left == NULL && right == NULL)
        return NULL;

    if (left != NULL)
        return left; // agr n1 mila pehle, to khojenge kya n2 bhi hai wahan & vice-versa

    return right;
}

int findDist(node *root, int k, int dist) // root(here, lca) & node with val k mai kitne level ka difference hai
{
    if (root == NULL)
        return -1;
    if (root->data == k)
        return dist;
    int left = findDist(root->left, k, dist + 1);
    if (left != -1) // left mai mil gya k
        return left;
    return findDist(root->right, k, dist + 1); // else right mai dekh lete hai
}

int distbwNodes(node *root, int n1, int n2)
{
    node *lca = LCA(root, n1, n2);
    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);
    return d1 + d2;
}

int32_t main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->left = new node(9);
    root->right->left->right = new node(6);

    cout << distbwNodes(root, 7, 9);
}