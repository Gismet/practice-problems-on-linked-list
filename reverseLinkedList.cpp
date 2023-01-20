#include <iostream>
#include <stack>

/* Given the head of a singly linked list, reverse the order of the elements and return the new head.
 * Note: you have to reverse the links. Don't just reverse the values the nodes have
 */
// 1 -> 2 -> 3 -> 4 -> null   =>  4 -> 3 -> 2 -> 1 -> null;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(NULL) {}
};

/* Here's the idea. Starting at the head node we are going to reverse the link between two adjacent nodes
 * up to the end of the list. Let's say we have a list 1 -> 2 -> 3 -> null, starting at the head node 1 we reverse its next pointer
 * to point back. In this case head node 1 will be the tail node of reversed list, so it will point to null.
 *  null <- 1  2 -> 3 -> null. Then we go to the next node, which is 2 and reverse its next pointer to point back to node 1
 * Here we have to careful not to lose the rest of the list when reversing next pointer of a node. We have to keep track of the head
 * of the rest of the linked list.  So after the second reversal, the link will look like null <- 1 <- 2  3 -> null.
 * We repeat the process untill the end of the list.
 */

ListNode *reverseLinkedList(ListNode *head)
{
    // keep track of two pointers : previous and current nodes
    ListNode *prev = NULL;
    ListNode *curr = head;

    // as long as the current node is not null
    while (curr)
    {
        ListNode *temp = curr->next; // not to lost the next pointer of the current node
        curr->next = prev;           // reverse the next pointer of the current node back to the previous node
        prev = curr;                 // the current node becomes the new previous node
        curr = temp;                 // The current node moves node toward the end of the list
    }
    // at the end, prev will be the head of the reversed list
    head = prev;
    return head;
}

ListNode *reverseRecursive(ListNode *head)
{
    // handel the most trivial cases
    if (head == NULL || head->next == NULL)
        return head;
    // Reverse the list starting from the second node
    ListNode *newHead = reverseRecursive(head->next);
    // head;
    // 1 -> 2 <- 3 <- 4
    //     /          newHead;
    //   null

    // node 2 points to null, we make it point back to node 1 and the node 1 point back to null
    // then return the newHead;

    // Make the node that comes after the head node point back to head
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

// to display the linked list nodes
void print(ListNode *head)
{
    if (head)
    {
        std::cout << head->val << " ";
        print(head->next);
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    std::cout << "The linked list before reversal: ";
    print(head);
    std::cout << std::endl;

    std::cout << "The linked list after reversal: ";
    head = reverseRecursive(head);
    print(head);

    return 0;
}