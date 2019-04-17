// A peak element is an element that is greater than its neighbors.
//
// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
//
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
// You may imagine that nums[-1] = nums[n] = -∞.
//
// Example 1:
//
//
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
//
// Example 2:
//
//
// Input: nums = [1,2,1,3,5,6,4]
// Output: 1 or 5 
// Explanation: Your function can return either index number 1 where the peak element is 2, 
//              or index number 5 where the peak element is 6.
//
//
// Note:
//
// Your solution should be in logarithmic complexity.
//


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return f(nums, 0, nums.size() - 1);
    }
private:
    int f(vector<int>& nums, int l, int r) {
        if (l >= r - 1) {
            return nums[l] > nums[r] ? l: r;
        }
        int m = (l+r)>> 1;
        if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
            return m;
        }
        int fl = f(nums, l, m);
        int fr = f(nums, m, r);
        return nums[fl] > nums[fr] ? fl: fr;
    }
};
