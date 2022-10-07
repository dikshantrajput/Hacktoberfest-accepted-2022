// Problem Link : https://leetcode.com/problems/odd-even-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// A linked list is a data structure where the objects are arranged in a linear order. Unlike an array, however, in which the linear order is determined by the array indices, the order in a linked list is determined by a pointer in each object.
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        // If there are just 0 or 1 or 2 nodes directly return the head;
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode *odd = head, *even = head->next, *anchor = head->next;

        // Connect all the odd nodes with each other and all even with each other
        while (odd->next && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        // Connect the last odd node with the first even node
        odd->next = anchor;
        return head;
    }
};