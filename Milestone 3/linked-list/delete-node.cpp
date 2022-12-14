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
// ---------------------------------------
Node *deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }
    int count = 0;
    Node *temp = head;
    if (pos == 0)
    {
        head = head->next;
        return head;
    }
    while (temp->next != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
        return head;

    Node *a = temp->next;
    Node *b = a->next;
    temp->next = b;
    delete a;
    return head;
}
// ---------------------------------------

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        head = deleteNode(head, pos);
        print(head);
    }

    return 0;
}