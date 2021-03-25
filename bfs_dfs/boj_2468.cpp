#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int count_safe_space(int N, vector<vector<int>> maze, int limit) {

    const int dirR[] {-1, 1, 0, 0};
    const int dirC[] {0, 0, -1, 1};

    auto is_valid = [&](int new_r, int new_c) {
        return new_r >= 0 && new_r < N && new_c >= 0 && new_c < N;
    };

    int cnt = 0;

    stack<pair<int, int>> st; // {r, c}
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (maze[r][c] > limit) {
                cnt++;
                st.push({r, c});

                while (!st.empty()) {
                    auto target = st.top();

                    for (int dir = 0; dir < 4; dir++) {
                        int new_r = target.first + dirR[dir];
                        int new_c = target.second + dirC[dir];

                        if (is_valid(new_r, new_c) && maze[new_r][new_c] > limit) {
                            maze[new_r][new_c] = 0;
                            st.push({new_r, new_c});
                            break;
                        }
                    }
                    if (st.top() == target) st.pop();
                }
            }
        }
    }

    return cnt;    
}

// 어떤 지역의 높이 정보 파악
// 물에 잠기지 않는 안전한 영역의 최대 개수
// 안전한 영역이란 물에 잠기지 않는 이어진 영역(상하좌우)
int solution(int N, vector<vector<int>>& maze) {

    int answer = 1;

    int min_level = maze[0][0];
    int max_level = maze[0][0];

    for (int r = 0; r < N; r++) {
        min_level = min(*min_element(maze[r].begin(), maze[r].end()), min_level);
        max_level = max(*max_element(maze[r].begin(), maze[r].end()), max_level);
    }

    for (int limit = min_level; limit < max_level; limit++) {
        answer = max(count_safe_space(N, maze, limit), answer);
    }

    return answer;
}

int main() {
    int N; cin >> N;
    vector<vector<int>> maze(N, vector<int>(N, 0));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> maze[r][c];
        }
    }

    cout << solution(N, maze) << endl;
}
