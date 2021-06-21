// 96ms, 10.2MB
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int idx = 0; idx < nums.size(); idx++) {
            int a = nums[idx];
            int b = target - a;
            
            auto itr = find(nums.begin(), nums.end(), b);
            
            if (itr != nums.end()) {
                int i = itr - nums.begin();
                if (i != idx) 
                    return vector<int>{idx, i};
            }
        }
        
        return vector<int>{0};
    }
};

// 12ms, 11.2MB
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        
        for (int idx = 0; idx < nums.size(); idx++) {
            int b = target - nums[idx];
            
            if (m.find(b) != m.end()) {
                return {m[b], idx};
            }
            
            m[nums[idx]] = idx;
        }
        return {0};
    }
};
