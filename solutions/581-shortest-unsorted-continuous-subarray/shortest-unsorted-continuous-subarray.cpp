// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.  
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
//
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//
//
//
// Note:
//
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=. 
//
//


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> s_nums(nums);
        sort(s_nums.begin(), s_nums.end());
        int s = nums.size();
        int l = s;
        int r = 0;
        for (int i = 0; i < s; i++) {
            if (s_nums[i] - nums[i]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        if (l == s && r == 0) {
            return 0;
        }
        return r - l + 1;
    }
};
