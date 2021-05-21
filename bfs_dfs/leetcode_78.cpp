class Solution {
public:
    void subset_generator(vector<int>& nums, vector<vector<int>>& answer, int idx, vector<int> temp) {
        if (idx > nums.size()) return;
        
        for (int i = idx; i < nums.size(); i++) {
            vector<int> temp_copy = temp;
            temp_copy.push_back(nums[i]);
            answer.push_back(temp_copy);
            subset_generator(nums, answer, i + 1, temp_copy);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        answer.push_back(vector<int>(0));
        
        subset_generator(nums, answer, 0, vector<int>());
        
        return answer;
    }
};
