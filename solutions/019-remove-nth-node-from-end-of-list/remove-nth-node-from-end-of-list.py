# Given a linked list, remove the n-th node from the end of list and return its head.
#
# Example:
#
#
# Given linked list: 1->2->3->4->5, and n = 2.
#
# After removing the second node from the end, the linked list becomes 1->2->3->5.
#
#
# Note:
#
# Given n will always be valid.
#
# Follow up:
#
# Could you do this in one pass?
#


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        dummy = ListNode()
        dummy.next = head
        fast = dummy
        while (n > 0):
            fast = fast.next
            n -= 1
        slow = dummy
        while fast.next:
            fast = fast.next
            slow = slow.next
        # slow would be the node exactly before the one we are going to remove
        slow.next = slow.next.next
        return dummy.next
