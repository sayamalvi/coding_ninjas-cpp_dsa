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

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{

    if (root == NULL || x == NULL)
        return NULL;

    TreeNode<int> *ans = NULL;
    int nextLarge = 9999;
    if (root->data > x && root->data < nextLarge)
    {
        ans = root;
        nextLarge = ans->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        if (root->children[i]->data > x && root->children[i]->data < nextLarge)
        {
            ans = root->children[i];
            nextLarge = root->children[i]->data;
        }
        TreeNode<int> *nextGreater = getNextLargerElement(root->children[i], x);
        if (ans == NULL)
            ans = nextGreater;
    }

    return ans;
}

//--------------------------------------------
int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int> *ans = getNextLargerElement(root, x);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}