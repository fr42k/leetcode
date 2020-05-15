# Implement a trie with insert, search, and startsWith methods.
#
# Example:
#
#
# Trie trie = new Trie();
#
# trie.insert("apple");
# trie.search("apple");   // returns true
# trie.search("app");     // returns false
# trie.startsWith("app"); // returns true
# trie.insert("app");   
# trie.search("app");     // returns true
#
#
# Note:
#
#
# 	You may assume that all inputs are consist of lowercase letters a-z.
# 	All inputs are guaranteed to be non-empty strings.
#
#


class Node:
        def __init__(self):
            self.w = False
            self.next = {}
class Trie:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.n = Node()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        p = self.n
        for c in word:
            if c not in p.next:
                p.next[c] = Node()
            p = p.next[c]
        p.w = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        p = self.n
        for c in word:
            if c not in p.next:
                return False
            p = p.next[c]
        return p.w

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        p = self.n
        for c in prefix:
            if c not in p.next:
                return False
            p = p.next[c]
        return p.w or len(p.next) > 0


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
