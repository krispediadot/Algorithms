// 252ms, 109.1MB
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;
        
        vector<vector<int>> arr(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        
        for (int r = nums1.size() - 1; r >= 0; r--) {
            for (int c = nums2.size() - 1; c >= 0; c--) {
                if (nums1[r] == nums2[c]) {
                    arr[r][c] = arr[r + 1][c + 1] + 1;
                    
                    answer = max(answer, arr[r][c]);
                }
            }
        }
        
        return answer;
    }
};
