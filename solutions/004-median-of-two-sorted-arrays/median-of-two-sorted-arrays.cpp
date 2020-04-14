// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// You may assume nums1 and nums2 cannot be both empty.
//
// Example 1:
//
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
// Example 2:
//
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5
//
//


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);
        int l = 0, h = m;
        while (l <= h) {
            int i = l + (h - l) / 2;
            int j = (m + n + 1) / 2 - i;
            int left1 = i? nums1[i - 1]: INT_MIN;
            int right1 = i < m? nums1[i]: INT_MAX;
            int left2 = j? nums2[j - 1]: INT_MIN;
            int right2 = j < n? nums2[j]: INT_MAX;
            if (left1 > right2) {
                h = i - 1;
            } else if (right1 < left2) {
                l = i + 1;
            } else {
                int maxl = max(left1, left2);
                int minr = min(right1, right2);
                if ((m + n) & 1) {
                    return maxl;
                } else {
                    return (maxl + minr) / 2.0;
                }
            }
        }
    }
};
