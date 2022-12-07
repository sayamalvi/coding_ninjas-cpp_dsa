#include <iostream>
#include "BinaryTree.h"
#include <queue>
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
//-----------------------------------------------
void insertDuplicateNode(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTree<int> *dup = new BinaryTree<int>(root->data);
    BinaryTree<int> *temp = root->left;
    root->left = dup;
    dup->left = temp;
}
//-----------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInput();
    insertDuplicateNode(root);
    printLevelATNewLine(root);
    delete root;
}