// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
//
// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
// Note:
//
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
//
//
// Example:
//
// Given the following 5x5 matrix:
//
//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic
//
// Return:
//
// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
//
//


class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) return {};
        int n = matrix[0].size();
        if (!n) return {};
        vector<pair<int, int>> ans;
        vector<vector<int>> pacif(m, vector<int>(n, 0));
        vector<vector<int>> atlan(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(matrix, i, 0, m, n, INT_MIN, pacif);
            dfs(matrix, i, n - 1, m, n, INT_MIN, atlan);
        }
        for (int j = 0; j < n; j++) {
            dfs(matrix, 0, j, m, n, INT_MIN, pacif);
            dfs(matrix, m - 1, j, m, n, INT_MIN, atlan);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacif[i][j] && atlan[i][j]) {
                    ans.emplace_back(i, j);
                }
            }
        }
        return ans;
    }
    vector<int> dir{0, 1, 0, -1, 0};
    void dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, int h, vector<vector<int>>& sea) {
        if (i < 0 || i >= m || j < 0 || j >= n || sea[i][j] || matrix[i][j] < h) return;
        sea[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            dfs(matrix, i + dir[k], j + dir[k + 1], m, n, matrix[i][j], sea);
        }
    }
};
