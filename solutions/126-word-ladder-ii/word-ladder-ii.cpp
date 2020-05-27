// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return an empty list if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), visited;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.emplace(vector<string>{beginWord});
        while (!q.empty()) {
            bool found = false;
            for (auto w: visited) {
                dict.erase(w);
            }
            visited.clear();
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto p = q.front();
                q.pop();
                auto word = p.back();
                if (word == endWord) {
                    found = true;
                    ans.emplace_back(p);
                }
                visited.emplace(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = k + 'a';
                        if (word[j] != c && dict.count(word)) {
                            p.emplace_back(word);
                            q.emplace(p);
                            p.pop_back();
                            visited.emplace(word);
                        }
                    }
                    word[j] = c;
                }
            }
            if (found) break;
        }
        return ans;
    }
};
