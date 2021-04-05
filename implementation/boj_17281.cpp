#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 9명으로 이루어진 두 팀 공격, 수비
// 하나의 이닝 = 공격 , 수비
// 총 N 이닝동안 게임 진행
// 한 이닝에서 3아웃이면 종료 & 두 팀이 공격과 수비를 서로 바꿈
// 타순은 경기 시작전에만 정할 수 있음
// 타순은 이닝이 끝나도 계속 연결됨
// 야구
// 1번 선수는 4번 타자
// 나머지 선수의 타순 선택

const int PLAYER_TOTAL = 9;

int N;
vector<vector<int>> player_info; // [round_idx][player_idx] = stat

int play(vector<int>& lineup) {
    int score = 0;
    int lineup_idx = 0;
    
    for (int round_idx = 0; round_idx < N; round_idx++) {
        vector<int> doru;
        int out_cnt = 0;

        while (out_cnt < 3) {
            // 1. 선수가 공 치기
            int player_idx = lineup[lineup_idx];
            int stat = player_info[round_idx][player_idx];

            // 2. 아웃이면 끝
            if (stat == 0) out_cnt++;

            // 3. 아웃이 아니면 이동
            else {

                // 4. 출루해있던 선수들 움직이기
                while (doru.size() > 0 && doru.front() + stat > 3) {
                    doru.erase(doru.begin());
                    score++;
                }

                for (int idx = 0; idx < doru.size(); idx++)
                    doru[idx] += stat;

                // 5. 홈런이면 점수 추가
                if (stat == 4) score++;

                // 6. 홈런 아니면 출루
                else doru.push_back(stat);
            }

            // 7. 다음 선수 대기
            lineup_idx = (lineup_idx + 1) % PLAYER_TOTAL;
        }
    }

    return score;
}

void solution(vector<int> lineup, vector<bool> done, int& answer) {
    if (lineup.size() == PLAYER_TOTAL) {
        answer = max(answer, play(lineup));
        return;
    }

    if (lineup.size() == 3) {
        lineup.push_back(0);
        solution(lineup, done, answer);
        lineup.pop_back();
    }
    
    else {
        for (int idx = 1; idx < PLAYER_TOTAL; idx++) {
            if (done[idx] == false) {
                lineup.push_back(idx);
                done[idx] = true;
                solution(lineup, done, answer);
                done[idx] = false;
                lineup.pop_back();
            }
        }
    }
}

int main() {
    cin >> N;

    player_info.resize(N, vector<int>(PLAYER_TOTAL, 0));
    for (int round_idx = 0; round_idx < N; round_idx++) {
        for (int player_idx = 0; player_idx < PLAYER_TOTAL; player_idx++) {
            cin >> player_info[round_idx][player_idx];
        }
    }

    int answer = 0;
    vector<int> lineup;
    vector<bool> done(PLAYER_TOTAL, false);

    solution(lineup, done, answer);
    cout << answer << endl;
    
    return 0;
}
