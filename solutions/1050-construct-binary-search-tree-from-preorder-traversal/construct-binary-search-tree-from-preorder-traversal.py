# Return the root node of a binary search tree that matches the given preorder traversal.
#
# (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)
#
#  
#
# Example 1:
#
#
# Input: [8,5,1,7,10,12]
# Output: [8,5,10,1,7,null,12]
#
#
#
#  
#
# Note: 
#
#
# 	1 <= preorder.length <= 100
# 	The values of preorder are distinct.
#
#


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        if len(preorder) == 0:
            return None
        t = preorder[0]
        root = TreeNode(t)
        l, r = 1, len(preorder) - 1
        while l < r:
            m = l + (r - l) // 2
            if preorder[m] < t:
                l = m + 1
            else:
                r = m
        if l == len(preorder) or preorder[l] < t:
            root.left = self.bstFromPreorder(preorder[1:])
            root.right = self.bstFromPreorder([])
        else:
            root.left = self.bstFromPreorder(preorder[1: l])
            root.right = self.bstFromPreorder(preorder[l:])
        return root
