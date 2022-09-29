#include <iostream>
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
class LLStack
{
    Node<T> *head;
    int size;

public:
    LLStack()
    {
        head = NULL;
        size = 0;
    }
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    void push(T element)
    {
        Node *newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        size++;
    }
    T top()
    {
        if(head == NULL) return -1;
        return head->data;
    }
    T pop()
    {
        if(head == NULL) return -1;
        T temp = head->data;
        head = head->next;
        size--;
        return temp;
    }
};