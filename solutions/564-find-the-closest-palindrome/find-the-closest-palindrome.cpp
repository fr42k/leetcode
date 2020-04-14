// Given an integer n, find the closest integer (not including itself), which is a palindrome. 
//
// The 'closest' is defined as absolute difference minimized between two integers.
//
// Example 1:
//
// Input: "123"
// Output: "121"
//
//
//
// Note:
//
// The input n is a positive integer represented by string, whose length will not exceed 18.
// If there is a tie, return the smaller one as answer.
//
//


class Solution {
public:
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;
        candidates.emplace(long(pow(10, l - 1)) - 1);
        candidates.emplace(long(pow(10, l)) + 1);
        long prenum = stol(n.substr(0, (l + 1) / 2));
        for (int i = -1; i <= 1; i++) {
            string pre = to_string(prenum + i);
            string candi = pre + string(pre.rbegin() + (l & 1), pre.rend());
            candidates.emplace(stol(candi));
        }
        long num = stol(n);
        candidates.erase(num);
        long diff = LONG_MAX, candi = 0;
        for (auto& c: candidates) {
            if (labs(c - num) < diff) {
                diff = labs(c - num);
                candi = c;
            }
        }
        return to_string(candi);
    }
};
