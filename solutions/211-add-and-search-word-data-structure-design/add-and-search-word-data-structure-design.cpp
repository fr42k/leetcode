// Design a data structure that supports the following two operations:
//
//
// void addWord(word)
// bool search(word)
//
//
// search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
//
// Example:
//
//
// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true
//
//
// Note:
// You may assume that all words are consist of lowercase letters a-z.
//


class Trie {
public:
    vector<Trie*> next;
    bool w;
    Trie(): w(false) {
        next.resize(26);
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto p = root;
        for (char c: word) {
            if (!p->next[c - 'a']) {
                p->next[c - 'a'] = new Trie();
            }
            p = p->next[c - 'a'];
        }
        p->w = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        auto p = root;
        return query(word, p);
    }
    bool query(string word, Trie* p) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (p->next[j] && query(word.substr(i + 1), p->next[j])) {
                        return true;
                    }
                }
                return false;
            } else {
                if (p->next[word[i] - 'a']) {
                    p = p->next[word[i] - 'a'];
                } else {
                    return false;
                }
            }
        }
        return p && p->w;
    }
    Trie* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
