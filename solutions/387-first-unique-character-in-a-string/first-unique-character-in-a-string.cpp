//
// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
//
// Examples:
//
// s = "leetcode"
// return 0.
//
// s = "loveleetcode",
// return 2.
//
//
//
//
// Note: You may assume the string contain only lowercase letters.
//


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> f{};
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            f[s[i]]++;
        }
        for (int i = 0; i < sz; i++) {
            if (f[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
