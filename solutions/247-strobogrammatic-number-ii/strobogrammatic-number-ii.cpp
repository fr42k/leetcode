// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Find all strobogrammatic numbers that are of length = n.
//
// Example:
//
//
// Input:  n = 2
// Output: ["11","69","88","96"]
//
//


class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return conduct(n, n);
    }
    vector<string> conduct(int n, int m) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};
        auto prev = conduct(n - 2, m);
        vector<string> ans;
        for (auto w: prev) {
            if (n != m) ans.emplace_back("0" + w + "0");
            ans.emplace_back("1" + w + "1");
            ans.emplace_back("6" + w + "9");
            ans.emplace_back("8" + w + "8");
            ans.emplace_back("9" + w + "6");
        }
        return ans;
    }
};
