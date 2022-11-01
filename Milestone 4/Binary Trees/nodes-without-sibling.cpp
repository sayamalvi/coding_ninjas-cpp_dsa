#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include "BinaryTree.h"
#include <cmath>
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

void inorder(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int height(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
//---------------------------------------------
void printNodesWithoutSibling(BinaryTree<int> *root)
{
    // if(root == NULL) return;
    if (root->left == NULL && root->right == NULL)
        return;
    if (root->left == NULL)
        cout << root->right->data << " ";
    if (root->right == NULL)
        cout << root->left->data << " ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}
//---------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    printNodesWithoutSibling(root);
}