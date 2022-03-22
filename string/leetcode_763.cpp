// 6.6MB, 11ms
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> answer;
        vector<int> alphabets(26, 0);
        
        for (int i = 0; i < s.length(); i++) alphabets[s[i] - 'a'] = i;
        
        int maxIdx = -1;
        int prev = 0;
        for (int i = 0; i < s.length(); i++) {
            
            maxIdx = max(maxIdx, alphabets[s[i] - 'a']);
            
            if (maxIdx == i) {
                if (answer.size() == 0) answer.push_back(i+1);
                else answer.push_back(i - prev + 1);
                
                prev += answer.back();
            }
        }
        
        return answer;
    }
};
