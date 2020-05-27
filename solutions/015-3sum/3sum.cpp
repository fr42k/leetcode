// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        int n = nums.size();
        unordered_set<int> used1, used2, sum;
        vector<vector<int>> ans;
        for (int i = 0; i <= n - 3; i++) {
            if (!used1.count(nums[i])) {
                int t = -nums[i];
                used2.clear();
                sum.clear();
                for (int j = i + 1; j < n; j++) {
                    if (!used1.count(nums[j]) && !used2.count(nums[j])) {
                        if (sum.count(t - nums[j])) {
                            ans.emplace_back(vector<int>{nums[i], t - nums[j], nums[j]});
                            used2.emplace(nums[j]);
                        } else {
                            sum.emplace(nums[j]);
                        }
                    }
                }
                used1.emplace(nums[i]);
            }
        }
        return ans;
        */
        int n = nums.size();
        unordered_set<int> used1;
        vector<vector<int>> ans;
        unordered_set<int> used2, sum2;
        for (int i = 0; i <= n - 3; i++) {
            if (!used1.count(nums[i])) {
                int t = -nums[i];
                used2.clear();
                sum2.clear();
                for (int j = i + 1; j < n; j++) {
                    if (!used1.count(nums[j]) && !used2.count(nums[j])) {
                        if (sum2.count(t - nums[j])) {
                            ans.emplace_back(vector<int>{nums[i], t - nums[j], nums[j]});
                            used2.emplace(nums[j]);
                        } else {
                            // avoid duplicate
                            sum2.emplace(nums[j]);
                        }
                    }
                }
                used1.emplace(nums[i]);
            }
        }
        return ans;
    }
};
