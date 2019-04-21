// Given two strings s and t , write a function to determine if t is an anagram of s.
//
// Example 1:
//
//
// Input: s = "anagram", t = "nagaram"
// Output: true
//
//
// Example 2:
//
//
// Input: s = "rat", t = "car"
// Output: false
//
//
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?
//


class Solution {
public:
    bool isAnagram(string s, string t) {
        int sum = 0;
        unordered_set<char> s1, s2;
        int size = s.size();
        if (size - t.size()) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            sum += static_cast<int>(s[i]);
            s1.emplace(s[i]);
            sum -= static_cast<int>(t[i]);
            s2.emplace(t[i]);
        }
        return sum? false: (s1 == s2? true: false);
    }
};
