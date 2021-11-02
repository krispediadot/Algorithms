// 2020 KB, 76ms

// BEST VERSION

#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int row[9][10];
int col[9][10];
int box[9][10];

void solution(int idx) {

    if (idx == 81) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    pair<int, int> pos = {idx / 9, idx % 9};

    if (board[pos.first][pos.second] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!row[pos.first][i] && !col[pos.second][i] && !box[(pos.first / 3)*3 + pos.second / 3][i]) {
                board[pos.first][pos.second] = i;
                row[pos.first][i] = true;
                col[pos.second][i] = true;
                box[(pos.first / 3)*3 + pos.second / 3][i] = true;
                solution(idx+1);
                box[(pos.first / 3)*3 + pos.second / 3][i] = false;
                col[pos.second][i] = false;
                row[pos.first][i] = false;
                board[pos.first][pos.second] = 0;
            }
        }       
    }
    else solution(idx+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] != 0) {
                row[r][board[r][c]] = true;
                col[c][board[r][c]] = true;
                box[(r/3)*3 + c/3][board[r][c]] = true;
            }
        }
    }

    solution(0);

    return 0;
}

// 시도한 과정
// 2024 KB, 288ms

/*
1번째 시도.

비어있는 칸 따로 저장
가로, 세로, 3x3정사각주변의 수 확인
사용하지 않은 수 하나씩 선택하며 확인 
*/

#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<vector<int>>& board, vector<pair<int, int>>& blank, int idx) {

    if (idx >= blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    pair<int, int>& pos = blank[idx];

    bool done = false;

    vector<bool> candidate(10, true);

    // row
    for (int r = 0; r < 9; r++) candidate[board[r][pos.second]] = false;
    // col
    for (int c = 0; c < 9; c++) candidate[board[pos.first][c]] = false;
    // square
    pair<int, int> init = {int(pos.first / 3)*3, int(pos.second / 3)*3};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            candidate[board[init.first + r][init.second + c]] = false;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (candidate[i] == true) {
            board[pos.first][pos.second] = i;
            done |= solution(board, blank, idx+1);
            board[pos.first][pos.second] = 0;
        }

        if (done) break;
    }

    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board(9, vector<int>(9));
    vector<pair<int, int>> blank;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
        }
    }

    solution(board, blank, 0);

    return 0;
}
// 2024 KB, 280ms

/*
2번째 시도.

비어있는 칸 따로 저장
가로, 세로, 3x3정사각주변의 수 확인 -> 가로세로 for 중복 제거
사용하지 않은 수 하나씩 선택하며 확인 
*/

#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<vector<int>>& board, vector<pair<int, int>>& blank, int idx) {

    if (idx == blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    pair<int, int>& pos = blank[idx];

    bool done = false;

    vector<bool> candidate(10, true);

    // row & col
    for (int r = 0; r < 9; r++) {
        candidate[board[r][pos.second]] = false;
        candidate[board[pos.first][r]] = false;
    }
    // square
    pair<int, int> init = {int(pos.first / 3)*3, int(pos.second / 3)*3};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            candidate[board[init.first + r][init.second + c]] = false;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (candidate[i] == true) {
            board[pos.first][pos.second] = i;
            done |= solution(board, blank, idx+1);
            board[pos.first][pos.second] = 0;
        }

        if (done) break;
    }

    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board(9, vector<int>(9));
    vector<pair<int, int>> blank;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
        }
    }

    solution(board, blank, 0);

    return 0;
}
// 2024 KB, 280ms

/*
3번째 시도.

비어있는 칸 따로 저장
가로, 세로, 3x3정사각주변의 수 확인 -> 가로세로 for 중복 제거
사용하지 않은 수 하나씩 선택하며 확인 

정답 출력 후 `return true` --> `exit(0)`으로 변경
*/

#include <iostream>
#include <vector>

using namespace std;

bool solution(vector<vector<int>>& board, vector<pair<int, int>>& blank, int idx) {

    if (idx == blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    pair<int, int>& pos = blank[idx];

    bool done = false;

    vector<bool> candidate(10, true);

    // row & col
    for (int r = 0; r < 9; r++) {
        candidate[board[r][pos.second]] = false;
        candidate[board[pos.first][r]] = false;
    }
    // square
    pair<int, int> init = {int(pos.first / 3)*3, int(pos.second / 3)*3};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            candidate[board[init.first + r][init.second + c]] = false;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (candidate[i] == true) {
            board[pos.first][pos.second] = i;
            done |= solution(board, blank, idx+1);
            board[pos.first][pos.second] = 0;
        }

        if (done) break;
    }

    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<int>> board(9, vector<int>(9));
    vector<pair<int, int>> blank;
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
        }
    }

    solution(board, blank, 0);

    return 0;
}
// 2020 KB, 264ms

/*
4번째 시도.


비어있는 칸 따로 저장
가로, 세로, 3x3정사각주변의 수 확인 -> 가로세로 for 중복 제거
사용하지 않은 수 하나씩 선택하며 확인 

입력 배열 vector -> array 변경 및 전역변수로 변경
비어있는 칸 저장 vector 전역변수로 변경
*/

#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<pair<int, int>> blank;

bool solution(int idx) {

    if (idx == blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    pair<int, int>& pos = blank[idx];

    bool done = false;

    vector<bool> candidate(10, true);

    // row & col
    for (int r = 0; r < 9; r++) {
        candidate[board[r][pos.second]] = false;
        candidate[board[pos.first][r]] = false;
    }
    // square
    pair<int, int> init = {int(pos.first / 3)*3, int(pos.second / 3)*3};

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            candidate[board[init.first + r][init.second + c]] = false;
        }
    }

    for (int i = 1; i <= 9; i++) {
        if (candidate[i] == true) {
            board[pos.first][pos.second] = i;
            done |= solution(idx+1);
            board[pos.first][pos.second] = 0;
        }

        if (done) break;
    }

    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
        }
    }

    solution(0);

    return 0;
}
// 2020 KB, 104ms

/*
5번째 시도.


비어있는 칸 따로 저장
사용하지 않은 수 하나씩 선택하며 확인 
입력 배열 vector -> array 변경 및 전역변수로 변경
비어있는 칸 저장 vector 전역변수로 변경

가로, 세로, 3x3 정사각 주변 확인용 array 전역변수 선언
*/


#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int row[9][10];
int col[9][10];
int box[9][10];
vector<pair<int, int>> blank;

bool solution(int idx) {

    if (idx == blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        return true;
    }

    pair<int, int>& pos = blank[idx];
    bool done = false;

    for (int i = 1; i <= 9; i++) {
        if (!row[pos.first][i] && !col[pos.second][i] && !box[(pos.first / 3)*3 + pos.second / 3][i]) {
            board[pos.first][pos.second] = i;
            row[pos.first][i] = true;
            col[pos.second][i] = true;
            box[(pos.first / 3)*3 + pos.second / 3][i] = true;
            done |= solution(idx+1);
            box[(pos.first / 3)*3 + pos.second / 3][i] = false;
            col[pos.second][i] = false;
            row[pos.first][i] = false;
            board[pos.first][pos.second] = 0;
        }

        if (done) break;
    }

    return done;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
            else {
                row[r][board[r][c]] = true;
                col[c][board[r][c]] = true;
                box[(r/3)*3 + c/3][board[r][c]] = true;
            }
        }
    }

    solution(0);

    return 0;
}
// 2020 KB, 96ms

/*
6번째 시도.


비어있는 칸 따로 저장
사용하지 않은 수 하나씩 선택하며 확인 
입력 배열 vector -> array 변경 및 전역변수로 변경
비어있는 칸 저장 vector 전역변수로 변경
가로, 세로, 3x3 정사각 주변 확인용 array 전역변수 선언

정답 출력 후 `return true` --> `exit(0)`으로 변경
solution 함수 리턴값 void로 변경
*/


#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int row[9][10];
int col[9][10];
int box[9][10];
vector<pair<int, int>> blank;

void solution(int idx) {

    if (idx == blank.size()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    pair<int, int>& pos = blank[idx];

    for (int i = 1; i <= 9; i++) {
        if (!row[pos.first][i] && !col[pos.second][i] && !box[(pos.first / 3)*3 + pos.second / 3][i]) {
            board[pos.first][pos.second] = i;
            row[pos.first][i] = true;
            col[pos.second][i] = true;
            box[(pos.first / 3)*3 + pos.second / 3][i] = true;
            solution(idx+1);
            box[(pos.first / 3)*3 + pos.second / 3][i] = false;
            col[pos.second][i] = false;
            row[pos.first][i] = false;
            board[pos.first][pos.second] = 0;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) blank.push_back({r, c});
            else {
                row[r][board[r][c]] = true;
                col[c][board[r][c]] = true;
                box[(r/3)*3 + c/3][board[r][c]] = true;
            }
        }
    }

    solution(0);

    return 0;
}
// 2020 KB, 76ms

/*
7번째 시도.


사용하지 않은 수 하나씩 선택하며 확인 
입력 배열 vector -> array 변경 및 전역변수로 변경
비어있는 칸 저장 vector 전역변수로 변경
가로, 세로, 3x3 정사각 주변 확인용 array 전역변수 선언
정답 출력 후 `return true` --> `exit(0)`으로 변경
solution 함수 리턴값 void로 변경

비어있는 칸 저장하는 vector 제거
solution 함수의 파라미터가 위치r x 위치c 를 나타내도록 변경
즉, 전체 위치를 확인하는 방식으로 변경
*/

#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
int row[9][10];
int col[9][10];
int box[9][10];

void solution(int idx) {

    if (idx == 81) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        exit(0);
    }

    pair<int, int> pos = {idx / 9, idx % 9};

    if (board[pos.first][pos.second] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (!row[pos.first][i] && !col[pos.second][i] && !box[(pos.first / 3)*3 + pos.second / 3][i]) {
                board[pos.first][pos.second] = i;
                row[pos.first][i] = true;
                col[pos.second][i] = true;
                box[(pos.first / 3)*3 + pos.second / 3][i] = true;
                solution(idx+1);
                box[(pos.first / 3)*3 + pos.second / 3][i] = false;
                col[pos.second][i] = false;
                row[pos.first][i] = false;
                board[pos.first][pos.second] = 0;
            }
        }       
    }
    else solution(idx+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] != 0) {
                row[r][board[r][c]] = true;
                col[c][board[r][c]] = true;
                box[(r/3)*3 + c/3][board[r][c]] = true;
            }
        }
    }

    solution(0);

    return 0;
}

