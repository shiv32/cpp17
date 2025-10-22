#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next; // Pointer to the next node
    Node *prev; // Pointer to the previous node
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }

    cout << "nullptr" << endl;
}

Node *insertAtEnd(Node *head, int value)
{
    Node *newNode = new Node{value, nullptr, nullptr};

    if (head == nullptr)
        return newNode;

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

Node *deleteNode(Node *head, int value)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
        return head;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp == head)
        head = temp->next;

    delete temp;

    return head;
}

int main()
{
    Node *head{};

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printList(head);

    head = deleteNode(head, 10);

    printList(head);

    return 0;
}