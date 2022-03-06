class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> m;
        for(auto s : stones) m[s]++;
        
        int cnt = 0;
        for(auto j : jewels) cnt += m[j];
        
        return cnt;
    }
};
