// Given a string, sort it in decreasing order based on the frequency of characters.
//
// Example 1:
//
// Input:
// "tree"
//
// Output:
// "eert"
//
// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
//
//
//
// Example 2:
//
// Input:
// "cccaaa"
//
// Output:
// "cccaaa"
//
// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
//
//
//
// Example 3:
//
// Input:
// "Aabb"
//
// Output:
// "bbAa"
//
// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//
//


class Solution {
public:
    string frequencySort(string s) {
        map<int, set<char>> res;
        res[1] = {};
        unordered_map<char, int> freq;
        unordered_set<char> cset;
        string ans("");
        for (char c: s) {
            if (freq.count(c)) {
                res[++freq[c]].emplace(c);
            } else {
                freq.emplace(c, 1);
                res[1].emplace(c);
            }
        }
        for (auto iter = res.rbegin(); iter != res.rend(); iter++) {
            auto tset = iter->second;
            for (char c: tset) {
                if (!cset.count(c)) {
                    for (int i = 0; i < iter->first; i++) {
                        ans.push_back(c);
                    }
                    cset.emplace(c);
                }
            }
        }
        return move(ans);
    }
};
