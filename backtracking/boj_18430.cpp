// 2156 KB, 280ms
#include <iostream>
#include <vector>

using namespace std;

const int dirR[] = {-1, 0, 1, 0};
const int dirC[] = {0, 1, 0, -1};

bool isValid(pair<int, int> pos, int& n, int& m) {
    return pos.first >= 0 && pos.first < n && pos.second >= 0 && pos.second < m;
}

void makeCurve(vector<vector<int>>& plate, vector<vector<bool>> used, int& n, int& m, pair<int, int> pos, int& answer, int sum) {

    if (pos.first >= n) {
        if (sum > answer) answer = sum;
        return;
    }

    pair<int, int> next = pos;
    next.second++;
    if (next.second == m) {
        next.second = 0;
        next.first++;
    }

    if (used[pos.first][pos.second] == false) {
        used[pos.first][pos.second] = true;

        for (int dir = 0; dir < 4; dir++) {
            pair<int, int> pos1 = {pos.first + dirR[dir], pos.second + dirC[dir]};
            pair<int, int> pos2 = {pos.first + dirR[(dir+1)%4], pos.second + dirC[(dir+1)%4]};

            if (isValid(pos1, n, m) && isValid(pos2, n, m) && used[pos1.first][pos1.second] == false && used[pos2.first][pos2.second] == false) {
                
                used[pos1.first][pos1.second] = true;
                used[pos2.first][pos2.second] = true;
                
                int hardness = (plate[pos.first][pos.second]) * 2 + plate[pos1.first][pos1.second] + plate[pos2.first][pos2.second];

                makeCurve(plate, used, n, m, next, answer, sum + hardness);

                used[pos1.first][pos1.second] = false;
                used[pos2.first][pos2.second] = false;
            }
        }

        used[pos.first][pos.second] = false;
    }

    makeCurve(plate, used, n, m, next, answer, sum);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<vector<int>> plate(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> plate[i][j];
        }
    }

    vector<vector<bool>> used(n, vector<bool>(m, false));
    int answer = 0;
    makeCurve(plate, used, n, m, {0, 0}, answer, 0);

    cout << answer;

    return 0;
}
