#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

using loc = pair<int, int>;

const int LAND = -1;
const int dirR[] = {-1, 0, 1, 0}; //북동남서
const int dirC[] = {0, 1, 0, -1};

int N, M;
vector<vector<int>> space;
vector<pair<int, pair<loc, loc>>> edges; // {cnt, {from, to}}
vector<int> parents;
int group_cnt = 1;

bool is_valid(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void update_edges(int r, int c) {
    for (int dir = 0; dir < 4; dir++) {
        int r_copy = r + dirR[dir];
        int c_copy = c + dirC[dir];
        int cnt = 1;

        while (is_valid(r_copy, c_copy)) {
            if (space[r_copy][c_copy] != 0) break;
            r_copy += dirR[dir];
            c_copy += dirC[dir];
            cnt++;
        }

        if (is_valid(r_copy, c_copy) && (space[r_copy][c_copy] == LAND || space[r_copy][c_copy] < 0)) {
            if (cnt - 1 > 1) edges.push_back({cnt - 1, {{r, c}, {r_copy, c_copy}}});
        }
    }
}

void set_group(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    
    while (!q.empty()) {
        auto target = q.front(); q.pop();
        space[target.first][target.second] = group_cnt;
        update_edges(target.first, target.second);

        for (int dir = 0; dir < 4; dir++) {
            int next_r = target.first + dirR[dir];
            int next_c = target.second + dirC[dir];

            if (is_valid(next_r, next_c) && space[next_r][next_c] == LAND) {
                q.push({next_r, next_c});
            }
        }
    }
}

int find_set(int target) {
    if (parents[target] == target) return target;
    return parents[target] = find_set(parents[target]);
}

void union_set(int a, int b) {
    int pa = find_set(a);
    int pb = find_set(b);

    parents[pb] = pa;
}

int solution() {
    int answer = 0;

    // 1. 섬 확인
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            if (space[r][c] == LAND) {
                set_group(r, c);
                group_cnt++;
            }
        }
    }

    sort(edges.begin(), edges.end());

    parents.resize(group_cnt, 0);
    for (int i = 0; i < group_cnt; i++) parents[i] = i;
    
    // 2. 섬 연결
    for (auto edge : edges) {
        loc from = edge.second.first;
        loc to = edge.second.second;

        int from_idx = space[from.first][from.second];
        int to_idx = space[to.first][to.second];

        if (from_idx != to_idx && (find_set(from_idx) != find_set(to_idx))) {
            union_set(from_idx, to_idx);
            answer += edge.first;
        }
    }

    unordered_set<int> group;
    for (int i = 1; i < group_cnt; i++) {
        parents[i] = find_set(i);
        group.insert(parents[i]);
    }

    if (group.size() != 1) return -1;
    return answer;
}

int main() {
    cin >> N >> M;
    
    space.resize(N, vector<int> (M, 0));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cin >> space[r][c];
            space[r][c] *= -1;
        }
    }

    cout << solution() << endl;
}
