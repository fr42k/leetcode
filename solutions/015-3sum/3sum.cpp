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
        // sort(nums.begin(), nums.end());
        // vector<vector<int>> ans;
        // for (int i = 0; i + 2 < nums.size(); i++) {
        //     if (i && nums[i] == nums[i - 1]) continue;
        //     int j = i + 1, k = nums.size() - 1;
        //     int t = -nums[i];
        //     while (j < k) {
        //         if (nums[j] + nums[k] == t) {
        //             ans.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
        //             while (j + 1 < nums.size() && nums[j] == nums[j + 1]) j++;
        //             while (k - 1 >= 0 && nums[k] == nums[k - 1]) k--;
        //             j++;
        //             k--;
        //         } else if (nums[j] + nums[k] > t) {
        //             k--;
        //         } else {
        //             j++;
        //         }
        //     }
        // }
        // return ans;
        vector<vector<int>> ans;
        unordered_set<int> global_used, local_used, sum;
        for (int i = 0; i + 1 < nums.size(); i++) {
            if (global_used.count(nums[i])) continue;
            local_used.clear();
            sum.clear();
            for (int j = i + 1; j < nums.size(); j++) {
                if (global_used.count(nums[j]) || local_used.count(nums[j])) continue;
                if (sum.count(-nums[i]-nums[j])) {
                    local_used.emplace(nums[j]);
                    local_used.emplace(-nums[i]-nums[j]);
                    ans.emplace_back(vector<int>{nums[i], -nums[i]-nums[j], nums[j]});
                }
                sum.emplace(nums[j]);
            }
            global_used.emplace(nums[i]);
        }
        return ans;
    }
};
