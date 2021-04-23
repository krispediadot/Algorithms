// 0ms, 6.1MB, 00:08:35
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        
        vector<int> answer(n + 1, 0);
        
        answer[n-1] = 1;
        answer[n-2] = 2;
        
        for (int idx = n-3; idx >= 0; idx--) {
            answer[idx] = answer[idx + 1] + answer[idx + 2];
        }
        
        return answer[0];
    }
};
