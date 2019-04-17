// Let's say a positive integer is a superpalindrome if it is a palindrome, and it is also the square of a palindrome.
//
// Now, given two positive integers L and R (represented as strings), return the number of superpalindromes in the inclusive range [L, R].
//
//  
//
// Example 1:
//
//
// Input: L = "4", R = "1000"
// Output: 4
// Explanation: 4, 9, 121, and 484 are superpalindromes.
// Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
//
//  
//
// Note:
//
//
// 	1 <= len(L) <= 18
// 	1 <= len(R) <= 18
// 	L and R are strings representing integers in the range [1, 10^18).
// 	int(L) <= int(R)
//
//
//
//  
//
//


class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        long l = stol(L), r = stol(R);
        int limit = sqrt(l);
        int ans = (l <= 1 && 1 <= r) + (l <= 4 && 4 <= r) + (l <= 9 && 9 <= r);
        for (long i = 1; i <= 34000; i++) {
            long seed = gen_pali(i);
            if (seed * seed > r) break;
            if (valid_pali(seed * seed, l, r)) {
                ans++;
            }
            for (int m = 0; m < 10; m++) {
                long candi = gen_pali(i, m);
                if (valid_pali(candi * candi, l, r)) {
                    ans++;
                }
            }
        }
        return ans;
    }
    long gen_pali(long v, int mid = -1) {
        long ans = v;
        if (mid != -1) {
            ans = ans * 10 + mid;
        }
        for (; v != 0; v /= 10) {
            ans = ans * 10 + v % 10;
        }
        return ans;
    }
    bool valid_pali(long v, long l, long r) {
        if (v < l || r < v) return false;
        long t = 0;
        long tmp = v;
        for (; tmp != 0; tmp /= 10) {
            t = t * 10 + tmp % 10;
        }
        return t == v;
    }
};
