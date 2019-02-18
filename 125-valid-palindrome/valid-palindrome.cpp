// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (!n) return true;
        int i = 0, j = n - 1;
        while (i < j) {
            while (i < j &&!isalnum(s[i])) i++;
            while (i < j && !isalnum(s[j])) j--;
            if (toupper(s[i]) != toupper(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};
