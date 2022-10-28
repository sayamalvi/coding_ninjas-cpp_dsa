#include <iostream>
#include "BinaryTree.h"
#include <queue>
using namespace std;

BinaryTree<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTree<int> *root = new BinaryTree<int>(rootData);

    queue<BinaryTree<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTree<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildren;
        cin >> leftChildren;
        if (leftChildren != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(leftChildren);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildren;
        cin >> rightChildren;
        if (rightChildren != -1)
        {
            BinaryTree<int> *child = new BinaryTree<int>(rightChildren);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void postOrder(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
void preOrder(BinaryTree<int> *root)
{

    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inorder(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void levelOrder(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTree<int> *> print;
    print.push(root);
    while (!print.empty())
    {
        BinaryTree<int> *front = print.front();
        print.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            print.push(front->left);
            cout << front->left->data << " ";
        }

        if (front->right != NULL)
        {
            print.push(front->right);
            cout <<  front->right->data;
        }
    
        cout << endl;
    }
}
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    inorder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    delete root;
}