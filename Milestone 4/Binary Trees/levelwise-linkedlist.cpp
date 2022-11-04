#include <iostream>
#include <queue>
#include <vector>

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

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;

    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//------------------------------------------------------
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> output;

    // handle if root is null
    if (root == NULL)
    {
        output.push_back(NULL);
        return output;
    }

    // make a queue and push root and Null
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);

    // make two pointers head and tail because we will eventually make a linked list
    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    // run the loop till queue is not empty
    while (!q.empty())
    {
        // store the first element of queue and remove it from queue
        BinaryTreeNode<int> *current = q.front();
        q.pop();

        // if first element is not null then make a new node and push its children in the queue
        if (current != NULL)
        {
            Node<int> *node = new Node<int>(current->data);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);

            // if head is null that means there does not exist any linked list so make head and tail point to the current node else move tail to the next node
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
                node->next = NULL;
            }
        }

        // if first element is null that means we have finished current level, now push head node of the linked list in the output and reset head and tail to null. check if queue is not empty then push null
        if (current == NULL)
        {
            output.push_back(head);
            head = NULL;
            tail = NULL;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
    }
    return output;
}
//------------------------------------------------------
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++)
    {
        print(ans[i]);
    }
}