# Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
#
# Example:
#
#
# Input: 
#
# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0
#
# Output: 4
#


class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        m = len(matrix)
        if m == 0:
            return 0
        n = len(matrix[0])
        dp = [0 for _ in range(n)]
        maxlen = 0
        for i in range(m):
            prev = dp[0]
            dp[0] = 1 if matrix[i][0] == '1' else 0
            maxlen = max(maxlen, dp[0])
            for j in range(1, n):
                top = dp[j]
                if matrix[i][j] == '1':
                    dp[j] = 1 + min(dp[j - 1], min(prev, top))
                    maxlen = max(maxlen, dp[j])
                else:
                    dp[j] = 0
                prev = top
        return maxlen ** 2
