// 26.2 MB, 41ms
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k %= nums.size();
        
        vector<int> answer;
        
        for (int i = nums.size() - k; i < nums.size(); i++)
            answer.push_back(nums[i]);
        
        for (int i = 0; i < nums.size() - k; i++) 
            answer.push_back(nums[i]);
         
        nums = answer;
    }
};

// 25 MB, 45ms 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k %= nums.size();
        
        reverse(nums.begin(), nums.end() - k);
        reverse(nums.end() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
