#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dirR[] = {-1, 0, 1, 0}; // 북동남서
const int dirC[] = {0, 1, 0, -1};

int R, C, T;
vector<vector<int>> arr;
int bot = 0;

void spread() {

    auto is_valid = [](int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C; 
    };

    vector<vector<int>> temp(R, vector<int>(C, 0));

    for (int r = 0; r < R; r++) {
        for (int c = 0 ;c < C; c++) {
            if (arr[r][c] > 0) {
                int sub = arr[r][c] / 5;
                int cnt = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int next_r = r + dirR[dir];
                    int next_c = c + dirC[dir];

                    if (is_valid(next_r, next_c) && arr[next_r][next_c] != -1) {
                        temp[next_r][next_c] += sub;
                        cnt++;
                    }
                }
                arr[r][c] -= (sub * cnt);
            }
        }
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            arr[r][c] += temp[r][c];
        }
    }
}

void counter_clockwise(int bot_r) {
    // 좌
    for (int r = bot_r - 1 ; r > 0; r--) {
        arr[r][0] = arr[r - 1][0];
    }
    // 상
    for (int c = 0; c < C - 1; c++) {
        arr[0][c] = arr[0][c + 1];
    }
    // 우
    for (int r = 0; r < bot_r ; r++) {
        arr[r][C - 1] = arr[r + 1][C - 1];
    }
    // 하
    for (int c = C - 1; c > 1; c--) {
        arr[bot_r][c] = arr[bot_r][c - 1];
    }
    arr[bot_r][1] = 0;
} 

void clockwise(int bot_r) {
    // 좌
    for (int r = bot_r + 1; r < R - 1; r++) {
        arr[r][0] = arr[r + 1][0];
    }
    // 하
    for (int c = 0; c < C - 1; c++) {
        arr[R - 1][c] = arr[R - 1][c + 1];
    }
    // 우
    for (int r = R - 1 ; r > bot_r; r--) {
        arr[r][C - 1] = arr[r - 1][C - 1];
    }
    // 상
    for (int c = C - 1; c > 1; c--) {
        arr[bot_r][c] = arr[bot_r][c - 1];
    }
    arr[bot_r][1] = 0;
} 

int solution() {
    while (T--) {
        // 1. 확산
        spread();

        // 2. 순환
        counter_clockwise(bot);
        clockwise(bot + 1);
    }

    // 3. 남은양 계산
    int answer = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (arr[r][c] > 0) answer += arr[r][c];
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> T;
    arr.resize(R, vector<int> (C, 0));
    bot = R + 1;
    
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> arr[r][c];
            if (arr[r][c] == -1 && bot == R + 1) bot = r;
        }
    }

    cout << solution() << endl;

}
