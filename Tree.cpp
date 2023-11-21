#include "C++.h"
using namespace std;
// nen bo sung chieu cao va size de it ton
struct Node
{
    int data;
    Node* left;
    Node* right;
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
void Add(node& Tree, int x)
{
    node p = MakeNode(x);
    if (Tree == NULL)
    {
        Tree = p;
        return;
    }
    else
    {
        if (x < Tree->data)
            Add(Tree->left, x);
        if (x > Tree->data)
            Add(Tree->right, x);
    }
}
node Search(node Tree, int x) {
    if (Tree == NULL) return NULL; 
    if (Tree->data == x)
        return Tree;
    else if (Tree->data < x) {
        Search(Tree->right, x);
    }
    else if (Tree->data > x) Search(Tree->left, x);
}
#pragma region Xoa
void RightMax(node& Tree, node& p) {
    if (p->left != NULL) {
        RightMax(Tree, p->left);
    }
    else {
        Tree->data = p->data;
        node tmp = p;
        p = p->right;
        delete tmp;
    }
}
void Delete(node& Tree, int x) {
    if (Tree == NULL) return;
    else {
        if (Tree->data > x) {
            Delete(Tree->left, x);
        }
        else if (Tree->data < x) {
            Delete(Tree->right, x);
        }
        else {
           // node p = Tree;
            if (Tree->left == NULL) {
                node p = Tree;
                Tree = Tree->right;
                delete p;
            }
            else if (Tree->right == NULL)
            {
                node p = Tree;
                Tree = Tree->left;
                delete p;
            }
            else if (Tree->left != NULL && Tree->right != NULL) {
                RightMax(Tree, Tree->right);
            }
        }
    }


}
#pragma endregion


void Duyet_NLR(node Tree) {
    if (Tree == NULL) return;
    else {
        cout << Tree->data << ' ';
        Duyet_NLR(Tree->left);
        Duyet_NLR(Tree->right);
    }
}
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

int main() {
    node Tree = NULL;
    int a[] = {5,4,3,15,12,13,20,11};
    for (int x : a) Add(Tree, x);
     Delete(Tree, 12);
    Duyet_LNR(Tree);
    return 1;
}
