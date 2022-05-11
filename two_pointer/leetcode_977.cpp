// 25.9 MB, 36ms
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> answer(nums.size());
        int left = 0, right = nums.size() - 1;
        
        int idx =nums.size() - 1;
        
        while (left <= right) {
            
            int turn = (abs(nums[left]) < abs(nums[right]) ? right-- : left++) ;

            answer[idx] = pow(nums[turn],2);
            idx--;
        }
        
        return answer;
    }
};
