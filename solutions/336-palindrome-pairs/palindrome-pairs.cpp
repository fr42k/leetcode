// Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
//
// Example 1:
//
//
//
// Input: ["abcd","dcba","lls","s","sssll"]
// Output: [[0,1],[1,0],[3,2],[2,4]] 
// Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
//
//
//
// Example 2:
//
//
// Input: ["bat","tab","cat"]
// Output: [[0,1],[1,0]] 
// Explanation: The palindromes are ["battab","tabbat"]
//
//
//
//


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string s1(words[i].substr(0, j));
                string s2(words[i].substr(j));
                if (ispal(s1)) {
                    string r2(s2.rbegin(), s2.rend());
                    if (mp.count(r2) && mp[r2] != i) {
                        ans.emplace_back(vector<int>{mp[r2], i});
                    }
                }
                if (ispal(s2) && !s2.empty()) {
                    string r1(s1.rbegin(), s1.rend());
                    if (mp.count(r1) && mp[r1] != i) {
                        ans.emplace_back(vector<int>{i, mp[r1]});
                    }
                }
            }
        }
        return ans;
    }
    bool ispal(string& s) {
        for (int l = 0, h = s.size() - 1; l < h; l++, h--) {
            if (s[l] != s[h]) return false;
        }
        return true;
    }
};
