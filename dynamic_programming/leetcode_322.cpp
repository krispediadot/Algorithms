// 18.5MB, 67ms
class Solution {
    vector<long> dp;
public:
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1, INT_MAX);
        dp[0] = 0;
        
        for (auto c : coins) {
            for (int i = c; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
        
        if (dp[amount] < INT_MAX) return int(dp[amount]);
        else return -1;
    }
};
