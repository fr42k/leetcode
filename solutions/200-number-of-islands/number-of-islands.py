# Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
#
# Example 1:
#
#
# Input:
# 11110
# 11010
# 11000
# 00000
#
# Output: 1
#
#
# Example 2:
#
#
# Input:
# 11000
# 11000
# 00100
# 00011
#
# Output: 3
#


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        dirs = [0, -1, 0, 1, 0]
        def dfs(grid, x, y) -> None:
            if x < 0 or y < 0 or x >= len(grid) or y >= len(grid[0]) or grid[x][y] != '1':
                return
            grid[x][y] = '0'
            for k in range(4):
                dfs(grid, x + dirs[k], y + dirs[k + 1])
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    ans += 1
                    dfs(grid, i, j)
        return ans
