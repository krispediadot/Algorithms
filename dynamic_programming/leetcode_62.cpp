class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> board(m, vector<int> (n, 1));
        
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                board[r][c] = board[r-1][c] + board[r][c-1];
            }
        }
        
        return board[m-1][n-1];
    }
};
