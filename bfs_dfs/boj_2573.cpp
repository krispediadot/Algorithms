#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;

const int WATER = 0;

const int dirR[] {0, 0, 1, -1}; //동서남북
const int dirC[] {-1, 1, 0, 0}; //동서남북

int count_cover_ice(int N, int M, vector<vector<int>> maze, pair<int, int>& start) {
    auto is_valid = [&N, &M](int new_r, int new_c) {
        return new_r >= 0 && new_r < N && new_c >= 0 && new_c < M;
    };

    stack<pair<int, int>> st;
    maze[start.first][start.second] = WATER;
    st.push(start);

    int cnt = 1;

    while (!st.empty()) {
        auto target = st.top();

        for (int dir = 0; dir < 4; dir++) {
            int new_r = target.first + dirR[dir];
            int new_c = target.second + dirC[dir];

            if (is_valid(new_r, new_c) && maze[new_r][new_c] != WATER) {
                maze[new_r][new_c] = WATER;
                st.push({new_r, new_c});
                cnt++;
            }
        }

        if (st.top() == target) st.pop();
    }
    return cnt;
}

void melt(int N, int M, vector<vector<int>>& maze, set<pair<int, int>>& ice, set<pair<int, int>>& ice_melt_down) {
    auto is_valid = [&N, &M](int new_r, int new_c) {
        return new_r >= 0 && new_r < N && new_c >= 0 && new_c < M;
    };
    
    for (auto& target : ice) {
        int cnt_water = 0;
        for (int dir = 0; dir < 4; dir++) {
            int new_r = target.first + dirR[dir];
            int new_c = target.second + dirC[dir];

            if (is_valid(new_r, new_c) && maze[new_r][new_c] == WATER) 
                cnt_water++;
        }

        if (maze[target.first][target.second] - cnt_water <= 0) ice_melt_down.insert({target.first, target.second});
        else maze[target.first][target.second] -= cnt_water;
    }
}

// 바다 = 0 / 그외 빙산
// 1년에 동서남북의 바다 수만큼 줄어듬
// 두 덩어리 이상으로 분리되는 최초의 시간
// 두 덩어리로 분리되지 않으면 0
int solution(int N, int M, vector<vector<int>>& maze, set<pair<int, int>>& ice) {
    int answer = 0;

    while (ice.size() > 0) {
        answer++;

        // 1. 빙산이 녹음
        set<pair<int, int>> ice_melt_down;
        melt(N, M, maze, ice, ice_melt_down);

        // 다 녹은 빙산 제거
        for (auto& target : ice_melt_down) {
            maze[target.first][target.second] = WATER;
            ice.erase(ice.find(target));
        }

        // 남은 빙산이 없으면 0
        if (ice.size() == 0) break;

        // 2. 덩어리 수 계산
        pair<int, int> start = *ice.begin();
        int cnt = count_cover_ice(N, M, maze, start);

        // 3. 덩어리 2개 이상이면 끝
        if (cnt < ice.size()) return answer;
    }
    
    return 0;
}

int main() {
    int N, M; cin >> N >> M;

    set<pair<int, int>> ice;
    vector<vector<int>> maze(N, vector<int>(M, 0));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> maze[r][c];
            if (maze[r][c] != WATER) 
                ice.insert({r, c});
        }
    }

    cout << solution(N, M, maze, ice) << endl;

}
