#include <iostream>
#include <queue>
#include "BinaryTree.h"
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

BinaryTree<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTree<int> *root = new BinaryTree<int>(rootData);
    queue<BinaryTree<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTree<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTree<int> *leftNode = new BinaryTree<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTree<int> *rightNode =
                new BinaryTree<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
//-----------------------------------------------
Node<int> *constructLinkedList(BinaryTree<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        return new Node<int>(root->data);
    }

    Node<int> *node = new Node<int>(root->data);

    Node<int> *leftTree = constructLinkedList(root->left);
    Node<int> *rightTree = constructLinkedList(root->right);

    if (leftTree)
    {
        Node<int> *tail = leftTree;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = node;
    }
    node->next = rightTree;
    if (!leftTree)
        return node;
    return leftTree;
}

//-----------------------------------------------
int main()
{
    BinaryTree<int> *root = takeInput();
    Node<int> *head = constructLinkedList(root);

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}