#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;
Node *takeinput()
{
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
//---------------------------------------
int findNode(Node *head, int n)
{
    int count = 0;
    Node *temp = head;
    if (head == NULL)
        return -1;
    while (temp != NULL && temp->data != n)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
        return -1;
    else
        return count;
}
//---------------------------------------

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int val;
        cin >> val;
        cout << findNode(head, val) << endl;
    }
}