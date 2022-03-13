/*
테스트 1 〉	통과 (0.01ms, 4.16MB)
테스트 2 〉	통과 (0.01ms, 3.64MB)
테스트 3 〉	통과 (3.06ms, 6.23MB)
테스트 4 〉	통과 (2.22ms, 5.61MB)
테스트 5 〉	통과 (2.09ms, 5.12MB)
테스트 6 〉	통과 (3.80ms, 6.71MB)
테스트 7 〉	통과 (3.76ms, 7.09MB)
테스트 8 〉	통과 (3.16ms, 5.89MB)
테스트 9 〉	통과 (3.42ms, 6.69MB)
테스트 10 〉	통과 (2.74ms, 6.11MB)
테스트 11 〉	통과 (2.45ms, 5.77MB)
*/

#include <string>
#include <vector>

using namespace std;

int clockwise(vector<vector<int>>& board, int x1, int y1, int x2, int y2) {
    
    int temp = board[x1-1][y1-1];
    int target = temp;
    
    for (int r = x1-1; r < x2-1; r++) {
        board[r][y1-1] = board[r+1][y1-1];
        target = min(target, board[r][y1-1]);
    }
    for (int c = y1-1; c < y2-1; c++) {
        board[x2-1][c] = board[x2-1][c+1];
        target = min(target, board[x2-1][c]);
    }
    for (int r = x2-1; r > x1-1; r--) {
        board[r][y2-1] = board[r-1][y2-1];
        target = min(target, board[r][y2-1]);
    }
    for (int c = y2-1; c > y1-1; c--) {
        board[x1-1][c] = board[x1-1][c-1];
        target = min(target, board[x1-1][c]);
    }
    
    board[x1-1][y1] = temp;
    
    return target;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows, vector<int>(columns));
    int n = 1;
    
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            board[r][c] = n++;
        }
    }
    
    for (auto q : queries) {
        answer.push_back(clockwise(board, q[0], q[1], q[2], q[3]));    
    }
    
    return answer;
}
