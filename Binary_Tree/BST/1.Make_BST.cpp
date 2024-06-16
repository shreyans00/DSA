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

node *insert(node *root, int val)
{
    if (root == NULL)
        return new node(val);

    if (val < root->data)
        root->left = insert(root->left, val);

    else
        root->right = insert(root->right, val);

    return root;
}

node *inorderSucc(node *root)
{
    node *curr = root;
    while (curr && curr->left != NULL) // inorder successor hm tb tk find krte rhenge jb tk curr->left null nhi ho jata
    {
        curr = curr->left;
    }
    return curr; // jo curr ki value hogi whi inorder successor hai
}

node *deletenode(node *root, int val)
{
    if (val < root->data)                         // val root ke left mai hai
        root->left = deletenode(root->left, val); // hmare paas aaega root ka nya left jispe saare changes inlcuded honge

    else if (val > root->data)
        root->right = deletenode(root->right, val);

    // hmne node to be deleted ko find kr liya hai, jahan bhi hai left ya right mil chuka hai
    else // jb val root->data ke equal ho gyai
    {
        // Case 1(koi child nhi) & 2(ek hi taraf child hai)
        if (root->left == NULL) // left mai child nhi hai
        {
            node *temp = root->right; // root ka right bhi agr null hai tb tbhi ye valid condition hi hoga
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3
        node *temp = inorderSucc(root->right); // root ka inorder successor root ke right mai hi milega
        root->data = temp->data;
        root->right = deletenode(root->right, temp->data); // hme root ke right mai jakr inorder successor ki val ko delete kr diya
    }
    return root;
}

node *search(node *root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    else
        return search(root->right, key);
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
    node *root = NULL;
    root = insert(root, 5);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 2);
    insert(root, 7);

    inorder(root);
    cout << endl;

    root = deletenode(root, 4);
    inorder(root);
    cout << endl;

    cout << search(root, 9);
    return 0;
}