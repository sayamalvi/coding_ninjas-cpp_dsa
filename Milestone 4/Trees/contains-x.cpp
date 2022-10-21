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

bool isPresent(TreeNode<int> *root, int x)
{
    if (root->data == x)
        return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool find = isPresent(root->children[i], x);
        if (find)
            return true;
    }
    return false;
}
//--------------------------------------------
int main()
{
    TreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << (isPresent(root, x) ? "true" : "false");
}