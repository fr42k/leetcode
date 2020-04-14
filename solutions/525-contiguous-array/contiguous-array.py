# Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 
#
#
# Example 1:
#
# Input: [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
#
#
#
# Example 2:
#
# Input: [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
#
#
#
# Note:
# The length of the given binary array will not exceed 50,000.
#


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        ans = 0
        pos = {}
        pos[0] = -1
        s = 0
        for i in range(len(nums)):
            s += 1 if nums[i] > 0 else -1
            if s in pos:
                ans = max(ans, i - pos[s])
            else:
                pos[s] = i
        return ans
