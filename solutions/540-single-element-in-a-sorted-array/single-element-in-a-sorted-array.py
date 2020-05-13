# You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
#
#  
#
# Example 1:
#
#
# Input: [1,1,2,3,3,4,4,8,8]
# Output: 2
#
#
# Example 2:
#
#
# Input: [3,3,7,7,10,11,11]
# Output: 10
#
#
#  
#
# Note: Your solution should run in O(log n) time and O(1) space.
#


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l, h = 0, len(nums) - 1
        while l < h:
            m = (l + h) // 2
            if nums[m] == nums[m^1]:
                l = m + 1
            else:
                h = m
        return nums[l]
