// On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
//
// Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
//
// What is the largest possible number of moves we can make?
//
//  
//
//
// Example 1:
//
//
// Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
// Output: 5
//
//
//
// Example 2:
//
//
// Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
// Output: 3
//
//
//
// Example 3:
//
//
// Input: stones = [[0,0]]
// Output: 0
//
//
//  
//
// Note:
//
//
// 	1 <= stones.length <= 1000
// 	0 <= stones[i][j] < 10000
//
//
//
//
//


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int num_components = 0;
        unordered_map<int, int> uf;
        function<int (int)> root = [&](int k){
            if (!uf.count(k)) {
                num_components += 1;
                uf[k] = k;
            }
            if (uf[k] != k) {
                uf[k] = root(uf[k]);
            }
            return uf[k];
        };
        function<void (int, int)> connect = [&](int x, int y) {
            auto p = root(x), q = root(y);
            if (p == q) {
                return;
            } else {
                num_components -= 1;
                uf[p] = q;
            }
        };
        for (auto s: stones) {
            connect(s[0], ~s[1]);
        }
        return n - num_components;
    }
};
