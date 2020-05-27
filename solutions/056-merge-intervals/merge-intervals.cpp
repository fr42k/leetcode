// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return {};
        auto cmp = [](Interval& a, Interval& b) {
            return a.start < b.start;    
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ans;
        ans.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int s = intervals[i].start, e = intervals[i].end;
            if (ans.back().end < s) {
                ans.emplace_back(intervals[i]);
            } else {
                ans.back().end = max(ans.back().end, e);
            }
        }
        return ans;
    }
};
