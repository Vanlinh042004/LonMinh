#include "C++.h"
#define COUNT 5
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    int height;
};
using node = Node*;
node MakeNode(int x)
{
    node p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int getHeight(node root)
{
    if (root == NULL) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}
void rightRotate(node& root)
{
    node x = root->left;
    root->left = x->right;
    x->right = root;
    root = x;
    // CAP NHAP LAI CHIEU CAO
    root->height = getHeight(root);
    x->height = getHeight(x);
}
void leftRotate(node& root)
{
    node x = root->right;
    root->right = x->left;
    x->left = root;
    root = x;
    root->height = getHeight(root);
    x->height = getHeight(x);
}
void Insert(node& root, int x)
{
    node p = MakeNode(x);
    if (root == NULL)
    {
        root = p;
        root->height = 1;
        return;
    }
    else
    {
        if (x > root->data)
            Insert(root->right, x);
        else if (x < root->data)
            Insert(root->left, x);
    }
    root->height = getHeight(root);
    int val = getHeight(root->left) - getHeight(root->right);
    // 3.1. Left left
    if (val > 1 && x < root->left->data) rightRotate(root);

    // 3.2. Right Right
    if (val < -1 && x > root->right->data)  leftRotate(root);
    // 3.3. Left Right
    if (val > 1 && x > root->left->data) {
        leftRotate(root->left);
        rightRotate(root);
    }
    // 3.4. Right Left
    if (val < -1 && x< root->right->data) {
        rightRotate(root->right);
        leftRotate(root);
    }

}
#pragma region Delete
int valBalance(node root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}
void RightMax(node& root, node& p) {
    if (p->left != NULL) {
        RightMax(root, p->left);
    }
    else {
        root->data = p->data;
        node tmp = p;
        p = p->right;
        delete tmp;
    }
}
void Delete(node& root, int x) {
    if (root == NULL) return;
    else {
        if (root->data > x) {
            Delete(root->left, x);
        }
        else if (root->data < x) {
            Delete(root->right, x);
        }
        else {
            // node p = root;
            if (root->left == NULL) {
                node p = root;
                root = root->right;
                delete p;
            }
            else if (root->right == NULL)
            {
                node p = root;
                root = root->left;
                delete p;
            }
            else if (root->left != NULL && root->right != NULL) {   
                RightMax(root, root->right);
            }
        }
        
    }
    
    if(root!=NULL) {
        root->height = getHeight(root);
        int val = valBalance(root);
        if (val > 1 && valBalance(root->left) >= 0) {
            rightRotate(root);
        }
        else if (val > 1 && valBalance(root->left) <=0) {
            leftRotate(root->left);
            rightRotate(root);
        }
        else if (val < -1 && valBalance(root->right) <=0) {
            leftRotate(root);
        }
        else if (val < -1 && valBalance(root->right) >=0) {
            rightRotate(root->right);
            leftRotate(root);
        }
    }

}
#pragma endregion
void Duyet_LNR(node Tree) {
    if (Tree == NULL)
        return;
    else
    {
        Duyet_LNR(Tree->left);
        cout << Tree->data << ' ';
        Duyet_LNR(Tree->right);
    }
}
void print2DUtil(node root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout << endl;

    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << " (" << root->height << ") "
        << "\n";

    print2DUtil(root->left, space);
}

int main()
{
    int space = 0;
    node Root = NULL;
    Insert(Root, 10);
    Insert(Root, 5);
    Insert(Root, 15);
    Insert(Root, 3);
    Insert(Root, 12);
    Insert(Root, 17);
    Insert(Root, 11);
    Delete(Root, 3);
    print2DUtil(Root, space);
    return 1;
}
