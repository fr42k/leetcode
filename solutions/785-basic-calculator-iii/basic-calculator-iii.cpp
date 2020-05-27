// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces  . The integer division should truncate toward zero.
//
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
//
// Some examples:
//
//
// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
//
//
//  
//
// Note: Do not use the eval built-in library function.
//


class Solution {
public:
    int calculate(string s) {
        auto start = s.find_first_not_of(" ");
        if (start == string::npos) return 0;
        s = s.substr(start);
        if (s[0] == '-') s.insert(s.begin(), '0');
        while (s.find(" ") != string::npos) {
            auto p = s.find(" ");
            s.erase(p, 1);
        }
        while (s.find("(-") != string::npos) {
            auto p = s.find("(-");
            s.insert(s.begin() + p + 1, '0');
        }
        stack<double> nums;
        stack<char> sym;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') continue;
            if (isdigit(s[i])) {
                int len = 0;
                while (i >= 0 && isdigit(s[i])) {
                    len++;
                    i--;
                }
                i++;
                nums.emplace(stol(s.substr(i, len)));
            } else if (s[i] == ')' || s[i] == '*' || s[i] == '/') {
                sym.emplace(s[i]);
            } else if (s[i] == '+' || s[i] == '-') {
                while (!sym.empty() && (sym.top() == '*' || sym.top() == '/')) {
                    calc(nums, sym);
                }
                sym.emplace(s[i]);
            } else if (s[i] == '(') {
                while (!sym.empty() && sym.top() != ')') {
                    calc(nums, sym);
                }
                sym.pop();
            }
        }
        while (!sym.empty()) {
            calc(nums, sym);
        }
        return nums.empty()? 0: nums.top();
    }
    void calc(stack<double>& nums, stack<char>& sym) {
        double left = nums.top();
        nums.pop();
        double right = nums.top();
        nums.pop();
        char s = sym.top();
        sym.pop();
        double n = 0;
        if (s == '+') {
            n = left + right;
        } else if (s == '-') {
            n = left - right;
        } else if (s == '*') {
            n = left * right;
        } else if (s == '/') {
            n = floor(left / right);
        }
        nums.emplace(n);
    }
};
