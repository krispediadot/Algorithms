// 15.4MB, 11ms
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            if (numbers[left] + numbers[right] == target) 
                break;
            
            if (numbers[left] + numbers[right] < target) 
                left++;
            else
                right--;
        }
        
        return {left+1, right+1};
    }
};
