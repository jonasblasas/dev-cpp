#include <iostream>

using namespace std;

class BST
{
    int data;
    BST *left, *right;

    public:
        BST();
        BST(int);
        BST *Insert(BST *, int);
        void Preorder(BST *);
        void Inorder(BST *);
        void Postorder(BST *);
        bool IsBST(BST *, BST *, BST *);
};

BST::BST() : data(0), left(NULL), right(NULL) {}

BST::BST(int value)
{
    data = value;
    left = right = NULL;
}

BST* BST::Insert(BST* root, int value)
{
    if(!root)
    {
        return new BST(value);
    }

    if(value > root->data)
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
    
    return root;
}

void BST::Preorder(BST* root)
{
    if(!root)
    {
        return;
    }
    cout << root->data << endl;
    Preorder(root->left);
    Preorder(root->right);
}

void BST::Inorder(BST* root)
{
    if(!root)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}

void BST::Postorder(BST* root)
{
    if(!root)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << endl;
}

bool BST::IsBST(BST* root, BST* left=NULL, BST* right=NULL)
{
    if(root == NULL)
    {
        return true;
    }

    if(left != NULL and root->data <= left->data) 
    {
        return false;
    }

    if(right != NULL and root->data >= right->data)
    {
        return false;
    }

    return IsBST(root->left, left, root) and IsBST(root->right, root, right);
}

int main() {
    BST b, *root = NULL;
    root = b.Insert(root, 50);
    b.Insert(root, 20);
    b.Insert(root, 30);
    b.Insert(root, 40);
    b.Insert(root, 60);
    b.Insert(root, 70);
    b.Insert(root, 80);
    b.Insert(root, 10);
    b.Insert(root, 25);
    b.Insert(root, 75);

    cout << "preorder" << endl;
    b.Preorder(root);

    cout << "inorder" << endl;
    b.Inorder(root);

    cout << "postorder" << endl;
    b.Postorder(root);

    cout << "is valid bst: " << b.IsBST(root, NULL, NULL) << endl;
    return 0;
}