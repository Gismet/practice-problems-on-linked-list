#include <iostream>

/* Write a function that is given a singly linked list where the data type is integer.
 * The function returns the count of negative numbers in the list
 */

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int data) : data(data), next(NULL) {}
};

int countNegativeNodes(ListNode *head)
{
    int count = 0;
    while (head)
    {
        if (head->data < 0)
            count++;
        head = head->next;
    }
    return count;
}

int countNegativesInList(ListNode *head)
{
    // if the list is empty, no nodes
    if (head == NULL)
        return 0;
    // find the count of negative integers in the rest of the list, starting at the second node
    int restCount = countNegativesInList(head->next);
    if (head->data < 0) // check if the first node is negative, if yes, increment the count
        restCount++;
    return restCount;
}

int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(-9);
    head->next->next = new ListNode(-4);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(-11);

    std::cout << countNegativesInList(head);

    return 0;
}