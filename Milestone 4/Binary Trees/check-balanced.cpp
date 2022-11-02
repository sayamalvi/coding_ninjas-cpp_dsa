#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include "BinaryTree.h"
#include <cmath>
class Pair
{
public:
    int height;
    bool balanced;
};
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
Pair checkBalanced(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        Pair ob;
        ob.balanced = true;
        ob.height = 0;
        return ob;
    }
    Pair leftTree = checkBalanced(root->left);
    Pair rightTree = checkBalanced(root->right);

    Pair ans;
    ans.height = max(leftTree.height, rightTree.height) + 1;
    if (leftTree.balanced == false || rightTree.balanced == false)
    {
        ans.balanced = false;
    }
    else if (abs(leftTree.height - rightTree.height) > 1)
    {
        ans.balanced = false;
    }
    else
        ans.balanced = true;

    return ans;
}
bool isBalanced(BinaryTree<int> *root)
{
    if (root == NULL)
        return true;
    Pair ans = checkBalanced(root);
    return ans.balanced;
}
//---------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    cout << (isBalanced(root) ? "true" : "false");
}