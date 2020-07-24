# Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
#
#  
#
# Example 1:
#
#
#
# Input: A = "ab", B = "ba"
# Output: true
#
#
#
# Example 2:
#
#
# Input: A = "ab", B = "ab"
# Output: false
#
#
#
# Example 3:
#
#
# Input: A = "aa", B = "aa"
# Output: true
#
#
#
# Example 4:
#
#
# Input: A = "aaaaaaabc", B = "aaaaaaacb"
# Output: true
#
#
#
# Example 5:
#
#
# Input: A = "", B = "aa"
# Output: false
#
#
#
#
#
#
#
#  
# Constraints:
#
#
# 	0 <= A.length <= 20000
# 	0 <= B.length <= 20000
# 	A and B consist only of lowercase letters.
#
#


class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A == B and len(set(A)) < len(A):
            return True
        diff = []
        for i in range(len(A)):
            if A[i] != B[i]:
                diff.append(i)
        if len(diff) == 2 and A[diff[0]] == B[diff[1]] and A[diff[1]] == B[diff[0]]:
            return True
        return False
