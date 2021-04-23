// 120ms, 97.1MB, 00:50:00
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min = INT_MAX;
        
        for (auto p : prices) {
            if (p < min) min = p;
            else profit = max(profit, p - min);
        }
        
        return profit;
    }
};
