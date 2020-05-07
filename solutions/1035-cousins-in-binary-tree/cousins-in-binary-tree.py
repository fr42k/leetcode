# In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.
#
# Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
#
# We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.
#
# Return true if and only if the nodes corresponding to the values x and y are cousins.
#
#  
#
# Example 1:
#
#
#
# Input: root = [1,2,3,4], x = 4, y = 3
# Output: false
#
#
#
# Example 2:
#
#
#
# Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
# Output: true
#
#
#
# Example 3:
#
#
#
#
# Input: root = [1,2,3,null,4], x = 2, y = 3
# Output: false
#
#  
#
#
#
# Note:
#
#
# 	The number of nodes in the tree will be between 2 and 100.
# 	Each node has a unique integer value from 1 to 100.
#
#
#
#
#  
#
#


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import OrderedDict
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        if root is None:
            return False
        level = OrderedDict()
        level[root] = 0
        while len(level) > 0:
            l = len(level)
            found = False
            v = -1
            for _ in range(l):
                r, p = level.popitem(last=False)
                if r.left:
                    level[r.left] = r.val
                    if r.left.val == x or r.left.val == y:
                        if found:
                            if v != r.val:
                                return True
                            else:
                                return False
                        else:
                            found = True
                            v = r.val
                if r.right:
                    level[r.right] = r.val
                    if r.right.val == x or r.right.val == y:
                        if found:
                            if v != r.val:
                                return True
                            else:
                                return False
                        else:
                            found = True
                            v = r.val
            if found:
                return False
        return False
