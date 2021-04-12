#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int idx = 0;
        
        while (idx < s.length() / 2) {
            if (s[idx] != s[s.length() - 1 - idx])
                return false;
            idx++;
        }
        return true;
    }
    int countSubstrings(string s) {
        int cnt = 0;
        int idx = 0;
        
        while (idx < s.length()) {
            for (int len = 1; len <= s.length() - idx; len++) {
                string target = s.substr(idx, len);
                
                if (isPalindrome(target)) cnt++;
            }
            idx++;
        }
        
        return cnt;
    }
};

int main() {
    Solution solution;
    cout << solution.countSubstrings("abc") << endl; // 3
    cout << solution.countSubstrings("aaa") << endl; // 6
}
