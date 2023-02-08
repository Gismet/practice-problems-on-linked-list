#include <iostream>

// You are given two sorted linked lists and required to merge two lists.
//  Let's say you are given a list 1 -> 3 -> 5 and another one 2 -> 4.
//  Your task is to merge these two linked lists. The merge list would look like this 1 -> 2 -> 3 -> 4 -> 5

// We can solve this problem iteratively or recursively
//  I chose to solve the problem recursively because it perfectly lends itself to recursion

// As with any recursive procedure, there are certain things we have to answer
//  Let's start with defining the base case or cases
//  Let's ask this question: What's the simplest input that can be solved easly or alrady solved ?
//  or what's the situation or the instance of the problem in which one can make sure that the problem is solved
//  or can be solved with a little bit effort
// Okay, let's try to answer this question: In this case the simplest input is when at least of the two lists is empty, that is null
// Let me be clear on that. Let's say we are presented with two lists: 2 and null. The first list has 1 node and the second
// list does not have any node. What should we do in this case?. What should we return?. Now it is obvious that we should return the
// list that is not empty. In this case it is the first list. Now let's consider another case. What about two empty lists
// In this case we can return either one of them, since both are null. Okay now this forms our base cases. Let's move on.

// Now what if the lists are not simple. By simple I mean they are relatively long enough that can not be handle by base cases
// Let's consider these two lists again. 1 -> 3 -> 5 and  2 -> 4. What should we do in this case?. Now we should try to reduce the
// input size or in other words we should do a little bit of work and assign the rest of the work to a recursive call.
// Okay, So we should be lazy and do a bit of work. Let's do it. Now consider the heads of the two lists. What does it tell us ?
// We know that one of the two heads must be the head of the final merged list. Now how do we define that head ?
// We know that the final list should also be sorted, in other words it will start from the node with smallest value.
// So the job we do here is to just choose the head of the final merged list, which is the head with the smallest value.
// In this case the head of the final merged list is the head of the first list since it has the smallest value.
// Okay, we have done our little work and we should not be concerned about the rest of work. It will be done by recursive call.
// Now we choose the head, which is the head of the first list. Now What do we have left ? the list 3 -> 5 and the list 2 -> 4.
// Now we call our merge function to merge two lists. After the merge function is done with merging two list, we will have
// the merge list 2 -> 3 -> 4 -> 5. Now one final thing, we should add the node we keep, which is the head node with value 1.
// So we add it to the front and get the final result. 1 -> 2 -> 3 -> 4 -> 5

// A structure for list node
struct LinkedListNode
{
    int data;
    LinkedListNode *next;
    LinkedListNode() {}
    LinkedListNode(int data) : data(data), next(NULL) {}
};

LinkedListNode *mergeLists(LinkedListNode *list1, LinkedListNode *list2)
{
    // base cases
    if (list1 == NULL) // check if the first list is empyt, if yes return the second list
        return list2;
    if (list2 == NULL) // otherwise, check if the second list is empty, if yes return the first one
        return list1;

    // Choose the head of the merged list. It will be the node with smallest value
    if (list1->data < list2->data)
    {
        list1->next = mergeLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeLists(list1, list2->next);
        return list2;
    }
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

int main()
{
    LinkedListNode *list1 = new LinkedListNode(1);
    list1->next = new LinkedListNode(3);
    list1->next->next = new LinkedListNode(5);

    LinkedListNode *list2 = new LinkedListNode(2);
    list2->next = new LinkedListNode(4);

    LinkedListNode *mergedList = mergeLists(list1, list2);
    print(mergedList);

    return 0;
}