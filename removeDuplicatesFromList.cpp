#include <iostream>

// A structure for linked list node
struct LinkedListNode
{
    int data;
    LinkedListNode *next;
    LinkedListNode() {}
    LinkedListNode(int data) : data(data), next(NULL) {}
};

void addNode(LinkedListNode *&head, int val)
{
    if (head == NULL)
    {
        head = new LinkedListNode(val);
        return;
    }
    LinkedListNode *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new LinkedListNode(val);
}

void print(LinkedListNode *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

LinkedListNode *deleteDuplicates(LinkedListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    LinkedListNode *rest = deleteDuplicates(head->next);
    if (head->data == rest->data)
        return rest;
    head->next = rest;
    return head;
}

int main()
{
    LinkedListNode *head = NULL;
    addNode(head, 1);
    addNode(head, 1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 3);

    head = deleteDuplicates(head);
    print(head);

    return 0;
}