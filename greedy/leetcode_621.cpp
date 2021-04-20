// 48ms, 34.9MB, x
class Solution {
public:
    int leastInterval(vector<char> tasks, int n) {
        vector<int> cnt_char(26, 0);
        for (auto c : tasks) cnt_char[c - 'A']++;
        
        sort(cnt_char.begin(), cnt_char.end());
        
        int cnt_max = cnt_char[25] - 1;
        int cnt_idle = cnt_max * n;
        
        for (int idx = 24; idx >= 0; idx--)
            cnt_idle -= min(cnt_char[idx], cnt_max);
        
        return cnt_idle > 0 ? cnt_idle + tasks.size() : tasks.size();
    }
};
