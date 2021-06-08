class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int global_max = nums[0];
        int local_max = nums[0];
        int local_min = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            
            int prev_max = local_max;
            int prev_min = local_min;
            
            local_max = max(nums[i], max(prev_max*nums[i], prev_min*nums[i]));
            local_min = min(nums[i], min(prev_max*nums[i], prev_min*nums[i]));
            
            global_max = max(global_max, local_max);
        }
        
        return global_max;
    }
};
