# Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
#
#  
#
# Example 1:
#
#
# Input: s1 = "ab" s2 = "eidbaooo"
# Output: True
# Explanation: s2 contains one permutation of s1 ("ba").
#
#
# Example 2:
#
#
# Input:s1= "ab" s2 = "eidboaoo"
# Output: False
#
#
#  
#
# Note:
#
#
# 	The input strings only contain lower case letters.
# 	The length of both given strings is in range [1, 10,000].
#
#


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        d = {}
        for x in s1:
            d[x] = d.get(x, 0) + 1
        t = {}
        slow, fast = 0, 0
        while fast < len(s2):
            t[s2[fast]] = t.get(s2[fast], 0) + 1
            if fast - slow + 1 == len(s1):
                if t == d:
                    return True
                t[s2[slow]] -= 1
                if t[s2[slow]] == 0:
                    t.pop(s2[slow])
                slow += 1
            fast += 1
        return False
