#include <bits./stdc++.h>
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

void printLevelOrder(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q; // q jisme nodes dalenge & nikalenge level wise
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *nd = q.front();
        q.pop();
        if (nd != NULL) // pop krne ke baad dekhenge hmara node null to nhi tha
        {
            cout << nd->data << " ";
            if (nd->left) // agr queue ke front node ka left hai to usko queue mai push kro
                q.push(nd->left);
            if (nd->right) // lly with right
                q.push(nd->right);
        }
        else if (!q.empty()) // node null tha to dekhenge wo empty to nhi hua hai, ye tb hoga jb ek level khatm ho gya hoga
        {
            q.push(NULL); // null ke piche wapas push kro, denoting ek level khatm ho chuka hai
        }
    }
}

int sumAtKlevel(node *root, int k) // assuming level starts from 1
{
    if (root == NULL)
        return -1;
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    if (k == 0)
        return root->data;
    int lev = 1, sum = 0;
    while (!q.empty())
    {
        node *nd = q.front();
        q.pop();
        if (nd != NULL)
        {
            if (lev == k)
                sum += nd->data;
            if (nd->left)
                q.push(nd->left);
            if (nd->right)
                q.push(nd->right);
        }
        else if (!q.empty())
        {
            q.push(NULL);
            lev++;
        }
    }
    return sum;
}

void rightView(node *root) // function to find rightView nodes
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    // q.push(NULL);  null nhi dalenge iss baar, q ka size hi check krke dekh lenge kitne nodes stored hai

    while (!q.empty())
    {
        int n = q.size(); // no. of nodes in each level
        for (int i = 0; i < n; i++)
        {
            node *curr = q.front();
            q.pop();

            if (i == n - 1) // jb last node pr jayenge uss level ke, to print kr denge
                cout << curr->data << " ";

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }
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
    root->left->right->left = new node(2);
    root->right->left->right = new node(6);

    // Level Order Traversal
    printLevelOrder(root);
    cout << endl;
    cout << sumAtKlevel(root, 4);
    rightView(root);
}