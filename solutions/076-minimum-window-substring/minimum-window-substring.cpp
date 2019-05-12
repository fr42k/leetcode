// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
//


class Solution {
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX, start = -1;
        vector<int> cnt(256);
        for (char c: t) {
            cnt[c]++;
        }
        for (int slow = 0, fast = 0, diff = 0; fast < s.size(); fast++) {
            if (cnt[s[fast]]-- > 0) {
                diff++;
            }
            while (diff >= t.size()) {
                int len = fast - slow + 1;
                if (len < minlen) {
                    minlen = len;
                    start = slow;
                }
                if (++cnt[s[slow++]] > 0) {
                    diff--;
                }
            }
        }
        return start == -1? "": s.substr(start, minlen);
    }
};
