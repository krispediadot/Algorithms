// 168ms, 8.9MB
 class Solution {
     vector<int> dp;
public:
    int numSquares(int n) {
        dp.resize(n+1);
        for (int i = 1; i <= n; i++) dp[i] = i;

        for (int target = 2; target * target <= n; target++) {
            int square = target * target;
            dp[square] = 1;

            for (int num = square + 1; num <= n; num++) {
                dp[num] = min(dp[num], dp[num - square] + 1);
            }
        }

        return dp[n];
    }
};
