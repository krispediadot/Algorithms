// 7 MB, 4ms

class Solution {
public:
    int myAtoi(string s) {
        long result = 0;
        int sign = 1;
        
        int idx = 0;
        while (s[idx] == ' ') idx++;
        if (s[idx] == '+' || s[idx] == '-') {
            if (s[idx] == '-') sign = -1;
            idx++;
        }
        
        while (idx < s.length()) {
            if (s[idx] >= '0' && s[idx] <= '9') {
                result *= 10;
                result += (s[idx] - '0');
                
                if (result*sign > INT_MAX) return INT_MAX;
                if (result*sign < INT_MIN) return INT_MIN;
                
                idx++;
            }
            else break;
        }
        
        return result*sign;
    }
};
