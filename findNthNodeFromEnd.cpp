#include <iostream>

struct LinkedListNode
{
    int data;
    LinkedListNode *next;
    LinkedListNode() : data(0), next(NULL) {}
    LinkedListNode(int data) : data(data), next(NULL) {}
};

// Add a node to the beginning of the list
void addNode(LinkedListNode *&head, int val)
{
    LinkedListNode *newNode = new LinkedListNode(val);
    newNode->next = head;
    head = newNode;
}

void print(LinkedListNode *head)
{
    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
}

LinkedListNode *findAndRemove(LinkedListNode *head, int n)
{
    LinkedListNode *dummy = new LinkedListNode();
    dummy->next = head; // create a dummy node to beginning of the list
    // create two pointers: left and right
    LinkedListNode *left = dummy;  // initialize left pointer to dummy node
    LinkedListNode *right = dummy; // initialize right pointer to dummy node
    int i = 0;
    // move right pointer n + 1 node further away from the left pointer
    while (i <= n)
    {
        right = right->next;
        i++;
    }
    while (right) // as long as right pointer is not null
    {
        // move left and right pointer to the next node
        left = left->next;
        right = right->next;
    }
    // left will point to the node one before the node we want to remove
    left->next = left->next->next;
    // return the head of the list
    return dummy->next;
}

int main()
{
    LinkedListNode *head = new LinkedListNode(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);

    int n = 2;

    head = findAndRemove(head, n);
    print(head);

    return 0;
}