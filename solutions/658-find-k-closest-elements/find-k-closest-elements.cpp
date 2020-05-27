// Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.
//
//  
// Example 1:
// Input: arr = [1,2,3,4,5], k = 4, x = 3
// Output: [1,2,3,4]
// Example 2:
// Input: arr = [1,2,3,4,5], k = 4, x = -1
// Output: [1,2,3,4]
//
//  
// Constraints:
//
//
// 	1 <= k <= arr.length
// 	1 <= arr.length <= 10^4
// 	Absolute value of elements in the array and x will not exceed 104
//
//


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, h = arr.size() - k;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (abs(arr[m] - x) > abs(arr[m + k] - x)) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};
