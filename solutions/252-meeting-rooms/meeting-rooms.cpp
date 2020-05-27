// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
// Example 1:
//
//
// Input: [[0,30],[5,10],[15,20]]
// Output: false
//
//
// Example 2:
//
//
// Input: [[7,10],[2,4]]
// Output: true
//
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        map<int, int> mp;
        for (auto p: intervals) {
            mp[p.start]++;
            mp[p.end]--;
        }
        int meet = 0, sum = 0;
        for (auto p: mp) {
            sum += p.second;
            meet = max(meet, sum);
        }
        return meet <= 1;
    }
};
