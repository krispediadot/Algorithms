// 2024KB, 4ms

#include <iostream>
#include <vector>

using namespace std;

const char WALL = 'T';

const int dirR[] = {-1, 0, 1, 0};
const int dirC[] = {0, 1, 0, -1};


bool isValid(vector<vector<char>>& board, int R, int C, int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C && board[r][c] != WALL;
}

void solution(vector<vector<char>>& board, vector<vector<bool>>& visited, int R, int C, int K, pair<int, int> cur, int cnt, int& answer) {
    if (cnt == K) {
        if (cur.first == 0 && cur.second == C-1) answer++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int nextR = cur.first + dirR[dir];
        int nextC = cur.second + dirC[dir];

        if (isValid(board, R, C, nextR, nextC) && visited[nextR][nextC] == false) {
            visited[nextR][nextC] = true;
            solution(board, visited, R, C, K, {nextR, nextC}, cnt+1, answer);
            visited[nextR][nextC] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int R, C, K; cin >> R >> C >> K;
    vector<vector<char>> board(R, vector<char>(C));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> board[r][c];
        }
    }

    int answer = 0;

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    pair<int, int> cur = {R-1, 0};
    visited[R-1][0] = true;
    
    solution(board, visited, R, C, K, cur, 1, answer);
    
    cout << answer << '\n';

    return 0;
}

// 2024KB, 8ms

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const char WALL = 'T';

const int dirR[] = {-1, 0, 1, 0};
const int dirC[] = {0, 1, 0, -1};


bool isValid(vector<vector<char>>& board, int R, int C, int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C && board[r][c] != WALL;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int R, C, K; cin >> R >> C >> K;
    vector<vector<char>> board(R, vector<char>(C));

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> board[r][c];
        }
    }

    int cnt = 0;

    vector<vector<bool>> visited(R, vector<bool>(C, false));
    pair<int, int> cur = {R-1, 0};
    stack<pair<pair<int, int>,string>> st;
    visited[cur.first][cur.second] = true;
    st.push({cur, "0000"});

    while (!st.empty()) {

        cur = st.top().first;
        string& visitedDir = st.top().second;

        if (st.size() == K) {
            if (cur.first == 0 && cur.second == C-1) cnt++;
            visited[cur.first][cur.second] = false;
            st.pop();
            continue;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nextR = cur.first + dirR[dir];
            int nextC = cur.second + dirC[dir];

            if (isValid(board, R, C, nextR, nextC) && visited[nextR][nextC] == false && visitedDir[dir] == '0') {
                visitedDir[dir] = '1';
                visited[nextR][nextC] = true;
                st.push({{nextR, nextC}, "0000"});
                break;
            }
        }

        if (st.top().first == cur) {
            visited[cur.first][cur.second] = false;
            st.pop();
        }
    }
    
    cout << cnt << '\n';

    return 0;
}
