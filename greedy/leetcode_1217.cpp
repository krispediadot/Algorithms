// 7.4 MB, 0ms

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cntEven = 0, cntOdd = 0;
        
        for (auto& p : position) {
            if (p % 2 == 0) cntEven++;
            else cntOdd++;
        }
        
        if (cntEven > cntOdd) return cntOdd;
        return cntEven;
    }
};
