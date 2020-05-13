# In a given grid, each cell can have one of three values:
#
#
# 	the value 0 representing an empty cell;
# 	the value 1 representing a fresh orange;
# 	the value 2 representing a rotten orange.
#
#
# Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
#
# Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
#
#  
#
#
# Example 1:
#
#
#
#
# Input: [[2,1,1],[1,1,0],[0,1,1]]
# Output: 4
#
#
#
# Example 2:
#
#
# Input: [[2,1,1],[0,1,1],[1,0,1]]
# Output: -1
# Explanation:  The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
#
#
#
# Example 3:
#
#
# Input: [[0,2]]
# Output: 0
# Explanation:  Since there are already no fresh oranges at minute 0, the answer is just 0.
#
#
#  
#
# Note:
#
#
# 	1 <= grid.length <= 10
# 	1 <= grid[0].length <= 10
# 	grid[i][j] is only 0, 1, or 2.
#
#
#
#
#


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        m = len(grid)
        if m == 0:
            return -1
        n = len(grid[0])
        if n == 0:
            return -1
        fresh = set()
        q = []
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    fresh.add((i, j))
                elif grid[i][j] == 2:
                    q.append((i, j))
        t = 0
        d = [0, -1, 0, 1, 0]
        while len(fresh) != 0 and len(q) != 0:
            size = len(q)
            for i in range(size):
                x, y = q[i]
                for k in range(4):
                    u, v = x + d[k], y + d[k + 1]
                    if 0 <= u < m and 0 <= v < n and grid[u][v] == 1:
                        grid[u][v] = 2
                        q.append((u, v))
                        fresh.remove((u, v))
            q = q[size:]
            t += 1
        return t if len(fresh) == 0 else -1
                
