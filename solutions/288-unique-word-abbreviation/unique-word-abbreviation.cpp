// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
//
//
// a) it                      --> it    (no abbreviation)
//
//      1
//      ↓
// b) d|o|g                   --> d1g
//
//               1    1  1
//      1---5----0----5--8
//      ↓   ↓    ↓    ↓  ↓    
// c) i|nternationalizatio|n  --> i18n
//
//               1
//      1---5----0
//      ↓   ↓    ↓
// d) l|ocalizatio|n          --> l10n
//
//
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
// Example:
//
//
// Given dictionary = [ "deer", "door", "cake", "card" ]
//
// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true
//
//


class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (auto word: dictionary) {
            if (raw.count(word)) {
                continue;
            }
            raw.emplace(word);
            int n = word.size();
            if (n > 2) word.replace(1, n - 2, to_string(n - 2));
            abbr_cnt[word]++;
        }
    }
    
    bool isUnique(string word) {
        string abbr(word);
        int n = abbr.size();
        if (n > 2) abbr.replace(1, n - 2, to_string(n - 2));
        if (raw.count(word)) {
            return abbr_cnt[abbr] == 1;
        } else {
            return abbr_cnt[abbr] == 0;
        }
    }
    unordered_set<string> raw;
    unordered_map<string, int> abbr_cnt;
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
