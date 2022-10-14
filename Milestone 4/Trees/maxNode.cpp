#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}
//--------------------------------------------
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    TreeNode<int> *max = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *next = maxDataNode(root->children[i]);
        if (next->data > max->data)
            max = next;
    }
    return max;
}
//--------------------------------------------
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    TreeNode<int> *ans = maxDataNode(root);

    if (root != NULL)
    {
        cout << ans->data;
    }
}