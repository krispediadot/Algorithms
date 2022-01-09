class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> cnts(1001);
        
        bool answer = true;
        
        for (auto& t : trips) {
            for (int i = t[1]; i < t[2]; i++) {
                cnts[i]+=t[0];
                
                if (cnts[i] > capacity) {
                    answer = false;
                    break;
                }
            }
            if (answer == false) break;
        }
        
        return answer;
    }
};
