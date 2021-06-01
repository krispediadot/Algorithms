class Solution {
public:
    int minDistance(string word1, string word2) {
        int r = word1.size() + 1;
        int c = word2.size() + 1;
        vector<vector<int>> memo(r, vector<int>(c, -1));
        
        for (int i = 0; i < r; i++) {
            memo[i][0] = i;
        }
        for (int j = 0; j < c; j++) {
            memo[0][j] = j;
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                memo[i][j] = min(memo[i - 1][j], memo[i][j - 1]) + 1;
                if (word1[i - 1] == word2[j - 1]) {
                    memo[i][j] = min(memo[i][j], memo[i - 1][j - 1]);
                }
                else {
                    memo[i][j] = min(memo[i][j], memo[i - 1][j - 1] + 1);
                }
            }
        }
        return memo[r - 1][c - 1];
    }
};
