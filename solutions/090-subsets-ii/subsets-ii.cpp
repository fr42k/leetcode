// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
// Example:
//
//
// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
//
//


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> sv;
        int s = nums.size();
        vector<int> tmp;
        travel(nums, 0, s, &tmp, &sv);
        vector<vector<int>> res;
        for (auto k: sv) {
            res.emplace_back(k);
        }
        return move(res);
    }
private:
    void travel(const vector<int>& nums, int pos, int s, vector<int>* tmp, set<vector<int>>* sv) {
        if (s > pos) {
            travel(nums, pos + 1, s, tmp, sv);
            tmp->emplace_back(nums[pos]);
            travel(nums, pos + 1, s, tmp, sv);
            tmp->pop_back();
        } else {
            auto p(*tmp);
            sort(p.begin(), p.end());
            sv->emplace(move(p));
            return;
        }
    }
};
