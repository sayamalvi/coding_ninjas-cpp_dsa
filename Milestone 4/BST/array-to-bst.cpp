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
void preOrder(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";

    preOrder(root->left);
    preOrder(root->right);
}

//-----------------------------------------------------------------

BinaryTree<int> *constructTree(int *input, int si, int ei, int n)
{
    if (n == 0)
        return NULL;
    int mid = (si + ei) / 2;
    BinaryTree<int> *root = new BinaryTree<int>(input[mid]);
    root->left = constructTree(input, si, mid - 1, mid - si);
    root->right = constructTree(input, mid + 1, ei, ei - mid);
    return root;
}
BinaryTree<int> *constructTree(int *input, int n)
{
    if (n == 0)
        return NULL;
    return constructTree(input, 0, n - 1, n);
}
//-----------------------------------------------------------------
int main()
{
    int size;
    cin >> size;
    int *input = new int[size];

    for (int i = 0; i < size; i++)
        cin >> input[i];

    BinaryTree<int> *root = constructTree(input, size);
    preOrder(root);
    delete[] input;
}
