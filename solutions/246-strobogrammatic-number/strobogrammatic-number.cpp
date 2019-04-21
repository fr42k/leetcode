// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
// Example 1:
//
//
// Input:  "69"
// Output: true
//
//
// Example 2:
//
//
// Input:  "88"
// Output: true
//
// Example 3:
//
//
// Input:  "962"
// Output: false
//


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> mp;
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        for (int l = 0, h = num.size() - 1; l <= h; l++, h--) {
            if (!mp.count(num[l]) || !mp.count(num[h])) return false;
            if (mp[num[l]] != num[h] || mp[num[h]] != num[l]) return false;
        }
        return true;
    }
};
