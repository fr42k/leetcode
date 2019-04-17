// Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example1:
//
// Input: [1,3,2,3,1]
// Output: 2
//
//
// Example2:
//
// Input: [2,4,3,5,1]
// Output: 3
//
//
// Note:
//
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.
//
//


class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size());
    }
    int mergesort(vector<int>& nums, int l, int h) {
        if (h - l <= 1) return 0;
        int m = l + (h - l) / 2;
        int cnt = mergesort(nums, l, m) + mergesort(nums, m, h);
        int p1 = l, p2 = m;
        while (p1 < m) {
            while (p2 < h && 1.0 * nums[p1] > 2.0 * nums[p2]) {
                p2++;
            }
            cnt += p2 - m;
            p1++;
        }
        sort(nums.begin() + l, nums.begin() + h);
        return cnt;
    }
};
