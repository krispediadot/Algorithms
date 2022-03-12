#include <string>
#include <vector>

using namespace std;

const int MOD = 10000019;

bool isValid(pair<int, int> p, int width, int height) {
    return p.first >= 0 && p.first <= height && p.second >= 0 && p.second <= width;
}

long long counter(int w, int h) {
    vector<vector<int>> board(h, vector<int>(w));

    for (int r = 0; r < board.size(); r++) board[r][0] = 1;
    for (int c = 0; c < board[0].size(); c++) board[board.size()-1][c] = 1;

    for (int r = board.size()-2; r >= 0; r--) {
        for (int c = 1; c < board[0].size(); c++) {
            board[r][c] = (board[r][c-1] + board[r+1][c] % MOD);
        }
    }
    return board[0][w-1] % MOD;
}

long long checker(int width, int height, pair<int, int> p1, pair<int, int> p2) {
    pair<int, int> from = {height, 0};
    pair<int, int> to = {0, width};

    return counter(p1.second + 1, height - p1.first + 1) * counter(width - p2.second + 1, p2.first + 1);
}

int solution(int width, int height, vector<vector<int>> diagonals) {
    int answer = 0;

    for (int i = 0; i < diagonals.size(); i++) {
        // 왼위(남서)
        int r = height - diagonals[i][1];
        int c = diagonals[i][0] - 1;
        pair<int, int> p1 = {r, c};

        // 오아래(북동)
        r = height - diagonals[i][1] + 1;
        c = diagonals[i][0];
        pair<int, int> p2 = {r, c};

        answer += int(checker(width, height, p1, p2) % MOD);
        answer += int(checker(width, height, p2, p1) % MOD);
        answer %= MOD;
    }

    return answer;
}
