// O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int answer = 0;
        
        for (int idx = 1; idx < nums.size() - 1; idx++) {
            if (nums[idx] > nums[idx - 1] && nums[idx] > nums[idx + 1])
                answer = idx;
        }
        
        return answer;
    }
};

// O(logn)
// 4ms, 8.8MB
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = (left + right) / 2;
            
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};

