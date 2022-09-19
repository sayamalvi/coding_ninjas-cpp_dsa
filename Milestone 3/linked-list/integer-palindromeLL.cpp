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
//----------------------------------------
Node *mid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverse(Node *head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *small = reverse(head->next);
    Node *tail = head->next;

    tail->next = head;
    head->next = NULL;

    return small;
}
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    Node *getMid = mid(head);
    Node *secondHead = reverse(getMid->next);

    getMid->next = NULL;
    bool isPal = true;

    Node *temp = getMid;

    while (head != NULL && secondHead != NULL)
    {
        if (head->data != secondHead->data)
            return false;
        ;

        head = head->next;
        secondHead = secondHead->next;
    }

    return true;
}

//----------------------------------------
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = takeinput();
        bool ans = isPalindrome(head);

        if (ans)
            cout << "true";
        else
            cout << "false";

        cout << endl;
    }

    return 0;
}