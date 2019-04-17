// Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
// Note that the row index starts from 0.
//
//
// In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
// Example:
//
//
// Input: 3
// Output: [1,3,3,1]
//
//
// Follow up:
//
// Could you optimize your algorithm to use only O(k) extra space?
//


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp;
        vector<int> tmp;
        for (int i = 0; i <= rowIndex; i++) {
            tmp = dp;
            for (int j = 0; j < tmp.size(); j++) {
                if (!j) {
                    dp[j] = 1;
                } else {
                    dp[j] = tmp[j] + tmp[j - 1]; 
                }
            }
            dp.emplace_back(1);
        }
        return move(dp);
    }
};
