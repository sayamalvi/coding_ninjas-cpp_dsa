#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
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


void zigZagOrder(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    stack<BinaryTree<int> *> s1;
    stack<BinaryTree<int> *> s2;

    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            BinaryTree<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";
            if (top->left)
                s2.push(top->left);
            if (top->right)
                s2.push(top->right);
        }
        cout << endl;
        while (!s2.empty())
        {
            BinaryTree<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";
            if (top->right)
                s1.push(top->right);
            if (top->left)
                s1.push(top->left);
        }
        cout << endl;
    }
}

//---------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    zigZagOrder(root);
}