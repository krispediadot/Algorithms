// 20832 KB, 356ms
#include <iostream>
#include <vector>

using namespace std;

bool isOneNumber(vector<vector<int>>& board, int r_s, int c_s, int size) {
    int number = board[r_s][c_s];

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (board[r_s + r][c_s + c] != number) return false;
        }
    }

    return true;
}

void solution(vector<vector<int>>& board, int r_s, int c_s, int size, vector<int>& answer) {
    if (size == 1 || isOneNumber(board, r_s, c_s, size)) {
        answer[board[r_s][c_s]+1]++;
        return;
    }

    // divide 9
    int len = size / 3;

    for (int r = r_s; r < r_s+size; r+=len) {
        for (int c = c_s; c < c_s+size; c+=len) {
            solution(board, r, c, len, answer);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> answer(3);

    solution(board, 0, 0, n, answer);

    for (auto a : answer) cout << a << '\n';

    return 0;
}

// 23300 KB, 1068ms
#include <iostream>
#include <vector>

using namespace std;

bool isOneNumber(vector<vector<int>>& board) {
    int number = board[0][0];

    for (auto& r : board) {
        for (auto& c : r) {
            if (c != number) return false;
        }
    }
    return true;
}

void generatePatch(vector<vector<int>>& patch, vector<vector<int>>& board, int r_s, int c_s, int len) {
    patch.clear();
    patch.resize(len, vector<int>(len));

    for (int r = 0; r < len; r++) {
        for (int c = 0; c < len; c++) {
            patch[r][c] = board[r_s + r][c_s + c];
        }
    }
}

void solution(vector<vector<int>>& board, vector<int>& answer) {
    if (isOneNumber(board)) {
        answer[board[0][0]+1]++;
        return;
    }

    // divide 9
    int len = board.size() / 3;
    vector<vector<int>> patch(len, vector<int>(len));

    for (int r = 0; r < board.size(); r+=len) {
        for (int c = 0; c < board.size(); c+=len) {
            generatePatch(patch, board, r, c, len);
            solution(patch, answer);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> answer(3);

    solution(board, answer);

    for (auto a : answer) cout << a << '\n';

    return 0;
}
