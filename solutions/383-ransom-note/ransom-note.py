# Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
#
# Each letter in the magazine string can only be used once in your ransom note.
#
#  
# Example 1:
# Input: ransomNote = "a", magazine = "b"
# Output: false
# Example 2:
# Input: ransomNote = "aa", magazine = "ab"
# Output: false
# Example 3:
# Input: ransomNote = "aa", magazine = "aab"
# Output: true
#
#  
# Constraints:
#
#
# 	You may assume that both strings contain only lowercase letters.
#
#


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        r = {}
        for x in ransomNote:
            r[x] = r.get(x, 0) + 1
        m = {}
        for x in magazine:
            m[x] = m.get(x, 0) + 1
        for k, v in r.items():
            if k not in m or v > m[k]:
                return False
        return True
