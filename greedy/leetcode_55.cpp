// 8ms, 12.7MB, 01:00:00
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size() - 1;
        
        for (int idx = nums.size() - 1; idx >= 0; idx--) {
            if (idx + nums[idx] >= last) {
                last = idx;
            }
        }
        
        return last == 0;
    }
};
