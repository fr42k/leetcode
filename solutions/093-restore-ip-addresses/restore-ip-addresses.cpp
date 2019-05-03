// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
// Example:
//
//
// Input: "25525511135"
// Output: ["255.255.11.135", "255.255.111.35"]
//
//


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    if (a + b + c >= s.size()) continue;
                    auto s1 = s.substr(0, a);
                    auto s2 = s.substr(a, b);
                    auto s3 = s.substr(a + b, c);
                    auto s4 = s.substr(a + b + c);
                    if (valid(s1) && valid(s2) && valid(s3) && valid(s4)) {
                        ans.emplace_back(s1 + "." + s2 + "." + s3 + "." + s4);
                    }
                }
            }
        }
        return ans;
    }
    bool valid(string s) {
        if (s.size() > 3 || (stoi(s) > 255) || (s.size() > 1 && s[0] == '0')) return false;
        return true;
    }
};
