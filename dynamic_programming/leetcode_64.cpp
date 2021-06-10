// 12ms, 10.1MB, 00:11:29
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r_size = grid.size();
        int c_size = grid[0].size();
        
        vector<vector<int>> result = grid;
        
        for (int r = 1; r < r_size; r++) result[r][0] += result[r - 1][0];
        for (int c = 1; c < c_size; c++) result[0][c] += result[0][c - 1];
        
        for (int r = 1; r < r_size; r++) {
            for (int c = 1;   c < c_size; c++) {
                result[r][c] += min(result[r - 1][c], result[r][c - 1]);
            }
        }
         
        return result.back().back();
    }
};

// 8ms, 9.5MB, 00:11:29
class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r_size = grid.size();
        int c_size = grid[0].size();

        for (int r = 1; r < r_size; r++) grid[r][0] += grid[r - 1][0];
        for (int c = 1; c < c_size; c++) grid[0][c] += grid[0][c - 1];

        for (int r = 1; r < r_size; r++) {
            for (int c = 1;   c < c_size; c++) {
                grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
            }
        }

        return grid.back().back();
    }
};
