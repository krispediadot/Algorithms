#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

void print_box (vector<vector<vector<int>>>& box) {
    for (auto& h : box) {
        for (auto& c : h) {
            for (auto& r : c) 
                cout << r << " ";
            cout << endl;
        }
        cout << endl;
    }
}

// 보관 후 하루가 지나면 익은 토마토들의 인접한곳에 익지 않은 토마토는 익는다.
// 인접한 곳 = 위/아래/왼/오/앞/뒤 6방향 대각선은 제외
// 며칠 있으면 다 익는가? 최소 
// 처음부터 모두 다 익어있으면 0, 모두 익지 못하면 -1
int solution(int N, int M, int H, vector<vector<vector<int>>>& box) {

    const int ROTTEN = 1;
    const int UNROTTEN = 0;
    //const int EMPTY = -1;

    const int dirR[] {0, 0, 0, 0, 1, -1}; // 위/아래/왼/오/앞/뒤
    const int dirC[] {0, 0, -1, 1, 0, 0};
    const int dirH[] {-1, 1, 0, 0, 0, 0};

    auto is_valid = [&](int new_h, int new_c, int new_r) {
        return new_h >= 0 && new_h < H && new_c >= 0 && new_c < M && new_r >= 0 && new_r < N;
    };

    // 1. 아직 익지 않은 토마토 개수 세기
    int unrotten_cnt = 0;

    using loc = tuple<int, int, int>;

    queue<pair<loc, int>> q;
    
    // 2. 현재 익어있는 토마토 부터 시작
    for (int h = 0; h < H; h++) {
        for (int c = 0; c < M; c++) {
             for (int r = 0; r < N; r++) {
                if (box[h][c][r] == ROTTEN) q.push({{h, c, r}, 0});
                if (box[h][c][r] == UNROTTEN) unrotten_cnt++;
            }
        }
    }

    int days = 0;

    while (!q.empty()) {
        //print_box(box);
        
        auto target = q.front(); q.pop();
        loc location = target.first;
        days = target.second;

        if (unrotten_cnt == 0) continue;

        // 3. 주변 토마토 익히기
        for (int dir = 0; dir < 6; dir++) {
            int new_h = get<0>(location) + dirH[dir];
            int new_c = get<1>(location) + dirC[dir];
            int new_r = get<2>(location) + dirR[dir];

            if (is_valid(new_h, new_c, new_r) && box[new_h][new_c][new_r] == UNROTTEN) {
                box[new_h][new_c][new_r] = ROTTEN;
                q.push({{new_h, new_c, new_r}, days + 1});
                unrotten_cnt--;
            }
        }
    }

    if (unrotten_cnt > 0) return -1;
    return days;
}

int main() {
    int N, M, H; cin >> N >> M >> H; // 세로, 가로, 높이
    
    vector<vector<vector<int>>> box(H, vector<vector<int>>(M, vector<int>(N, 0)));
    for (int h = 0; h < H; h++) {
        for (int c = 0; c < M; c++) {
             for (int r = 0; r < N; r++) {
                cin >> box[h][c][r];
            }
        }
    }

    cout << solution(N, M, H, box) << endl;
}
