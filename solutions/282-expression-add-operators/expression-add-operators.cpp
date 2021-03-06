// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
// Example 1:
//
//
// Input: num = "123", target = 6
// Output: ["1+2+3", "1*2*3"] 
//
//
// Example 2:
//
//
// Input: num = "232", target = 8
// Output: ["2*3+2", "2+3*2"]
//
// Example 3:
//
//
// Input: num = "105", target = 5
// Output: ["1*0+5","10-5"]
//
// Example 4:
//
//
// Input: num = "00", target = 0
// Output: ["0+0", "0-0", "0*0"]
//
//
// Example 5:
//
//
// Input: num = "3456237490", target = 9191
// Output: []
//
//
//  
// Constraints:
//
//
// 	0 <= num.length <= 10
// 	num only contain digits.
//
//


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        search(num, target, "", 0, 0, 0, ans);
        return ans;
    }
    void search(string num, int target, string path, int idx, long val, long last, vector<string>& ans) {
        if (idx == num.size() && val == target) {
            ans.emplace_back(path);
        }
        for (int i = idx; i < num.size(); i++) {
            if (num[idx] == '0' && i > idx) return;
            string str_n(num.substr(idx, i - idx + 1));
            long v = stol(str_n);
            if (!idx) {
                search(num, target, str_n, i + 1, v, v, ans);
            } else {
                search(num, target, path + "+" + str_n, i + 1, val + v, v, ans);
                search(num, target, path + "-" + str_n, i + 1, val - v, -v, ans);
                search(num, target, path + "*" + str_n, i + 1, val - last + last * v, last * v, ans);
            }
        }
    }
};
