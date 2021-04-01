#include <iostream>
#include <vector>

using namespace std;

const int WALL = 1;
const int dirR[] {0, 1, 1}; //동, 남, 동남
const int dirC[] {1, 0, 1};
using p = pair<pair<int, int>, int>; // point1, dir

vector<vector<int>> maze;
int n; 

bool is_valid(pair<int, int> location) {
    return location.first >= 0 && location.first < n && location.second >= 0 && location.second < n;
}
void count_solutions(p cur, int& answer) {
    pair<int, int> point1 = cur.first;
    int cur_dir = cur.second;

    // 도착하면 끝!
    if (point1.first == n - 1 && point1.second == n - 1) {
        answer++;
        return;
    }

    // 대각선 이동 시 이동 가능한지 확인하기 위해 필요 
    vector<bool> movable(3, false);
    for (int dir = 0; dir < 3; dir++) {
        int next_r = point1.first + dirR[dir];
        int next_c = point1.second + dirC[dir];

        if (is_valid({next_r, next_c}) && maze[next_r][next_c] != WALL)
            movable[dir] = true;

        // 가로로 놓여있다면 남쪽으로 못감
        if (cur_dir == 0 && dir == 1) continue;
        
        // 세로로 놓여있다면 동쪽으로 못감
        if (cur_dir == 1 && dir == 0) continue;

        // 대각선으로 이동하려면 동,남,동남 모두 이동 가능해야함.
        if (dir == 2){
            if (movable[0] && movable[1] && movable[2]) count_solutions({{next_r, next_c}, dir}, answer);
        }
        // 대각선 외 각자 방향만 이동 가능하면 됨.
        else {
            if (movable[dir]) count_solutions({{next_r, next_c}, dir}, answer);
        }
    }
}

int solution() {
    int answer = 0;
    p pipe {{0, 1}, 0};

    count_solutions(pipe, answer);

    return answer;
}

int main() {
    cin >> n;
    for (int r = 0; r < n; r++) {
        vector<int> temp;
        for (int c = 0; c < n; c++) {
            int num; cin >> num;
            temp.push_back(num);
        }
        maze.push_back(temp);
    }

    cout << solution() << endl;
}
