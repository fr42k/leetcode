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
                    for (int d = 1; d <= 3; d++) {
                        if (a + b + c + d == s.size()) {
                            auto s1 = s.substr(0, a);
                            auto s2 = s.substr(a, b);
                            auto s3 = s.substr(a + b, c);
                            auto s4 = s.substr(a + b + c);
                            int v1 = stoi(s1);
                            int v2 = stoi(s2);
                            int v3 = stoi(s3);
                            int v4 = stoi(s4);
                            if (v1 <= 255 && v2 <= 255 && v3 <= 255 && v4 <= 255) {
                                v1 = to_string(v1).size();
                                v2 = to_string(v2).size();
                                v3 = to_string(v3).size();
                                v4 = to_string(v4).size();
                                if (v1 + v2 + v3 + v4 == s.size()) {
                                    ans.emplace_back(s1 + "." + s2 + "." + s3 + "." + s4);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
