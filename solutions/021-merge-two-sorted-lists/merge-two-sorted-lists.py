# Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
#
# Example:
#
#
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4
#
#


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        x = ListNode()
        h = x
        p, q = l1, l2
        while p and q:
            if p.val < q.val:
                x.next = p
                p = p.next
            else:
                x.next = q
                q = q.next
            x = x.next
#       only p or q not null
        if p:
            x.next = p
        else:
            x.next = q
        return h.next
