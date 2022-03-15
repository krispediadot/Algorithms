// 7.5MB, 11ms
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long> dp(amount+1);
        dp[0] = 1;
        
        for (int c : coins) {
            for (int i = c; i < amount+1; i++) {
                dp[i] += (dp[i-c]);
            }
        }
        
        return dp[amount];
    }
};
