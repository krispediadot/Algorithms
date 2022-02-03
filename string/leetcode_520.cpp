// 6.1MB, 4ms
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool upper = (word[1] >= 'A' && word[1] <= 'Z') ? true : false;
        if (upper == true && (word[0] >= 'a' && word[0] <= 'z')) return false;
        
        for (int i = 2; i < word.length(); i++) {
            auto& c = word[i];
            if (upper == true && c >= 'a' && c <= 'z') return false;
            if (upper == false && c >= 'A' && c <= 'Z') return false;
        }
        return true;
    }
};
