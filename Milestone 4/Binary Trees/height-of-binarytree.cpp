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

void printLevelWise(BinaryTree<int> *root)
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
            cout << "L:" << front->left->data << ",";
        }
        else
            cout << "L:"
                 << "-1"
                 << ",";
        if (front->right != NULL)
        {
            print.push(front->right);
            cout << "R:" << front->right->data;
        }
        else
            cout << "R:"
                 << "-1";
        cout << endl;
    }
}
//--------------------------------------------

int height(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    int heightRight = 1;
    int heightLeft = 1;
    heightRight += height(root->right);
    heightLeft += height(root->left);
    if (heightRight > heightLeft)
        return heightRight;
    else
        return heightLeft;
}
//--------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    cout << height(root);
    delete root;
}