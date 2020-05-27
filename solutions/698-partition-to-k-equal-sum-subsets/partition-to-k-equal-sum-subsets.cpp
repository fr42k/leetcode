// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.
//
//  
//
// Example 1:
//
//
// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
//
//
//  
//
// Note:
//
//
// 	1 <= k <= len(nums) <= 16.
// 	0 < nums[i] < 10000.
//
//


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) return true;
        if (k <= 0 || k > n) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        vector<int> subset(k, 0), used(n, 0);
        return parti(nums, 0, subset, 0, sum / k, used);
    }
    bool parti(vector<int>& nums, int idx, vector<int>& subset, int subidx, int target, vector<int>& used) {
        if (subset[subidx] == target) {
            if (subidx == subset.size() - 2) return true;
            return parti(nums, 0, subset, subidx + 1, target, used);
        }
        for (int i = idx; i < nums.size(); i++) {
            if (used[i]) continue;
            if (subset[subidx] + nums[i] <= target) {
                used[i] = 1;
                subset[subidx] += nums[i];
                if (parti(nums, i + 1, subset, subidx, target, used)) return true;
                subset[subidx] -= nums[i];
                used[i] = 0;
            }
        }
        return false;
    }
};
