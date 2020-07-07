# Given a singly linked list, determine if it is a palindrome.
#
# Example 1:
#
#
# Input: 1->2
# Output: false
#
# Example 2:
#
#
# Input: 1->2->2->1
# Output: true
#
# Follow up:
# Could you do it in O(n) time and O(1) space?
#


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if head is None or head.next is None:
            return True
        # slow would be the mid point, read if necessary
#         https://fr42k.github.io/2018/07/29/linkedListMid/
        # try to see where slow is given 3 nodes vs 4 nodes
        
        slow, fast = head, head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        second_half = slow.next
        # reverse linked list
        reversed_half = None
        while second_half:
            next_n = second_half.next
            second_half.next = reversed_half
            reversed_half = second_half
            second_half = next_n
        
        while reversed_half:
            if head.val != reversed_half.val:
                return False
            head = head.next
            reversed_half = reversed_half.next

        return True
        
