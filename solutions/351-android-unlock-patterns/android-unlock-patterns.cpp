// Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.
//
//  
//
// Rules for a valid pattern:
//
//
// 	Each pattern must connect at least m keys and at most n keys.
// 	All the keys must be distinct.
// 	If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
// 	The order of keys used matters.
//
//
//  
//
//
//
//
//  
//
// Explanation:
//
//
// | 1 | 2 | 3 |
// | 4 | 5 | 6 |
// | 7 | 8 | 9 |
//
// Invalid move: 4 - 1 - 3 - 6 
// Line 1 - 3 passes through key 2 which had not been selected in the pattern.
//
// Invalid move: 4 - 1 - 9 - 2
// Line 1 - 9 passes through key 5 which had not been selected in the pattern.
//
// Valid move: 2 - 4 - 1 - 3 - 6
// Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern
//
// Valid move: 6 - 5 - 4 - 1 - 9 - 2
// Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.
//
//  
//
// Example:
//
//
//
// Input: m = 1, n = 1
// Output: 9
//
//
//


class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        int ans = 0;
        vector<int> visited(10, 0);
        for (int i = m; i <= n; i++) {
            ans += dfs(skip, visited, 1, i - 1) * 4;
            ans += dfs(skip, visited, 2, i - 1) * 4;
            ans += dfs(skip, visited, 5, i - 1);
        }
        return ans;
    }
    int dfs(vector<vector<int>>& skip, vector<int>& visited, int key, int remain) {
        if (remain == 0) return 1;
        visited[key] = 1;
        int ans = 0;
        for (int i = 1; i <= 9; i++) {
            if (!visited[i] && (skip[key][i] == 0 || visited[skip[key][i]])) {
                ans += dfs(skip, visited, i, remain - 1);
            }
        }
        visited[key] = 0;
        return ans;
    }
};
