// 8ms, 6.9MB, 00:20:00
class Solution1 {
public:
    vector<int> partitionLabels(string S) {
        vector<int> answer;
        
        // 1. count each letter
        unordered_map<char, int> m;
        for (auto c : S) m[c]++;
        
        // 2. 
        unordered_map<char, int> temp;
        int idx = 0;
        
        while (idx < S.length()) {
            temp[S[idx]]++;
            
            if (temp[S[idx]] == m[S[idx]]) temp.erase(S[idx]);
            
            if (temp.empty()) {
                answer.push_back(idx + 1);
            }
            
            idx++;
        }
        
        for (int i = answer.size() - 1; i > 0; i--) {
            answer[i] -= answer[i - 1];
        }
        
        return answer;
    }
};

// 8ms, 6.8MB, 00:33:40
class Solution2 {
public:
    vector<int> partitionLabels(string S) {
        vector<int> answer;

        // 1. count each letter
        unordered_map<char, int> m;
        for (auto c : S) m[c]++;

        // 2. partition
        unordered_map<char, int> temp;
        int prev = 0;

        for (int idx = 0; idx < S.length(); idx++) {
            char target = S[idx];

            if (temp.find(target) == temp.end())
                temp[target] = m[target];
            temp[target]--;

            if (temp[target] == 0) temp.erase(target);

            if (temp.empty()) {
                answer.push_back(idx + 1 - prev);
                prev = idx + 1;
            }
        }

        return answer;
    }
};

// 4ms, 6.8MB, 00:37:00
class Solution3 {
public:
    vector<int> partitionLabels(string S) {
        vector<int> answer;

        // 1. count each letter
        unordered_map<char, int> m;
        for (auto c : S) m[c]++;

        // 2. partition
        unordered_map<char, int> temp;
        int gap = 0;

        for (int idx = 0; idx < S.length(); idx++) {
            gap++;
            char target = S[idx];

            if (temp.find(target) == temp.end())
                temp[target] = m[target];
            temp[target]--;

            if (temp[target] == 0) temp.erase(target);

            if (temp.empty()) {
                answer.push_back(gap);
                gap = 0;
            }
        }

        return answer;
    }
};

// 4ms, 6.6MB, 00:54:00
class Solution4 {
public:
    vector<int> partitionLabels(string S) {
        vector<int> last_loc(26, -1);
        vector<int> answer;

        // 1. get last location
        for (int idx = 0; idx < S.length(); idx++)
            last_loc[S[idx] - 'a'] = idx;

        // 2. partition
        int start = 0, end = -1;
        for (int idx = 0; idx < S.length(); idx++) {
            char target = S[idx];

            end = max(end, last_loc[target - 'a']);

            if (idx == end) {
                answer.push_back(end - start + 1);
                start = end + 1;
                end = -1;
            }
        }

        return answer;
    }
};
