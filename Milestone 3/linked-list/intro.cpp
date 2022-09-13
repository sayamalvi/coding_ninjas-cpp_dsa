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
int main()
{
    // statically
    // Node n1(1);
    // Node *head = &n1;

    // Node n2(2);
    // Node n3(3);
    // Node n4(4);
    // Node n5(5);

    // n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;
    // n4.next = &n5;

    // Node::print(head);

    // dynamically
    Node *n1 = new Node(1);
    Node *head = n1;

    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    print(head);
}