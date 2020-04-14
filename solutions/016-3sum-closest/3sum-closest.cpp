// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int s = nums.size();
        int ans = 0;
        if (s <= 3) {
            for (int n: nums) {
                ans += n;
            }
            return ans;
        }
        int tmp = 0;
        sort(nums.begin(), nums.end());
        ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < s; i++) {
            int j = i + 1;
            int k = s - 1;
            while (j < k) {
                tmp = nums[i] + nums[j] + nums[k];
                if (abs(tmp - target) < abs(ans - target)) {
                    ans = tmp;
                }
                tmp > target ? k--: j++;
            }
        }
        return ans;
    }
};
