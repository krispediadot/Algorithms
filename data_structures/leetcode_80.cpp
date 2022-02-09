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

// 10.9MB, 10ms
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 2;
        int sub = 0;
        
        if (nums.size() < 3)
            return nums.size();
        
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[i-2-sub]) nums[cnt++] = nums[i];
            else sub++;
        }
        
        return cnt;
    }
};
