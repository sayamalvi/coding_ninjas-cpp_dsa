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
TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = ans->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *child = maxSumNode(root->children[i]);
        int childSum = child->data;
        for (int i = 0; i < child->children.size(); i++)
        {
            childSum += child->children[i]->data;
        }
        if (childSum > sum)
        {
            sum = childSum;
            ans = child;
        }
    }
    return ans;
}
//--------------------------------------------
int main()
{
    TreeNode<int> *root = takeInput();
    TreeNode<int> *ans = maxSumNode(root);

    printTree(root);
}