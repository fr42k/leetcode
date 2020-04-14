// Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
//
//  
//
//
//
//
//
//
//
//
//
//
//
// Example 1:
//
//
// Input: "ab-cd"
// Output: "dc-ba"
//
//
//
// Example 2:
//
//
// Input: "a-bC-dEf-ghIj"
// Output: "j-Ih-gfE-dCba"
//
//
//
// Example 3:
//
//
// Input: "Test1ng-Leet=code-Q!"
// Output: "Qedo1ct-eeLg=ntse-T!"
//
//
//  
//
//
// Note:
//
//
// 	S.length <= 100
// 	33 <= S[i].ASCIIcode <= 122 
// 	S doesn't contain \ or "
//
//
//
//
//


class Solution {
public:
    string reverseOnlyLetters(string S) {
        string ans;
        for (int i = 0; i < S.size(); i++) {
            if (isalpha(S[i])) {
                ans.insert(ans.begin(), 1, S[i]);
            }
        }
        for (int i = 0; i < S.size(); i++) {
            if (!isalpha(S[i])) {
                ans.insert(ans.begin() + i, 1, S[i]);
            }
        }
        return ans;
    }
};
