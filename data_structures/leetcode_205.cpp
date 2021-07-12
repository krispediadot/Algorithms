class Solution {
public:
    string normalize_pattern(string word) {
        unordered_map<char, char> m;
        char curr = 'a';
        
        for (auto letter : word)
            if (!m[letter]) m[letter] = curr++;
        
        for (int i = 0; i < word.size(); i++) word[i] = m[word[i]];
        
        return word;
        
    }
    
    bool isIsomorphic(string s, string t) {
        return normalize_pattern(s) == normalize_pattern(t);
    }
};
