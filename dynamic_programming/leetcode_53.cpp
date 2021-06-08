class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = nums[0];
        int global_max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            local_max = max(nums[i], local_max + nums[i]);
            if (local_max > global_max)
                global_max = local_max;
        }
        
        return global_max;
    }
};
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int answer = nums[0];

        for (int idx = 1; idx < nums.size(); idx++) {
            nums[idx] = max(nums[idx - 1] + nums[idx], nums[idx]);

            answer = max(answer, nums[idx]);
        }

        return answer;
    }
};
