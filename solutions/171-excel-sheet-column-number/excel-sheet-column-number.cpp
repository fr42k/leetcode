// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//
//
//     A -> 1
//     B -> 2
//     C -> 3
//     ...
//     Z -> 26
//     AA -> 27
//     AB -> 28 
//     ...
//
//
// Example 1:
//
//
// Input: "A"
// Output: 1
//
//
// Example 2:
//
//
// Input: "AB"
// Output: 28
//
//
// Example 3:
//
//
// Input: "ZY"
// Output: 701
//


class Solution {
public:
    int titleToNumber(string s) {
        int n = 0;
        int l = s.size();
        for (int i = 0; i < l - 1; i++) {
            n += s[i] - 'A' + 1;
            n *= 26;
        }
        n += s[l - 1] - 'A' + 1;
        return n;
    }
};
