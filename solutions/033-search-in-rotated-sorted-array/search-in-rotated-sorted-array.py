# Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
#
# (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
#
# You are given a target value to search. If found in the array return its index, otherwise return -1.
#
# You may assume no duplicate exists in the array.
#
# Your algorithm's runtime complexity must be in the order of O(log n).
#
# Example 1:
#
#
# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4
#
#
# Example 2:
#
#
# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1
#


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        if n == 0:
            return -1
        l, r = 0, n - 1
        while l < r:
            m = l + (r - l) // 2
            if nums[m] == target:
                return m
            if (nums[l] <= nums[m]):
                if nums[l] <= target and target < nums[m]:
                    r = m - 1
                else:
                    l = m + 1
            else:
                if nums[m] < target and target <= nums[r]:
                    l = m + 1
                else:
                    r = m - 1
        return l if  nums[l] == target else -1
