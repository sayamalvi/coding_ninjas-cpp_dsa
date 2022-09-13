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
// ----------------------------------------
void printIthNode(Node *head, int i)
{

    int count = 0;
    Node *temp = head;
    if (temp == NULL)
        return;
    while (count <= i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (i > count)
        return;
    cout << temp->data;
}
// ------------------------------------------
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int pos;
        cin >> pos;
        printIthNode(head, pos);
        cout << endl;
    }
    return 0;
}