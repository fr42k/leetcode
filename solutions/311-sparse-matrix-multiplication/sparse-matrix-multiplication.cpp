// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
//
// Input:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
// Output:
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
//
//


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = B.size();
        int z = B[0].size();
        vector<vector<int>> ans(m, vector<int>(z, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!A[i][j]) continue;
                for (int k = 0; k < z; k++) {
                    if (!B[j][k]) continue;
                    ans[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return ans;
    }
};
