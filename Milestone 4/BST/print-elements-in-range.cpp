#include <iostream>
#include <queue>
#include "BinaryTree.h"
using namespace std;

BinaryTree<int> *takeInput()
{
    int rootData;
    cout << "Enter root data : ";
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
        cout << "Enter left child of " << currentNode->data << " : ";
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTree<int> *leftNode = new BinaryTree<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << currentNode->data << " : ";
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTree<int> *rightNode = new BinaryTree<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
//----------------------------------------------------------------

void elementsInRangeK1K2(BinaryTree<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (root->data > max(k1, k2))
        elementsInRangeK1K2(root->left, k1, k2);
    else
    {
        elementsInRangeK1K2(root->left, k1, k2);
        if (root->data >= k1 && root->data <= k2)
        {
            cout << root->data << " ";
        }
        elementsInRangeK1K2(root->right, k1, k2);
    }
}
//----------------------------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    elementsInRangeK1K2(root, k1, k2);
}