// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans(digits);
        ans.back() += 1;
        int c = 0;
        for (int i = ans.size() - 1; i >= 0; i--) {
            int sum = c;
            sum += ans[i];
            c = sum / 10;
            ans[i] = sum % 10;
        }
        if (c) {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};
