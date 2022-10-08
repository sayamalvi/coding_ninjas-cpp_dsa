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
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
//---------------------------------------
void printReverse(Node *head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        cout << head->data << " ";
        return;
    }
    printReverse(head->next);
    cout << head->data << " ";
    return;
}
//---------------------------------------
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        printReverse(head);
        cout << endl;
    }
    return 0;
}