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

void printLevelATNewLine(BinaryTree<int> *root)
{
    queue<BinaryTree<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTree<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}
//-----------------------------------------------------------------
BinaryTree<int> *buildTree(int *pre, int *in, int inorderStart, int inorderEnd, int preorderStart, int preorderEnd)
{
    if (inorderStart > inorderEnd || preorderStart > preorderEnd)
        return NULL;

    int rootData = pre[preorderStart];
    int rootIndex = -1;
    for (int i = inorderStart; i <= inorderEnd; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInorderStart = inorderStart;
    int leftInorderEnd = rootIndex - 1;
    int rightInorderStart = rootIndex + 1;
    int rightInorderEnd = inorderEnd;
    int leftPreorderStart = preorderStart + 1;
    int leftPreorderEnd = leftInorderEnd - leftInorderStart + leftPreorderStart;
    int rightPreorderStart = leftPreorderEnd + 1;
    int rightPreorderEnd = preorderEnd;

    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    root->left = buildTree(pre, in, leftInorderStart, leftInorderEnd, leftPreorderStart, leftPreorderEnd);
    root->right = buildTree(pre, in, rightInorderStart, rightInorderEnd, rightPreorderStart, rightPreorderEnd);

    return root;
}
BinaryTree<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildTree(preorder, inorder, 0, inLength - 1, 0, preLength - 1);
}
//-----------------------------------------------------------------
int main()
{
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    for (int i = 0; i < size; i++)
        cin >> in[i];
    BinaryTree<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}