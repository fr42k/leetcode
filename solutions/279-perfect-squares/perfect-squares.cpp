// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.


class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};
        while (dp.size() <= n) {
            int m = dp.size();
            int dp_i = INT_MAX;
            for (int i = 1; i * i <= m; i++) {
                dp_i = min(dp_i, dp[m - i*i] + 1);
            }
            dp.emplace_back(dp_i);
        }
        return dp[n];
    }
};
