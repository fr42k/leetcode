// There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
//
// Example 1:
//
//
// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
//
// Output: "wertf"
//
//
// Example 2:
//
//
// Input:
// [
//   "z",
//   "x"
// ]
//
// Output: "zx"
//
//
// Example 3:
//
//
// Input:
// [
//   "z",
//   "x",
//   "z"
// ] 
//
// Output: "" 
//
// Explanation: The order is invalid, so return "".
//
//
// Note:
//
//
// 	You may assume all letters are in lowercase.
// 	If the order is invalid, return an empty string.
// 	There may be multiple valid order of letters, return any one of them is fine.
//
//


class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> pre, suc;
        unordered_set<char> letters;
        string last;
        for (auto& w: words) {
            letters.insert(w.begin(), w.end());
            for (int i = 0; i < min(last.size(), w.size()); i++) {
                if (last[i] != w[i]) {
                    suc[last[i]].emplace(w[i]);
                    pre[w[i]].emplace(last[i]);
                    break;
                }
            }
            last = w;
        }
        set<char> nopre(letters.begin(), letters.end());
        for (auto it: pre) {
            nopre.erase(it.first);
        }
        string ans;
        while (nopre.size()) {
            int n = nopre.size();
            for (int i = 0; i < n; i++) {
                auto c = *nopre.begin();
                nopre.erase(c);
                ans += c;
                for (char next: suc[c]) {
                    if (!pre.count(next)) continue;
                    pre[next].erase(c);
                    if (pre[next].empty()) {
                        pre.erase(next);
                        nopre.emplace(next);
                    }
                }
            }
        }
        return ans.size() == letters.size()? ans: "";
    }
};
