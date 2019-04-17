// A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example:
//
//
// Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
// Output: [1,1,2,3]
//
//
// Explanation:
//
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
//
//
// 0 0 0
// 0 0 0
// 0 0 0
//
//
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//
//
// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
//
//
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//
//
// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
//
//
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//
//
// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
//
//
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//
//
// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
//
//
// Follow up:
//
// Can you do it in time complexity O(k log mn), where k is the length of the positions?
//


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> ans;
        vector<int> dir{0, 1, 0, -1, 0};
        vector<int> uf(m * n, -1);
        int cnt = 0;
        for (auto p: positions) {
            int x = p.first, y = p.second;
            int idx = x * n + y;
            uf[idx] = idx;
            cnt++;
            for (int k = 0; k < 4; k++) {
                int n_x = x + dir[k], n_y = y + dir[k + 1];
                int n_idx = n_x * n + n_y;
                if (valid(n_x, n_y, m, n) && uf[n_idx] != -1) {
                    int pa = ufind(uf, idx), pb = ufind(uf, n_idx);
                    if (pa != pb) {
                        cnt--;
                        uf[pa] = min(pa, pb);
                        uf[pb] = uf[pa];
                    }
                }
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
    inline bool valid(int x, int y, int m, int n) {
        return (0 <= x && x < m && 0 <= y && y < n);
    }
    int ufind(vector<int>& uf, int k) {
        if (k != uf[k]) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
