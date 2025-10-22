#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next; // Pointer to the next node
};

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "nullptr" << endl;
}

Node *insertAtBeginning(Node *head, int value)
{
    Node *newNode = new Node{value, head};
    return newNode;
}

Node *deleteNode(Node *head, int value)
{
    if (head == nullptr)
        return nullptr;

    if (head->data == value)
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }

    Node *current = head;

    while (current->next != nullptr && current->next->data != value)
    {
        current = current->next;
    }

    if (current->next != nullptr)
    {
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    return head;
}

int main()
{
    // Node *head = new Node{1, nullptr};
    // head->next = new Node{2, nullptr};
    // head->next->next = new Node{3, nullptr};
    // printList(head);

    Node *head{};

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);

    printList(head);

    head = deleteNode(head, 20);

    printList(head);

    return 0;
}