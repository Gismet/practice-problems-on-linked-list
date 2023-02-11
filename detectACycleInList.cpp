#include <iostream>
#include <unordered_set>

struct LinkedListNode
{
    int data;
    LinkedListNode *next;
    LinkedListNode() : data(0), next(NULL) {}
    LinkedListNode(int data) : data(data), next(NULL) {}
};

// if there is a cycle, then it will print infinitely
void print(LinkedListNode *head)
{
    while (head)
    {
        std::cout << head->next << " ";
        head = head->next;
    }
}

// We can use two pointers to detect the cycle in the list
// Both pointers start at the head of the linked list.
// Then the slow one moves one node ahead, and the fast one moves two nodes ahead
// If there is a cycle, then the fast pointer will eventually reach the slow pointer, coming from behind
// If there is no cycle, fast pointer will reach the end of the list, and stop iterating, at which point
// we jump out of the while loop, and return false to indicate no cycle

bool hasCycle(LinkedListNode *head)
{
    // If head node is null, there is no node, thus no cycle
    if (head == NULL)
        return false;
    // create two pointers and initialize them to head node
    LinkedListNode *slow = head;
    LinkedListNode *fast = head;
    // While the fast pointer has not reach the end of the list, move two pointers one node ahead
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) // if at any point, fast becomes slow pointer, then there is a cycle
            return true;
    }
    return false;
}

// we can use a set. We can traverse the list, checking if we have seen a node before
bool hasCycle2(LinkedListNode *head)
{
    std::unordered_set<LinkedListNode *> nodeSet;
    while (head)
    {
        if (nodeSet.count(head) > 0) // if the node is already present in the set, then there is a cycle
        {
            return true;
        }
        // otherwise insert the node to the list, and move on to the next node
        nodeSet.insert(head);
        head = head->next;
    }
    return false;
}

int main()
{
    LinkedListNode *head = new LinkedListNode(1);
    head->next = new LinkedListNode(2);
    head->next->next = new LinkedListNode(3);
    head->next->next->next = new LinkedListNode(4);
    head->next->next->next->next = head->next;

    std::cout << hasCycle(head) << "\n";
    std::cout << hasCycle2(head);

    return 0;
}