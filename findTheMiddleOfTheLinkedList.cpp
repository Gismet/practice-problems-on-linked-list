#include <iostream>

/*Given the head of a singly linked list, return the middle element of the list.
If the list has an even number of elements, return the second middle element.*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(NULL) {}
};

// set two pointer to the head of the list: one slow and one fast
// fast pointer will move twice as fast as slow pointer.
// In particular, while fast pointer will be moving two nodes ahead, slow pointer will move only one node ahead
// When the fast pointer get to the end of the list, slow pointer will be somewhere in the middle.
// If the length of the list is odd, then the slow will be the middle node when fast gets to the end
// If the length of the list is even, then the slow will be the second middle node when fast gets to the end

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode *findMiddleUsingLength(ListNode *head)
{
    int len = 0;
    ListNode *loopPtr = head;
    // find the length of the list
    while (loopPtr)
    {
        len++;
        loopPtr = loopPtr->next;
    }
    loopPtr = head;
    int i = 0;
    // iterate up to the middle
    while (i < len / 2)
    {
        loopPtr = loopPtr->next;
        i++;
    }
    return loopPtr;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    // 1 -> 2 -> 3 -> 4 -> 5 -> null

    ListNode *middleNode = findMiddleUsingLength(head);
    std::cout << middleNode->val;

    return 0;
}