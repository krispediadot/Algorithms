// 16ms, 10.1M, 00:10:00
class Solution {
public:
    void bfs(vector<vector<char>>& grid) {
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        auto is_valid = [&](int& r, int& c) {
            return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
        };
        
        const int dirR[] = {-1, 0, 1, 0}; // 북동남서
        const int dirC[] = {0, 1, 0, -1};
        
        const char LAND = '1'; 
        
        int answer = 0;
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == LAND) {
                    answer++;
                    
                    queue<pair<int, int>> q; //{r, c}
                    
                    grid[r][c] = 0;
                    q.push({r, c});
                    
                    while (!q.empty()) {
                        auto target = q.front(); q.pop();
                        
                        for (int dir = 0; dir < 4; dir++) {
                            int next_r = target.first + dirR[dir];
                            int next_c = target.second + dirC[dir];
                            
                            if (is_valid(next_r, next_c) && grid[next_r][next_c] == LAND) {
                                grid[next_r][next_c] = '0';
                                q.push({next_r, next_c});
                            }   
                        }
                    }
                }
            }
        }
        
        return answer;
    }
};
