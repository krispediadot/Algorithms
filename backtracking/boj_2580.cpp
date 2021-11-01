// 2024 KB, 288ms
#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<vector<int>>& board, vector<pair<int, int>>& blank, int idx) {

    if (idx >= blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    pair<int, int>& pos = blank[idx];

    bool done = false;

    vector<bool> candidate(10, true);

    // row
    for (int r = 0; r < 9; r++) candidate[board[r][pos.second]] = false;
    // col
    for (int c = 0; c < 9; c++) candidate[board[pos.first][c]] = false;
    // square
    pair<int, int> init = {int(pos.first / 3)*3, int(pos.second / 3)*3};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            candidate[board[init.first + r][init.second + c]] = false;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (candidate[i] == true) {
            board[pos.first][pos.second] = i;
            done |= solution(board, blank, idx+1);
            board[pos.first][pos.second] = 0;
        }

        if (done) break;
    }

    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board(9, vector<int>(9));
    vector<pair<int, int>> blank;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
        }
    }

    solution(board, blank, 0);

    return 0;
}
