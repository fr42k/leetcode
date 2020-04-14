// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
// Example 1:
//
//
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
//
// Example 2:
//
//
// Input: [[7,10],[2,4]]
// Output: 1
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
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp;
        int rooms = 0;
        int sum = 0;
        for (auto i: intervals) {
            mp[i.start]++;
            mp[i.end]--;
        }
        for (auto p: mp) {
            sum += p.second;
            rooms = max(rooms, sum);
        }
        return rooms;
    }
};
