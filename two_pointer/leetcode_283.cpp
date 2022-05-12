// 19.3MB, 32ms
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p = 0, idx = 0;
        
        while (p < nums.size()) {
            if (nums[p] != 0)
                nums[idx++] = nums[p];
            p++;
        }
        
        while (idx < nums.size())
            nums[idx++] = 0;
    }
};
