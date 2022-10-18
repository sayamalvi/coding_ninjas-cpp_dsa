#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<TreeNode<int> *> printque;
    printque.push(root);
    while (!printque.empty())
    {
        TreeNode<int> *front = printque.front();
        printque.pop();
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data;
            if (i != front->children.size() - 1)
                cout << ",";
            printque.push(front->children[i]);
        }
        cout << endl;
    }
}
//--------------------------------------------
int getLargeNodeCount(TreeNode<int> *root, int x)
{
    // Write your code here
    int count = 0;
    if (root->data > x)
        count++;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLargeNodeCount(root->children[i], x);
    }
    return count;
}
//--------------------------------------------
int main()
{
    int x;
    cin >> x;
    TreeNode<int> *root = takeInput();
    getLargeNodeCount(root, x);
}