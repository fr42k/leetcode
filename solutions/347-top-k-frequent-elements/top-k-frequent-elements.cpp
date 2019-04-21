// Given a non-empty array of integers, return the k most frequent elements.
//
// Example 1:
//
//
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
//
//
//
// Example 2:
//
//
// Input: nums = [1], k = 1
// Output: [1]
//
//
// Note: 
//
//
// 	You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// 	Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//
//


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, set<int>> r_m;
        unordered_map<int, int> n_f;
        r_m[1] = {};
        for (int n: nums) {
            if (n_f.count(n)) {
                r_m[++n_f[n]].emplace(n);
            } else {
                n_f[n] = 1;
                r_m[1].emplace(n);
            }
        }
        vector<int> res;
        unordered_set<int> used;
        for (auto iter = r_m.rbegin(); iter != r_m.rend(); iter++) {
            auto rset = iter->second;
            for (int j: rset) {
                if (!used.count(j)) {
                    res.emplace_back(j);
                    used.emplace(j);
                    if (res.size() == k) {
                        return move(res);
                    }
                }
            }
        }
        return move(res);
    }
};
