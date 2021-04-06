#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int KILLERS_TOTAL = 3;

int N, M, D;
vector<pair<int, int>> enemies;

bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

int get_near_enemy_idx(pair<int, int>& killer_loc, vector<pair<int, int>>& enemies_copy) {
    
    const int dirR[] = {0, -1, 0, 1}; // 서북동남
    const int dirC[] = {-1, 0, 1, 0};

    queue<pair<pair<int, int>, int>> q;
    q.push({killer_loc, 0});

    while (!q.empty()) {
        auto target = q.front(); q.pop();
        pair<int, int> target_loc = target.first;
        int dist = target.second;

        if (dist > D) break;

        for (int dir = 0; dir < 4; dir++) {
            int next_r = target_loc.first + dirR[dir];
            int next_c = target_loc.second + dirC[dir];

            auto itr = find(enemies_copy.begin(), enemies_copy.end(), make_pair(next_r, next_c));

            if (is_valid(next_r, next_c)) {
                if (dist + 1 <= D && itr != enemies_copy.end()) {
                    return itr-enemies_copy.begin();
                }
                q.push({{next_r, next_c}, dist + 1});
            }
        }
    }
    return -1;
}

int kill_enemies(vector<pair<int, int>>& killers_copy) {

    vector<pair<int, int>> enemies_copy = enemies;
    int killed_cnt = 0;

    int time_limit = N;
    while (time_limit--) {
        vector<int> target_enemies_idx(KILLERS_TOTAL);

        // 1. 가까운 적 찾기
        for (int killer_idx = 0; killer_idx < KILLERS_TOTAL; killer_idx++) {
            pair<int, int>& killer_loc = killers_copy[killer_idx];
            
            int target_enemy_idx = get_near_enemy_idx(killer_loc, enemies_copy);
            target_enemies_idx[killer_idx] = target_enemy_idx;
        }

        // 2. 적 제거
        for (int killer_idx = 0; killer_idx < KILLERS_TOTAL; killer_idx++) {
            int target_enemy_idx = target_enemies_idx[killer_idx];

            if (target_enemy_idx < enemies_copy.size() && enemies_copy[target_enemy_idx].first != N) {
                enemies_copy[target_enemy_idx].first = N;
                killed_cnt++;
            }
        }

        // 3. 남아있는 적 아래로 이동
        for (int enemy_idx = 0; enemy_idx < enemies_copy.size(); enemy_idx++) {
            if (enemies_copy[enemy_idx].first != N) {
                enemies_copy[enemy_idx].first++;
            }
        }

        // 4. 적이 모두 제거되면 끝
        int enemy_left = 0;
        for (auto enemy : enemies_copy) {
            if (enemy.first != N) {
                enemy_left++;
            }
        }
        if (enemy_left == 0) break;
    }

    return killed_cnt;
}

// 제거할 수 있는 최대 적의 수
void solution(vector<pair<int, int>> killers, int& answer) {
    if (killers.size() == KILLERS_TOTAL) {
        answer = max(answer, kill_enemies(killers));
        return;
    }
    for (int idx = 0; idx < M; idx++) {
        killers.push_back({N,idx});

        solution(killers, answer);

        killers.pop_back();
    }
}

int main() {
    cin >> N >> M >> D;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            int stat; cin >> stat;

            if (stat == 1) enemies.push_back({r, c});
        }
    }

    int answer = 0;
    vector<pair<int, int>> killers;

    solution(killers, answer);

    cout << answer << endl;
}
