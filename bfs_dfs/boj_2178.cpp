#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// 최소의 칸을 이동해서 도착하기 - bfs
int solution(int& n, int& m,  vector<vector<int>>& maze) {
    const int dirR[] {-1, 1, 0, 0};
    const int dirC[] {0, 0, -1, 1};

    auto is_valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == 1;
    };

    vector<vector<int>> visited(n, vector<int> (m, 0));
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, 0}, 1});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto target = q.front(); q.pop();
        pair<int, int> location = target.first;
        int step = target.second;

        if (location.first == n - 1 && location.second == m - 1) return step;

        for (int dir = 0; dir < 4; dir++) {
            int nextR = location.first + dirR[dir];
            int nextC = location.second + dirC[dir];

            if (is_valid(nextR, nextC) && !visited[nextR][nextC]) {
                q.push({{nextR, nextC}, step + 1});
                visited[nextR][nextC] = 1;
            }
        }
    }
    return -1;
}

int main() {

    int n, m; cin>>n>>m;
    vector<vector<int>> maze(n, vector<int> (m, 0));
    for (int r = 0; r < n; r++) {
        string s; cin>>s;
        for (int c = 0; c < m; c++) {
            maze[r][c] = s[c] - '0';
        }
    }

    cout << solution(n, m, maze) << endl;
}
