#include <iostream>

using std::cout;
using std::endl;

struct Node
{
    int data;
    Node *next; // Points to the next node (or the head for the last node)
};

void printCircularList(Node *head)
{
    if (head == nullptr)
        return;

    Node *temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD" << endl;
}

Node *insertInCircularList(Node *head, int value)
{
    Node *newNode = new Node{value, nullptr};

    if (head == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}

int main()
{
    Node *head{};

    printCircularList(head);

    head = insertInCircularList(head, 10);
    head = insertInCircularList(head, 20);
    head = insertInCircularList(head, 30);
    head = insertInCircularList(head, 40);

    printCircularList(head);

    return 0;
}