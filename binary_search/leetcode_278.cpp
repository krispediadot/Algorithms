// 6MB, 0ms
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        
        while (left < right && right >= 0) {
            int mid = left + (right - left)/2;
            
            if (isBadVersion(mid) == false) left = mid + 1;
            else right = mid;
        }
        return right;
    }
};
