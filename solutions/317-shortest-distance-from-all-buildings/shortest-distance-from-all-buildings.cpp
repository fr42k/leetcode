// You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
//
//
// 	Each 0 marks an empty land which you can pass by freely.
// 	Each 1 marks a building which you cannot pass through.
// 	Each 2 marks an obstacle which you cannot pass through.
//
//
// Example:
//
//
// Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
//
// 1 - 0 - 2 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
//
// Output: 7 
//
// Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
//              the point (1,2) is an ideal empty land to build a house, as the total 
//              travel distance of 3+3+1=7 is minimal. So return 7.
//
// Note:
// There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
//


class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (!m) return -1;
        int n = grid[0].size();
        if (!n) return -1;
        vector<vector<int>> ngrid(grid);
        vector<vector<int>> total(m, vector<int>(n, 0));
        vector<int> dir{0, 1, 0, -1, 0};
        int mind = INT_MAX, canReach = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    vector<vector<int>> dist(m, vector<int>(n, 0));
                    q.emplace(i, j);
                    while (!q.empty()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int next_x = x + dir[k], next_y = y + dir[k + 1];
                            if (valid(next_x, next_y, m, n) && ngrid[next_x][next_y] == canReach) {
                                ngrid[next_x][next_y]--;
                                dist[next_x][next_y] = dist[x][y] + 1;
                                total[next_x][next_y] += dist[next_x][next_y];
                                q.emplace(next_x, next_y);
                            }
                        }
                    }
                    canReach--;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (ngrid[i][j] == canReach && total[i][j] < mind) {
                    mind = total[i][j];
                }
            }
        }
        return mind == INT_MAX? -1: mind;
    }
    inline bool valid(int x, int y, int m, int n) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
};
