// 11MB, 11ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int cnt = 0;
        int sub = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && prev == nums[i]) cnt++;
            else cnt = 0;
            
            if (cnt >= 2) sub++;
            else nums[i-sub] = nums[i];
            
            prev = nums[i];
        }
        
        return nums.size() - sub;
    }
};
