// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stack.emplace_back(i);
            } else {
                if (!stack.empty() && s[stack.back()] == '(') {
                    stack.pop_back();
                    int last_pos = -1;
                    if (!stack.empty()) last_pos = stack.back();
                    int curlen = i - last_pos;
                    ans = max(ans, curlen);
                } else {
                    stack.emplace_back(i);
                }
            }
        }
        return ans;
    }
};
