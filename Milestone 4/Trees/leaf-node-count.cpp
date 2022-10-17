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
//----------------------------------------------------------------
int getLeafNodeCount(TreeNode<int> *root)
{
    // Write your code here
    int leaf = 0;
    if (root->children.size() == 0)
        return 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        leaf += getLeafNodeCount(root->children[i]);
    }
    return leaf;
}
//----------------------------------------------------------------
int main()
{
    TreeNode<int> *root = takeInput();
    cout << getLeafNodeCount(root);
}