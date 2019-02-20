// A sequence of numbers is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
//
// For example, these are arithmetic sequences:
// 1, 3, 5, 7, 9
// 7, 7, 7, 7
// 3, -1, -5, -9
//
// The following sequence is not arithmetic. 1, 1, 2, 5, 7 
//
//
// A zero-indexed array A consisting of N numbers is given. A subsequence slice of that array is any sequence of integers (P0, P1, ..., Pk) such that 0 ≤ P0 < P1 < ... < Pk < N.
//
// A subsequence slice (P0, P1, ..., Pk) of array A is called arithmetic if the sequence A[P0], A[P1], ..., A[Pk-1], A[Pk] is arithmetic. In particular, this means that k ≥ 2.
//
// The function should return the number of arithmetic subsequence slices in the array A. 
//
// The input contains N integers. Every integer is in the range of -231 and 231-1 and 0 ≤ N ≤ 1000. The output is guaranteed to be less than 231-1.
//
//
// Example:
//
// Input: [2, 4, 6, 8, 10]
//
// Output: 7
//
// Explanation:
// All arithmetic subsequence slices are:
// [2,4,6]
// [4,6,8]
// [6,8,10]
// [2,4,6,8]
// [4,6,8,10]
// [2,4,6,8,10]
// [2,6,10]
//
//


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n <= 2) return 0;
        vector<unordered_map<int, int>> dp(n);
        // 等差数列个数
        int ans = 0;
        // 最长等差数列
        // int maxlen = 0, last = -1, df = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)A[i] - (long)A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                // dp[i][diff] + 1: 结尾为A[i], 公差为diff的等差数列的长度
                dp[i][diff] += 1;
                if (dp[j].count(diff)) {
                    dp[i][diff] += dp[j][diff];
                    ans += dp[j][diff];
                }
                /* 最长等差数列
                if (dp[i][diff] > maxlen) {
                    maxlen = dp[i][diff];
                    df = diff;
                    last = A[i];
                }
                */
            }
        }
        /* 最长等差数列
        vector<int> as(maxlen + 1);
        for (int i = maxlen; i >= 0; i--) {
            as[i] = last;
            last -= df;
        }
        for (int v: as) {
            cout << v << endl;
        }
        */
        return ans;
    }
};
