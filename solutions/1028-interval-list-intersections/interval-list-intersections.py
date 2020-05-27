# Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
#
# Return the intersection of these two interval lists.
#
# (Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
#
#
#  
#
# Example 1:
#
#
#
#
# Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
# Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
#
#
#  
#
# Note:
#
#
# 	0 <= A.length < 1000
# 	0 <= B.length < 1000
# 	0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9
#
#
#


class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        i, j = 0, 0
        m, n = len(A), len(B)
        ans = []
        while i < m and j < n:
            x = A[i]
            y = B[j]
            u = max(x[0], y[0])
            v = min(x[1], y[1])
            if u <= v:
                ans.append([u, v])
            if x[1] < y[1]:
                i += 1
            else:
                j += 1
        return ans
            
            
