// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        if (!n) return false;
        int l = 0, h = m - 1;
        while (l < h) {
            int mid = l + (h - l) / 2 + 1;
            if (matrix[mid][0] <= target) {
                l = mid;
            } else {
                h = mid - 1;
            }
        }
        if (matrix[l][0] > target) return false;
        int x = l;
        l = 0, h = n - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (matrix[x][mid] < target) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return matrix[x][l] == target;
    }
};
