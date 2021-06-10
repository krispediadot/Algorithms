// 4ms, 6.1MB, 

// binary search tree의 특징은 
// 1. 부모노드의 왼쪽 자식은 부모노드보다 작음
// 2. 부모노드의 오른쪽 자식은 부모노드보다 큼

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        
        dp[0] = 1;
        dp[1] = 1;
        
        for (int target = 2; target <= n; target++) {
            for (int root = 1; root <= target; root++) {
                dp[target] += (dp[root - 1] * dp[target - root]);
            }
        }
        
        return dp[n];
    }
};
