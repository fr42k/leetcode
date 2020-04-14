//
// Given a non-empty string s, you may delete at most one character.  Judge whether you can make it a palindrome.
//
//
// Example 1:
//
// Input: "aba"
// Output: True
//
//
//
// Example 2:
//
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
//
//
//
// Note:
//
// The string will only contain lowercase characters a-z.
// The maximum length of the string is 50000.
//
//


class Solution {
public:
    bool validPalindrome(string s) {
        for (int l = 0, h = s.size() - 1; l < h; l++, h--) {
            if (s[l] != s[h]) {
                return ispal(s, l, h - 1) || ispal(s, l + 1, h);
            }
        }
        return true;
    }
    bool ispal(string s, int l, int h) {
        while (l < h) {
            if (s[l++] != s[h--]) {
                return false;
            }
        }
        return true;
    }
};
