// 4ms, 9.9MB, 00:02:00
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        return nums[nums.size() - k];
        
    }
};
