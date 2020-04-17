// Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself.  If a cell has less than 8 surrounding cells, then use as many as you can.
//
// Example 1:
//
// Input:
// [[1,1,1],
//  [1,0,1],
//  [1,1,1]]
// Output:
// [[0, 0, 0],
//  [0, 0, 0],
//  [0, 0, 0]]
// Explanation:
// For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
// For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
// For the point (1,1): floor(8/9) = floor(0.88888889) = 0
//
//
//
// Note:
//
// The value in the given matrix is in the range of [0, 255].
// The length and width of the given matrix are in the range of [1, 150].
//
//


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        if (M.empty()) {
            return M;
        }
        int m = M.size();
        int n = M[0].size();
        if (n == 0) {
            return M;
        }
        auto N = M;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                N[i][j] = getN(M, i ,j);
            }
        }
        return N;
    }
    int getV(vector<vector<int>>& M, int x, int y) {
        int m = M.size();
        int n = M[0].size();
        if (x >= 0 && x < m && y >= 0 && y < n) {
            return M[x][y];
        }
        return 0;
    }
    int getC(vector<vector<int>>& M, int x, int y) {
        int m = M.size();
        int n = M[0].size();
        if (x >= 0 && x < m && y >= 0 && y < n) {
            return 1;
        }
        return 0;
    }
    int getN(vector<vector<int>>& M, int x, int y) {
        int sum = 0;
        int ct = 0;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                sum += getV(M, i, j);
                ct += getC(M, i, j);
            }
        }
        return sum/ct;
    }
};
