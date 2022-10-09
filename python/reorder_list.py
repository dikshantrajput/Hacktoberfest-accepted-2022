"""
https://leetcode.com/problems/reorder-list/

143. Reorder List
Medium

6917

237

Add to List

Share
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
 

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000
"""
# Definition for singly-linked list.
from string import printable
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        #cut in half
        h = self.cutinhalf(head)

        # reverse the other half
        h = self.reverse(h)

        p = head

        while h:
            n = h.next
            h.next = p.next
            p.next = h

            p = p.next.next
            h = n

        self.printall(head)
    # helper methods

    def printall(self, head):
        t = head
        while t:
            print(t.val)
            t = t.next

    def cutinhalf(self, head):
        if not head or not head.next:
            return None

        p, q = head, head

        while p.next and p.next.next:
            p = p.next.next
            q = q.next

        t = q.next
        q.next = None
        return t

    def reverse(self, head):
        if not head or not head.next:
            return head

        p, c, n = None, head, head.next

        while n:
            c.next = p

            p, c, n = c, n, n.next

        c.next = p
        return c


head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)

# a = ListNode()
# print_all(head)
a = Solution()
a.reorderList(head)
