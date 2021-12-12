// 2024 KB, 0ms

#include <iostream>
#include <vector>

using namespace std;

// 0 - settings

const char STUDENT = 'S';
const char TEACHER = 'T';
const char BLOCK = 'O';

const int dirR[] = {-1, 0, 1, 0};
const int dirC[] = {0, 1, 0, -1};

bool isValid(int n, int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1 - input

    int n; cin >> n;
    vector<vector<char>> board(n, vector<char>(n));
    vector<pair<int, int>> teachers;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == TEACHER) teachers.push_back({i, j});
        }
    }

    // 2 - check 

    int cnt = 0; // obstacle

    for (auto& t : teachers) {

        for (int dir = 0; dir < 4; dir++) {
            pair<int, int> prev = t;
            pair<int, int> pos = {t.first + dirR[dir], t.second + dirC[dir]};

            while (isValid(n, pos.first, pos.second)) {
                if (board[pos.first][pos.second] == BLOCK) break;
                if (board[pos.first][pos.second] == STUDENT) {
                    if (board[prev.first][prev.second] == TEACHER) cnt = 4;
                    else board[prev.first][prev.second] = BLOCK;
                    cnt++;
                    break;
                }
                prev = pos;
                pos.first += dirR[dir];
                pos.second += dirC[dir];
            }

            if (cnt > 3) break;
        }

        if (cnt > 3) break;
    }

    // 3 - output

    if (cnt > 3) cout << "NO";
    else cout << "YES";

    return 0;
}
