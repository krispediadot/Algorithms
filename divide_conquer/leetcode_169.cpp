// 16ms, 19.7MB, 00:15:00
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int idx = 0;
        int target = nums[0];
        
        while (idx < nums.size()) {
            target = nums[idx];
            int cnt = 0;
            
            while (idx < nums.size() && nums[idx] == target) {
                idx++;
                cnt++;
            }
            
            if (cnt > nums.size() / 2) break;
        }
        return target;
    }
};

// 16ms, 19.6MB, 00:25:00
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int answer = 0;
        int cnt = 0;

        for (auto n : nums) {
            if (answer == n) cnt++;
            else if(cnt == 0) {
                answer = n;
                cnt++;
            }
            else cnt--;
        }

        return answer;
    }
};

// 8ms, 19.6MB, 00:29:00
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int answer = 0;
        int cnt = 0;

        for (auto n : nums) {
            if(cnt == 0) answer = n;

            cnt += (n == answer) ? 1 : -1;
        }

        return answer;
    }
};
