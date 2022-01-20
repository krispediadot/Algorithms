// 6.4MB, 6ms
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_set<string> words;
        unordered_map<char, string> dict;
        stringstream ss(s);
        
        int idx = 0;
        string word; 
        
        while (ss >> word) {
            if (dict.find(pattern[idx]) == dict.end()) {
                if (words.find(word) != words.end()) return false;
                words.insert(word);   
                dict[pattern[idx]] = word;
            }
            else {
                if (dict[pattern[idx]] != word) return false;
            }
            idx++;
        }
        
        if (idx < pattern.length()) return false;
        return true;
    }
};
