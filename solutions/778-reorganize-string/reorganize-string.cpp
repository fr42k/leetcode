// Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.
//
// If possible, output any possible result.  If not possible, return the empty string.
//
// Example 1:
//
//
// Input: S = "aab"
// Output: "aba"
//
//
// Example 2:
//
//
// Input: S = "aaab"
// Output: ""
//
//
// Note:
//
//
// 	S will consist of lowercase letters and have length in range [1, 500].
//
//
//  
//


class Solution {
public:
    string reorganizeString(string s) {
        vector<int> cnt(26, 0);
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            if (++cnt[s[i] - 'a'] > cnt[cur]) {
                cur = s[i] - 'a';
            }
        }
        string ans;
        ans += cur + 'a';
        cnt[cur]--;
        for (int i = 1; i < s.size(); i++) {
            int tmp = -1;
            for (int j = 0; j < 26; j++) {
                if ((cnt[j]) && ans[i - 1] != j + 'a' && (tmp == -1 || (cnt[j] > cnt[tmp]))) {
                    tmp = j;
                }
            }
            if (tmp == -1) return "";
            ans += tmp + 'a';
            cnt[tmp]--;
        }
        return ans;
    }
};
