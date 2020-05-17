# Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
#
# Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
#
# The order of output does not matter.
#
# Example 1:
#
# Input:
# s: "cbaebabacd" p: "abc"
#
# Output:
# [0, 6]
#
# Explanation:
# The substring with start index = 0 is "cba", which is an anagram of "abc".
# The substring with start index = 6 is "bac", which is an anagram of "abc".
#
#
#
# Example 2:
#
# Input:
# s: "abab" p: "ab"
#
# Output:
# [0, 1, 2]
#
# Explanation:
# The substring with start index = 0 is "ab", which is an anagram of "ab".
# The substring with start index = 1 is "ba", which is an anagram of "ab".
# The substring with start index = 2 is "ab", which is an anagram of "ab".
#
#


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        t = {}
        for x in p:
            t[x] = t.get(x, 0) + 1
        d = {}
        ans = []
        slow, fast = 0, 0
        while fast < len(s):
            d[s[fast]] = d.get(s[fast], 0) + 1
            if fast - slow + 1 == len(p):
                if d == t:
                    ans.append(slow)
                d[s[slow]] -= 1
                if d[s[slow]] == 0:
                    d.pop(s[slow])
                slow += 1
            fast += 1
        return ans
