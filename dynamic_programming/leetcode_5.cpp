class Solution {
public:
    string longestPalindrome(string s) {
        int answer_start = 0, answer_end = 0;
        for (int i = 0; i < s.length(); i++) {
            int start = i, end = i;
        
            while (end + 1 < s.length() && s[end + 1] == s[start]) {
                end++;
            }

            i = end;
          
            while (start - 1 >= 0 && end + 1 < s.length() &&
                s[start - 1] == s[end + 1]) {
                end++;
                start--;
            }

            if (end - start + 1 > answer_end - answer_start + 1) {
                answer_start = start;
                answer_end = end;
            }
        }
        return s.substr(answer_start, answer_end - answer_start + 1);
    }
};
