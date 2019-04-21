// Implement the StreamChecker class as follows:
//
//
// 	StreamChecker(words): Constructor, init the data structure with the given words.
// 	query(letter): returns true if and only if for some k >= 1, the last k characters queried (in order from oldest to newest, including this letter just queried) spell one of the words in the given list.
//
//
//  
//
// Example:
//
//
// StreamChecker streamChecker = new StreamChecker(["cd","f","kl"]); // init the dictionary.
// streamChecker.query('a');          // return false
// streamChecker.query('b');          // return false
// streamChecker.query('c');          // return false
// streamChecker.query('d');          // return true, because 'cd' is in the wordlist
// streamChecker.query('e');          // return false
// streamChecker.query('f');          // return true, because 'f' is in the wordlist
// streamChecker.query('g');          // return false
// streamChecker.query('h');          // return false
// streamChecker.query('i');          // return false
// streamChecker.query('j');          // return false
// streamChecker.query('k');          // return false
// streamChecker.query('l');          // return true, because 'kl' is in the wordlist
//
//
//  
//
// Note:
//
//
// 	1 <= words.length <= 2000
// 	1 <= words[i].length <= 2000
// 	Words will only consist of lowercase English letters.
// 	Queries will only consist of lowercase English letters.
// 	The number of queries is at most 40000.
//
//


struct Trie {
    vector<Trie*> next;
    bool w;
    Trie(): w(false) {
        next.resize(26, nullptr);
    }
};
class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for (auto& w: words) {
            auto p = root;
            size = max(size, int(w.size()));
            for (int i = w.size() - 1; i >= 0; --i) {
                char c = w[i];
                if (!p->next[c - 'a']) {
                    p->next[c - 'a'] = new Trie();
                }
                p = p->next[c - 'a'];
            }
            p->w = true;
        }
    }
    
    bool query(char letter) {
        q.insert(q.begin(), letter);
        if (q.size() > size) {
            q.pop_back();
        }
        auto p = root;
        for (char c: q) {
            if (p->w) return true;
            if (p->next[c - 'a']) {
                p = p->next[c - 'a'];
            } else {
                return false;
            }
        }
        return p->w;
    }
    Trie* root;
    int size;
    vector<char> q;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
