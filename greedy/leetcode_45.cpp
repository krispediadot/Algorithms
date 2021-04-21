// 4ms, 8.3MB, 00:55:00
class Solution1 {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) return 1;

        vector<int> cnts(nums.size(), 100000);
        for (int idx = nums.size() - 2; idx >= 0; idx--) {
            if (idx + nums[idx] >= nums.size() - 1) cnts[idx] = 1;
            else {
                for (int jump = 1; jump <= nums[idx]; jump++) {
                    cnts[idx] = min(cnts[idx], cnts[idx + jump] + 1);
                }
            }
        }
        
        return cnts[0];
    }
};

// 0ms, 8.3MB, 01:10:00
class Solution2 {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        vector<int> cnts(nums.size(), 100000);
        cnts[0] = 0;

        for (int idx = 0; idx < nums.size() - 1; idx++) {
            if (idx + nums[idx] >= nums.size() - 1) return cnts[idx] + 1;

            for (int i = idx + 1; i <= idx + nums[idx]; i++) {
                cnts[i] = min(cnts[i], cnts[idx] + 1);
            }
        }

        return -1;
    }
};
