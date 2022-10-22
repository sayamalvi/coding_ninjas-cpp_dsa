#include <iostream>
#include "BinaryTree.h"
using namespace std;
BinaryTree<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;

    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    BinaryTree<int> *leftChild = takeInput();
    BinaryTree<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
void printTree(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    if (root->left != NULL)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
int main()
{
    BinaryTree<int> *root = takeInput();
    printTree(root);
    delete root;
}