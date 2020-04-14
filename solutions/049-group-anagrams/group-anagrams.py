# Given an array of strings, group anagrams together.
#
# Example:
#
#
# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
#   ["ate","eat","tea"],
#   ["nat","tan"],
#   ["bat"]
# ]
#
# Note:
#
#
# 	All inputs will be in lowercase.
# 	The order of your output does not matter.
#
#


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for s in strs:
            def mysort(s):
                v = sorted(s)
                ret = ""
                for x in v:
                    ret += x
                return ret
            u = mysort(s)
            if u not in d:
                d[u] = [s]
            else:
                d[u].append(s)
        ans = []
        for _, v in d.items():
            ans.append(v)
        return ans
