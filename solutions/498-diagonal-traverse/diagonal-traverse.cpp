// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//  
//
// Example:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
//
// Output:  [1,2,4,7,5,3,6,8,9]
//
// Explanation:
//
//
//
//  
//
// Note:
//
// The total number of elements of the given matrix will not exceed 10,000.
//


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return {};
        int n = matrix[0].size();
        vector<int> ans(m * n);
        vector<int> dir{-1, 1, -1};
        int r = 0, c = 0, k = 0;
        for (int i = 0; i < m * n; i++) {
            ans[i] = matrix[r][c];
            r += dir[k];
            c += dir[k + 1];
            if (r >= m) {
                r = m - 1;
                c += 2;
                k = 1 - k;
            }
            if (c >= n) {
                c = n - 1;
                r += 2;
                k = 1 - k;
            }
            if (r < 0) {
                r = 0;
                k = 1 - k;
            }
            if (c < 0) {
                c = 0;
                k = 1 - k;
            }
        }
        return ans;
    }
};
