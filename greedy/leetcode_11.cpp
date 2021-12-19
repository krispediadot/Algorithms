// 59.1 MB, 84ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int s = 0, e = height.size()-1;
        int answer = 0;
        
        while (s < e) {
            answer = max(answer, (e-s)*min(height[s], height[e]));
                
            if (height[s] < height[e]) s++;
            else if (height[s] > height[e]) e--;
            else {
                if (height[s+1] > height[e-1]) s++;
                else e--;
            }   
        }       
        
        return answer;
    }
};
