#include <iostream>
#include <vector>

using namespace std;

const int BLANK = 0;
const int WALL = 1;
const int CLEAN = 2;

const int dirR[] {-1, 0, 1, 0}; // 북서남동 
const int dirC[] {0, -1, 0, 1}; // 북서남동
int N, M;

using robot = pair<pair<int, int>, int>; // {{위치r, 위치c}, 방향}

void print_maze(vector<vector<int>>& maze) {
    for (auto& r : maze) {
        for (auto& c : r) 
            cout << c << " ";
        cout << endl;
    }
}

// 로봇 청소기의 청소 영역 개수 
// 청소기 동작 
// 1. 현재 위치 청소
// 2. 왼쪽 방향부터 차례로 확인
// a. 왼쪽이 청소 가능, 회전 후 전진
// b. 왼쪽이 청소 불가능이면, 회전 후 왼쪽
// c. 네 방향 모두 청소 되거나 벽이라면, 방향 유지 & 후진
// d. 네 방향 모두 청소 되거나 벽이고, 후진도 안되면 끝
int solution(robot& bot, vector<vector<int>>& maze) {
    auto is_valid = [](pair<int, int> loc) {
        return loc.first > 0 && loc.first < N - 1 && loc.second > 0 && loc.second < M - 1;
    };
    auto movable = [&](pair<int, int>& loc) {
        for (int dir = 0; dir < 4; dir++) {
            int new_r = loc.first + dirR[dir];
            int new_c = loc.second + dirC[dir];

            if (is_valid({new_r, new_c}) && maze[new_r][new_c] == BLANK)
                return true;
        }
        return false;
    };

    pair<int, int>& bot_loc = bot.first;
    int& bot_dir = bot.second;

    // 1. 현재 위치 청소
    maze[bot_loc.first][bot_loc.second] = CLEAN;
    int cnt = 1;

    // 2. 왼쪽 방향부터 차례로 확인
    while (1) {
        //print_maze(maze);
        // a, b
        if (movable(bot_loc)) {
            // 현재 방향의 왼쪽
            bot_dir = (bot_dir + 1) % 4;
            int cnt_turn = 0;
            
            while (cnt_turn < 4) {
                int new_r = bot_loc.first + dirR[bot_dir];
                int new_c = bot_loc.second + dirC[bot_dir];

                // a. 왼쪽이 청소 가능, 회전 후 전진
                if (is_valid({new_r, new_c}) && maze[new_r][new_c] == BLANK) {
                    maze[new_r][new_c] = CLEAN;
                    cnt++;
                    bot_loc = {new_r, new_c};
                    break;
                }
                // b. 왼쪽이 청소 불가능이면, 회전 후 왼쪽
                bot_dir = (bot_dir + 1) % 4;
                cnt_turn++;
            }
        }
        // c, d
        else {
            // 후진 방향
            int bot_dir_back = (bot_dir + 2) % 4;
            
            int new_r = bot_loc.first + dirR[bot_dir_back];
            int new_c = bot_loc.second + dirC[bot_dir_back];

            // c. 네 방향 모두 청소 되거나 벽이라면, 방향 유지 & 후진
            if (is_valid({new_r, new_c}) && maze[new_r][new_c] != WALL) {
                if (maze[new_r][new_c] != CLEAN) cnt++;
                maze[new_r][new_c] = CLEAN;
                bot_loc = {new_r, new_c};
            }
            // d. 네 방향 모두 청소 되거나 벽이고, 후진도 안되면 끝
            else {
                break;
            }
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;
    
    robot bot {{0, 0}, 0}; cin >> bot.first.first >> bot.first.second >> bot.second;
    bot.second = (bot.second % 2 == 1) ? ((bot.second == 3) ? 1 : 3) : bot.second;

    vector<vector<int>> maze(N, vector<int> (M, 0));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> maze[r][c];
        }
    }

    cout << solution(bot, maze) << endl;
}
