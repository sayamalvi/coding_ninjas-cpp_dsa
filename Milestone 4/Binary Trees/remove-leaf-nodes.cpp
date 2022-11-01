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
void printLevel(BinaryTree<int> *root)
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

int height(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
//---------------------------------------------
BinaryTree<int> *removeLeafNodes(BinaryTree<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        delete root;
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}
//---------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    root = removeLeafNodes(root);
    printLevel(root);
}