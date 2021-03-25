#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int dfs(vector<vector<int>>& maze, int r, int c) {
    
    const int dirR[] {-1, 1, 0, 0};
    const int dirC[] {0, 0, -1, 1};

    auto is_valid = [&](int new_r, int new_c) {
        return new_r >= 0 && new_r < maze.size() && new_c >= 0 && new_c < maze.size() && maze[new_r][new_c] == 1;
    };

    stack<pair<int, int>> st;
    maze[r][c] = 0;
    st.push({r, c});

    int cnt = 1;

    while (!st.empty()) {
        auto target = st.top();

        for (int dir = 0; dir < 4; dir++) {
            int next_r = target.first + dirR[dir];
            int next_c = target.second + dirC[dir];

            if (is_valid(next_r, next_c)) {
                maze[next_r][next_c] = 0;
                st.push({next_r, next_c});
                cnt++;
                break;
            }
        }

        if (st.top().first == target.first && st.top().second == target.second)
            st.pop();
    }

    return cnt;
}

vector<int> solution(int n, vector<vector<int>>& maze) {
    vector<int> answer;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (maze[r][c] == 1) {
                int a = dfs(maze, r, c);
                answer.push_back(a);
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main() {
    int n; cin >> n;
    vector<vector<int>> maze(n, vector<int>(n, 0));
    for (int r = 0; r < n; r++) {
        string s; cin >> s;
        for (int c = 0; c < n; c++) {
            maze[r][c] = s[c] - '0';
        }
    }

    vector<int> answer = solution(n, maze);

    cout << answer.size() << endl;
    for (auto& a : answer) cout << a << endl;

}
