#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> patch(6, 5);
vector<vector<int>> paper(10, vector<int>(10, 0));
int spot = 0;
int answer = 0;

bool add_patch(int cur_r, int cur_c, int idx) {
    vector<vector<int>> paper_copy = paper;
    for (int r = cur_r; r < cur_r + idx; r++) {
        for (int c = cur_c; c < cur_c + idx; c++) {
            if (paper[r][c] == 0) return false;
            paper_copy[r][c] = 0;
        }
    }
    paper = paper_copy;
    return true;
}

void remove_patch(int cur_r, int cur_c, int idx) {
    for (int r = cur_r; r < cur_r + idx; r++) {
        for (int c = cur_c; c < cur_c + idx; c++) {
            paper[r][c] = 1;
        }
    }
}

// 종이가 주어졌을 때 필요한 색종이의 최소 개수
void solution(int cur_r, int cur_c, int cnt) {
    if (cnt > answer) return;
    if (spot == 0) {
        answer = min(answer, cnt);
        return;
    }

    int r = cur_r;
    int c = cur_c;

    while (paper[r][c] == 0) {
        c++;
        if (c >= 10) {
            c = 0;
            r++;
        }
    }

    for (int idx = 5; idx >= 1; idx--) {
        if (patch[idx] <= 0) continue;

        if (r + idx <= 10 && c + idx <= 10 && add_patch(r, c, idx)) {
            patch[idx]--;
            spot -= (idx * idx);

            solution(r, c, cnt + 1);

            remove_patch(r, c, idx);
            spot += (idx * idx);
            patch[idx]++;
        }
    }
}

int main() {
    for (int r = 0; r < 10; r++) {
        for (int c = 0; c < 10; c++) {
            cin >> paper[r][c];
            
            if (paper[r][c] == 1) spot++;
        }
    }

    if (spot > 0) {
        answer = INT_MAX;
        solution(0, 0, 0);
    }

    if (answer == INT_MAX) cout << -1 << endl;
    else cout << answer << endl;

    return 0;
}
