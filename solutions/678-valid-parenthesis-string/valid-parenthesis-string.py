#
# Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
#
# Any left parenthesis '(' must have a corresponding right parenthesis ')'.
# Any right parenthesis ')' must have a corresponding left parenthesis '('.
# Left parenthesis '(' must go before the corresponding right parenthesis ')'.
# '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
# An empty string is also valid.
#
#
#
# Example 1:
#
# Input: "()"
# Output: True
#
#
#
# Example 2:
#
# Input: "(*)"
# Output: True
#
#
#
# Example 3:
#
# Input: "(*))"
# Output: True
#
#
#
# Note:
#
# The string size will be in the range [1, 100].
#
#


class Solution:
    def checkValidString(self, s: str) -> bool:
        left_pos = 0
        right_pos = 0
        for c in s:
            if c == '(':
                left_pos += 1
                right_pos += 1
            if c == ')':
                left_pos -= 1
                right_pos -=1
            if c =='*':
                left_pos += 1
                right_pos -= 1
            if left_pos < 0:
                return False
            right_pos = max(0, right_pos)
        return right_pos == 0
                
