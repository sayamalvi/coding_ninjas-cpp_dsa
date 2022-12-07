#include "BinaryTree.h"
#include <iostream>
using namespace std;
class BST
{
    BinaryTree<int> *root;

    bool hasData(int data, BinaryTree<int> *root)
    {
        if (root == NULL)
            return false;
        if(root->data == data) return true;
        else if (data < root->data)
            return hasData(data, root->left);
        else
            return hasData(data, root->right);
    }
    BinaryTree<int> *insert(int data, BinaryTree<int> *root)
    {
        if (root == NULL)
        {
            BinaryTree<int> *newNode = new BinaryTree<int>(data);
            return newNode;
        }
        if (data < root->data)
        {
            root->left = insert(data, root->left);
        }
        else
        {
            root->right = insert(data, root->right);
        }
        return root;
    }
    BinaryTree<int> *deleteData(int data, BinaryTree<int> *root)
    {
        if (root == NULL)
            return NULL;

        if (data > root->data)
        {
            root->right = deleteData(data, root->right);
            return root;
        }
        else if (data < root->data)
        {
            root->left = deleteData(data, root->left);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                BinaryTree<int> *temp = root->right;
                root->right == NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                BinaryTree<int> *temp = root->left;
                root->left == NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTree<int> *minNode = root->right;
                while (minNode->left)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deleteData(rightMin, root->right);
                return root;
            }
        }
    }
    void printTree(BinaryTree<int> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << ":";
        if (root->left != NULL)
            cout << "L" << root->left->data;
        if (root->right != NULL)
            cout << " R" << root->right->data;
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    void deleteData(int data)
    {
        root = deleteData(data, root);
    }
    void insert(int data)
    {
        root = insert(data, root);
    }
    bool hasData(int data)
    {
        return hasData(data, root);
    }
    void printTree()
    {
        printTree(root);
    }
};