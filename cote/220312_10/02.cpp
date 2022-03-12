#include <string>
#include <vector>

using namespace std;

const int dirR[] = {0, 1, 0, -1}; // 동남서북
const int dirC[] = {1, 0, -1, 0};

vector<vector<int>> solution(int n, bool clockwise) {
    vector<vector<int>> answer(n, vector<int>(n, 0));

    vector<pair<int, int>> p(4);
    vector<int> dir(4);

    if (clockwise) { 
        p = {{0, 0}, {0, n-1}, {n-1, n-1}, {n-1, 0}};
        dir = {0, 1, 2, 3};
    }
    else {
        p = {{0, n-1}, {0, 0}, {n-1, 0}, {n-1, n-1}};
        dir = {2, 1, 0, 3};       
    }

    for (auto target : p) {
        answer[target.first][target.second] = 1;
    }

    bool done = false;
    int move = n - 2;

    while (done == false) {
        for (int idx = 0; idx < 4; idx++) {
            pair<int, int>& target = p[idx];
            int& tdir = dir[idx];

            int nextR = target.first + dirR[tdir];
            int nextC = target.second + dirC[tdir];

            for (int m = 0; m < move; m++) {
                if (!done && nextR == int(n/2) && nextC == int(n/2)) done = true;

                answer[nextR][nextC] = answer[target.first][target.second] + 1;
                target = {nextR, nextC};
                nextR = target.first + dirR[tdir];
                nextC = target.second + dirC[tdir];
            }

            if (clockwise) tdir++;
            else tdir--;

            tdir = (tdir+4) % 4;
        }
        if (move == n-2 || move == 2) move--;
        else move -= 2;
    }

    return answer;
}
