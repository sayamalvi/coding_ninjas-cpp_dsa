#include <iostream>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    int n;
    cout << "Enter number of children of" << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}
void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
//--------------------------------------------
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1->children.size() != root2->children.size())
        return false;
    bool identical;
    if (root1->data == root2->data)
        identical = true;
    else
        return false;

    for (int i = 0; i < root1->children.size(); i++)
    {
        identical = areIdentical(root1->children[i], root2->children[i]);
    }
    return identical;
}
//--------------------------------------------
int main()
{
    TreeNode<int> *root1 = takeInput();
    TreeNode<int> *root2 = takeInput();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}