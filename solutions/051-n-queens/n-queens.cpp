// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> avail(n + 2 * n - 1 + 2 * n - 1, 1);
        search(board, avail, 0, ans);
        return ans;
    }
    void search(vector<string>& board, vector<int>& avail, int row, vector<vector<string>>& ans) {
        int n = board.size();
        if (row == n) {
            ans.emplace_back(board);
        }
        for (int col = 0; col < n; col++) {
            if (avail[col] && avail[n + row + col] && avail[3 * n - 1 + n - row + col - 1]) {
                avail[col] = avail[n + row + col] = avail[3 * n - 1 + n - row + col - 1] = 0;
                board[row][col] = 'Q';
                search(board, avail, row + 1, ans);
                board[row][col] = '.';
                avail[col] = avail[n + row + col] = avail[3 * n - 1 + n - row + col - 1] = 1;
            }
        }
    }
};
