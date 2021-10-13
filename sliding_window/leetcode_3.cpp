// 8.9 MB, 20ms

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int pin = 0;
        
        while (pin <= matrix.size()/2) {
            int lineLen = matrix.size() - (pin*2);
            
            vector<int> temp;
            for (int i = 0; i < lineLen-1; i++) temp.push_back(matrix[pin+i][pin]);
            
            // left
            for (int r = 0; r < lineLen; r++) matrix[pin+r][pin] = matrix[pin+lineLen-1][pin+r];
            
            // bottom
            for (int c = 1; c < lineLen; c++) matrix[pin+lineLen-1][pin+c] = matrix[pin+lineLen-1-c][pin+lineLen-1];
            
            // right
            for (int r = lineLen-2; r >= 0; r--) matrix[pin+r][pin+lineLen-1] = matrix[pin][pin+r];
            
            // top
            for (int i = 0; i < lineLen-1; i++) matrix[pin][pin+lineLen-1-i] = temp[i];
            
            pin++;
        }
    }
};
