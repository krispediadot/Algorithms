// 2036 KB, 4ms
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 8방향

const int dirR[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int dirC[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

bool isValid(pair<int, int>& a, int& N) {
    return a.first >= 0 && a.first < N && a.second >= 0 && a.second < N;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(N));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> board[r][c];
        }
    }
    
    queue<pair<int, int>> cloud; // {r, c}
    cloud.push({N-2, 0});
    cloud.push({N-2, 1});
    cloud.push({N-1, 0});
    cloud.push({N-1, 1});
    

    while (M--) {
        vector<vector<bool>> removed(N, vector<bool>(N, false));
        int d, s; cin >> d >> s;

        for (int i = 0; i < cloud.size(); i++) {
            auto target = cloud.front(); cloud.pop();

            // 1
            target.first += (dirR[d] * s);
            while (target.first < 0) target.first += N; 
            while (target.first >= N) target.first -= N;
            target.second += (dirC[d] * s);
            while (target.second < 0) target.second += N;
            while (target.second >= N) target.second-= N;

            // 2
            board[target.first][target.second]++;
            cloud.push(target);
            removed[target.first][target.second] = true;
        }

        // 3,
        while (!cloud.empty()) {
            auto target = cloud.front(); cloud.pop();
            // 4
            for (int dir = 2; dir <= 8; dir+=2) {
                pair<int, int> cross = {target.first + dirR[dir], target.second + dirC[dir]};
                if (isValid(cross, N) && board[cross.first][cross.second] > 0)
                    board[target.first][target.second]++;
            }
        }

        // 5
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (removed[r][c] == false && board[r][c] >= 2) {
                    cloud.push({r, c});
                    board[r][c] -= 2;
                }
            }
        }
    }

    int answer = 0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            answer += board[r][c];
        }
    }

    cout << answer << '\n';

    return 0;
}
