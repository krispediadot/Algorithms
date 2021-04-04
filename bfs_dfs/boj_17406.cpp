#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K; 
vector<vector<int>> arr;
vector<vector<int>> ops;

void compare_answer(int& answer, vector<vector<int>>& arr_copy) {
    for (int r = 1; r <= N; r++) {
        int r_sum = 0;
        for (int c = 1; c <= M; c++) {
            r_sum += arr_copy[r][c];
        }

        answer = min(answer, r_sum);
    }
}

// 회전 연산 적용
void apply_op(int& answer) {
    vector<vector<int>> arr_copy = arr;

    for (auto op : ops) {

        int r = op[0];
        int c = op[1];
        int s = op[2];
        int side_length = 2 * s + 1;

        pair<int, int> bottom_right{r + s, c + s};
        pair<int, int> point {r - s, c - s};
        while (side_length > 1) {
            
            // 반시계 방향으로 확인하며 값 당기기
            int temp = arr_copy[point.first][point.second];
            for (int r = point.first; r < bottom_right.first; r++) {
                arr_copy[r][point.second] = arr_copy[r + 1][point.second];
            }
            for (int c = point.second; c < bottom_right.second; c++) {
                arr_copy[bottom_right.first][c] = arr_copy[bottom_right.first][c + 1];
            }
            for (int r = bottom_right.first; r > point.first; r--) {
                arr_copy[r][bottom_right.second] = arr_copy[r - 1][bottom_right.second];
            }
            for (int c = bottom_right.second; c > point.second; c--) {
                arr_copy[point.first][c] = arr_copy[point.first][c - 1];
            }
            arr_copy[point.first][point.second + 1] = temp;

            side_length -= 2;
            point.first += 1;
            point.second += 1;
            bottom_right.first -= 1;
            bottom_right.second -= 1;
    
        }
    }
    compare_answer(answer, arr_copy);
}

// 모든 가능성 확인
int solution() {
    int answer = 50 * 50 * 100;

    sort(ops.begin(), ops.end());
    do {
        apply_op(answer);
    } while(next_permutation(ops.begin(), ops.end()));

    return answer;
}

int main() {
    cin >> N >> M >> K;

    arr.resize(N + 1, vector<int>(M + 1, 0));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            cin >> arr[r][c];
        }
    }

    ops.resize(K, vector<int>(3, 0));
    for (int i = 0; i < K; i++) {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
    }

    cout << solution() << endl;
    
    return 0;
}
