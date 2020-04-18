# Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
#
# Note: You can only move either down or right at any point in time.
#
# Example:
#
#
# Input:
# [
#   [1,3,1],
#   [1,5,1],
#   [4,2,1]
# ]
# Output: 7
# Explanation: Because the path 1→3→1→1→1 minimizes the sum.
#
#


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if grid == None:
            return 0
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for j in range(1, n + 1):
            dp[1][j] = dp[1][j - 1] + grid[0][j - 1]
        for i in range(2, m + 1):
            dp[i][1] = dp[i-1][1] + grid[i - 1][0]
        for i in range(2, m + 1):
            for j in range(2, n + 1):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1]
        return dp[m][n]
