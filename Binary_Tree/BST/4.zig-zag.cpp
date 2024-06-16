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

void zig(node *root) // no recursion
{
    if (root == NULL)
        return;

    stack<node *> curlev;
    stack<node *> nexlev;
    bool lr = 1; // to check l->r jana hai ya r->l
    curlev.push(root);

    while (!curlev.empty())
    {
        if (curlev.top() != NULL) // tb tk chalega jb tk ek level khatm na ho jaye
        {
            if (lr)
            {
                if (curlev.top()->left)
                    nexlev.push(curlev.top()->left);
                if (curlev.top()->right)
                    nexlev.push(curlev.top()->right);
            }
            else
            {
                if (curlev.top()->right)
                    nexlev.push(curlev.top()->right);
                if (curlev.top()->left)
                    nexlev.push(curlev.top()->left);
            }
            cout << curlev.top()->data << " ";
            curlev.pop();
        }
        if (curlev.empty())
        {
            lr = !lr; // varible ka sign change krenge
            // swap(curlev, nexlev);
            stack<node *> temp = curlev;
            curlev = nexlev;
            nexlev = temp; // also need to update nexlev
        }
    }
}

int main()
{
    node *root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);
    root->right->left = new node(6);
    root->right->right = new node(7);

    zig(root);
    return 0;
}