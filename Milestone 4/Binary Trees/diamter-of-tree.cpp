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

void inorder(BinaryTree<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int height(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
//---------------------------------------------
int diameter(BinaryTree<int> *root)
{
    if (root == NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
pair<int, int> heightDiameter(BinaryTree<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int lh = leftAns.first;
    int ld = leftAns.second;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> ans;
    ans.first = height;
    ans.second = diameter;
    return ans;
}
//---------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInputLevelWise();
    inorder(root);
    pair<int, int> p = heightDiameter(root);
    cout << endl;
    cout << "Height : " << p.first << endl;
    cout << "Diameter : " << p.second << endl;
    delete root;
}