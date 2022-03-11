// 9.2MB, 4ms
class Solution {
    unordered_map<string, bool> m; //{string, bool}
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (m.find(s) != m.end()) return m[s];
        
        bool answer = false;
        
        for (auto w : wordDict) {
            int len = w.length();

            if (w == s.substr(0, len)) {
                if (len == s.length()) answer = true;
                else answer |= wordBreak(s.substr(len), wordDict);
            }
            
            if (answer) break;
        }
        
        m.insert({s, answer});
        return answer;
    }
};

// 14.6MB, 34ms
class Solution {
    unordered_map<string, bool> m;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (m.find(s) != m.end()) return m[s]; 
            
        if (s.length() == 0) return true;
        
        bool possible = false;
        
        for (int len = s.length(); len > 0; len--) {
            if (find(wordDict.begin(), wordDict.end(), s.substr(0, len)) != wordDict.end()) {
                possible = wordBreak(s.substr(len), wordDict);
                if (possible) break;
            }   
        }
        
        m[s] = possible;
        return possible;
    }
};
