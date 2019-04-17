// A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)
//
// Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.
//
//  
//
// Example 1:
//
//
// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
// Output: [true,false,true,true,false]
// Explanation: 
// "FooBar" can be generated like this "F" + "oo" + "B" + "ar".
// "FootBall" can be generated like this "F" + "oot" + "B" + "all".
// "FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
//
// Example 2:
//
//
// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
// Output: [true,false,true,false,false]
// Explanation: 
// "FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
// "FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
//
//
// Example 3:
//
//
// Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
// Output: [false,true,false,false,false]
// Explanation: 
// "FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
//
//
//  
//
// Note:
//
//
// 	1 <= queries.length <= 100
// 	1 <= queries[i].length <= 100
// 	1 <= pattern.length <= 100
// 	All strings consists only of lower and upper case English letters.
//


class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto& q: queries) {
            int i = 0, j = 0;
            bool miss = false;
            while (i < q.size() and j < pattern.size() and !miss) {
                if (q[i] == pattern[j]) {
                    ++i;
                    ++j;
                } else if (isupper(q[i]) and islower(pattern[j])) {
                    miss = true;
                } else if (islower(q[i])) {
                    ++i;
                } else {
                    miss = true;
                }
            }
            if (miss || (i == q.size() and j < pattern.size())) {
                ans.emplace_back(false);
            } else {
                while (i < q.size()) {
                    if (isupper(q[i])) {
                        miss = true;
                        break;
                    } else {
                        ++i;
                    }
                }
                if (miss) {
                    ans.emplace_back(false);
                } else {
                    ans.emplace_back(true);
                }
            }
        }
        return ans;
    }
};
