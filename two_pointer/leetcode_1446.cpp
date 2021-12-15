// 6.6 MB, 7ms

class Solution {
public:
    int maxPower(string s) {
        int answer = 0;
        int sIdx=0, eIdx=0;
        
        while (eIdx < s.length()) {
            if (s[sIdx] == s[eIdx]) {
                eIdx++;
                answer = max(answer, eIdx - sIdx);
            }
            else {
                sIdx = eIdx;
            }
        }
        
        return answer;
    }
};
