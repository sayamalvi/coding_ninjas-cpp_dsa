#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head; // temporary pointer storing address of head in case it gets lost
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    temp = head;
}

Node *takeInput() // O(n^2)
{
    // enter data of first node
    int data;
    cin >> data;
    // make a pointer head and store NULL
    Node *head = NULL;
    // this is a terminating condition
    while (data != -1)
    {
        // while user has not entered -1, make a new node and store data in it
        Node *n = new Node(data); // n will be de allocated after every iteration but not the node. So n will hold new address in every iteration.

        // now the address of this new node is stored in n ex: 100
        // check if head is NULL , if yes then put 100 in head
        if (head == NULL)
        {
            head = n;
        }
        // if head is not NULL make a temp pointer and store the value of head in it. Now this temp variable will traverse over the linked list and fill the next of every node with the addresses of next nodes. This will connect our linked list.
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
        cin >> data;
    }
    return head;
}
// -------------------------------------------
Node *takeInputBetter() // O(n) - optimized solution
{
    // enter data of first node
    int data;
    cin >> data;
    // make a pointer head and tail and store NULL
    Node *head = NULL;
    Node *tail = NULL;
    // this is a terminating condition
    while (data != -1)
    {
        // while user has not entered -1, make a new node and store data in it
        Node *n = new Node(data); // n will be de allocated after every iteration but not the node. So n will hold new address in every iteration.

        // now the address of this new node is stored in n ex: 100
        // check if head is NULL , if yes then put 100 in head as well as in tail
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        // if head is not null then simply store the address of new node in the next at which tail is pointing and update tail
        else
        {
            tail->next = n;
            tail = tail->next;
            // or tail = n;
        }
        cin >> data;
    }
    return head;
}
// -------------------------------------------
int main()
{
    Node *head = takeInput();
    print(head);
}