// 20ms, 10.5MB, 00:30:22
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp(nums.size(), *max_element(nums.begin(), nums.end()));
        int answer = 0;
        
        for (auto target : nums) {
            int dp_idx = 0;
            while (dp[dp_idx] < target) dp_idx++;
            dp[dp_idx] = target;
            
            answer = max(answer, dp_idx);
        }
        
        return answer + 1;
    }
};
