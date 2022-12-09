# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        def mergeTwoLists(l1, l2):
            curr = dummy = ListNode(0)
            while l1 and l2:
                if l1.val < l2.val:
                    curr.next = l1
                    l1 = l1.next
                else:
                    curr.next = l2
                    l2 = l2.next
                curr = curr.next
            curr.next = l1 or l2
            return dummy.next
    
        def mergeKListsHelper(lists, begin, end):
            if begin > end:
                return None
            if begin == end:
                return lists[begin]
            return mergeTwoLists(mergeKListsHelper(lists, begin, (begin + end) / 2), \
                                 mergeKListsHelper(lists, (begin + end) / 2 + 1, end))
        return mergeKListsHelper(lists, 0, len(lists) - 1)
        
