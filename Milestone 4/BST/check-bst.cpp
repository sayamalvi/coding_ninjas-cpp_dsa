#include <climits>
#include <iostream>
#include <queue>
#include "BinaryTree.h"

using namespace std;
BinaryTree<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTree<int> *leftNode = new BinaryTree<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTree<int> *rightNode =
                new BinaryTree<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
//-----------------------------------------------------------------
bool isBST(BinaryTree<int> *root, int min, int max)
{
    if (root == NULL)
        return true;
    return (root->data < max && root->data >= min &&
            isBST(root->left, min, root->data) &&
            isBST(root->right, root->data, max));
}
bool isBST(BinaryTree<int> *root)
{
    if (root == NULL)
        return true;
    return isBST(root, INT_MIN, INT_MAX);
}
//-----------------------------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}