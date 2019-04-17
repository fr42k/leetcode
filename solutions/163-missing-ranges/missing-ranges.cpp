// Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//
// Example:
//
//
// Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
// Output: ["2", "4->49", "51->74", "76->99"]
//
//


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        for (int k: nums) {
            if (k > lower) {
                ans.emplace_back(to_string(lower) + (k - 1 > lower? "->" + to_string(k - 1): ""));
            }
            lower = k + 1;
            if (k == upper) {
                return ans;
            }
        }
        if (upper >= lower) {
            ans.emplace_back(to_string(lower) + (upper > lower? "->" + to_string(upper): ""));
        }
        return ans;
    }
};
