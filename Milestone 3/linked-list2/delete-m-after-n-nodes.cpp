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
//---------------------------------------------

Node *skipMdeleteN(Node *head, int M, int N)
{
    if (M == 0)
    {
        head = NULL;
        return head;
    }
    Node *t1 = head;
    Node *t2;
    while (t1 != NULL)
    {
        for (int i = 1; i < M && t1 != NULL; i++)
        {
            t1 = t1->next;
        }
        if (t1 == NULL)
            break;
        t2 = t1->next;
        for (int i = 1; i <= N && t2 != NULL; i++)
        {
            t2 = t2->next;
        }
        t1->next = t2;
        t1 = t2;
    }
    return head;
}
//---------------------------------------------
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *head = takeinput();
        int m, n;
        cin >> m >> n;
        head = skipMdeleteN(head, m, n);
        print(head);
    }
    return 0;
}