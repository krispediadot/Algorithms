// 4ms, 13.3MB, 00:10:00
class Solution1 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        vector<int> answer(nums.size(), 0);
        
        answer[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            answer[i] = (answer[i - 1] + nums[i] > nums[i]) ? answer[i - 1] + nums[i] : nums[i];
            
            sum = max(sum, answer[i]);
        }
        return sum;
    }
};

// 4ms, 13.1MB, 00:12:00
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = (nums[i - 1] + nums[i] > nums[i]) ? nums[i - 1] + nums[i] : nums[i];
            
            sum = max(sum, nums[i]);
        }
        return sum;
    }
};
