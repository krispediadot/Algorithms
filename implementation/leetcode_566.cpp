// 12ms, 10.6MB
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int nR = mat.size();
        int nC = mat[0].size();
        
        if (nR * nC != r * c) return mat;
        
        vector<vector<int>> answer(r, vector<int>(c));
        
        int rm = 0;
        int cm = 0;
        
        for (int ra = 0; ra < r; ra++) {
            for (int ca = 0; ca < c; ca++) {
                
                answer[ra][ca] = mat[rm][cm];
                
                cm++;
                if (cm >= nC) {
                    cm = 0;
                    rm++;
                }
            }
        }
        
        return answer;
    }
};
