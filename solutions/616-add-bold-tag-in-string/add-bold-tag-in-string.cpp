// Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them. 
//
// Example 1:
//
// Input: 
// s = "abcxyz123"
// dict = ["abc","123"]
// Output:
// "<b>abc</b>xyz<b>123</b>"
//
//
//
// Example 2:
//
// Input: 
// s = "aaabbcc"
// dict = ["aaa","aab","bc"]
// Output:
// "<b>aaabbc</b>c"
//
//
//
// Note:
//
// The given dict won't contain duplicates, and its length won't exceed 100.
// All the strings in input have length in range [1, 1000]. 
//
//


class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<pair<int, int>> range;
        for (auto w: dict) {
            int n = w.size();
            for (int i = 0; (i = s.find(w, i)) != string::npos; i++) {
                range.emplace_back(i, i + n);
            }
        }
        if (range.empty()) return s;
        vector<pair<int, int>> merged;
        sort(range.begin(), range.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.first < b.first || (a.first == b.first && a.second < b.second);});
        merged.emplace_back(range[0]);
        for (int i = 1; i < range.size(); i++) {
            if (merged.back().second < range[i].first) {
                merged.emplace_back(range[i]);
            } else {
                merged.back().second = max(merged.back().second, range[i].second);
            }
        }
        for (auto it = merged.rbegin(); it != merged.rend(); it++) {
            s.insert(it->second, "</b>");
            s.insert(it->first, "<b>");
        }
        return s;
    }
};
