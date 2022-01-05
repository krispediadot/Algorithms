// 2152 KB, 0ms
#include <iostream>
#include <vector>

using namespace std;

const int WHITE = 0;

bool isSame(vector<vector<int>>& paper, pair<int, int> start, int n) {
    int base = paper[start.first][start.second];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (paper[start.first + r][start.second + c] != base) return false;
        }
    }
    return true;
}

void solution(vector<vector<int>>& paper, pair<int, int> start, int n, int& cntW, int& cntB) {
    if (isSame(paper, start, n)) {
        if (paper[start.first][start.second] == WHITE) cntW++;
        else cntB++;
        return;
    }

    // 1. 
    solution(paper, start, n/2, cntW, cntB);
    // 2.
    solution(paper, {start.first, start.second + n/2}, n/2, cntW, cntB);
    // 3
    solution(paper, {start.first + n/2, start.second}, n/2, cntW, cntB);
    // 4
    solution(paper, {start.first + n/2, start.second + n/2}, n/2, cntW, cntB);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> paper(n, vector<int>(n));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> paper[r][c];
        }
    }

    int cntW = 0, cntB = 0;

    solution(paper, {0,0}, n, cntW, cntB);

    cout << cntW << '\n' << cntB << '\n';

    return 0;
}
