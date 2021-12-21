// 6.4 MB, 0ms
class Solution {
public:
    string decodeString(string s) {
        if (s.length() <= 1) return s;
        
        string answer = "";
        
        for (int idx = 0; idx < s.length(); idx++) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                int times = 0;
                
                while (idx < s.length() && s[idx] != '['){
                    times *= 10;
                    times += (s[idx] - '0');
                    
                    idx++;
                }

                int open = idx;
                int close = idx + 1;
      
                int open_cnt = 1;
                int close_cnt = 0;
                
                while (close < s.length() && open_cnt != close_cnt) {
                    if (s[close] == '[') open_cnt++;
                    if (s[close] == ']') close_cnt++;
                    if (open_cnt == close_cnt) break;
                    close++;
                }
                
                string res = decodeString(s.substr(open + 1, close - open - 1));
                
                while(times--) answer += res;
                
                idx = close;
            }
            else answer += s[idx];
        }
        
        return answer;
    }
};
