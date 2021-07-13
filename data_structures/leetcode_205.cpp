// 20ms, 7.2MB
class Solution1 {
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

// 12ms, 7.1MB
class Solution2 {
public:
    string pattern(string s) {
        unordered_map<char, char> ms;

        char cur = 'a';

        for (auto& c : s) {
            if (!ms[c]) ms[c] = cur++;
            c = ms[c];
        }

        return s;
    }
    bool isIsomorphic(string s, string t) {
        return pattern(s) == pattern(t);
    }
};
