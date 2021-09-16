// 2156 KB,	60ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BLANK = 0;
const int WALL = 6;
const int VISITED = -1;

const int dirR[] = { -1, 0, 1, 0 };
const int dirC[] = { 0, 1, 0, -1 };

const vector<int> CCTV[] = { {},
							 {1},
							 {1, 3},
							 {0, 1},
							 {0, 1, 3},
							 {0, 1, 2, 3}};

bool isValid(vector<vector<int>>& board, pair<int, int>& a) {
	return a.first >= 0 && a.first < board.size() && a.second >= 0 && a.second < board[0].size() && board[a.first][a.second] != WALL;
}

int detect(vector<vector<int>>& board, pair<int, int> cur, int dir) {
	int cnt = 0;

	while (isValid(board, cur)) {
		if (board[cur.first][cur.second] == BLANK) {
			cnt++;
			board[cur.first][cur.second] = VISITED;
		}

		cur.first += dirR[dir];
		cur.second += dirC[dir];
	}

	return cnt;
}

void check(vector<vector<int>> board, vector<pair<int, int>>& cctvList, int targetIdx, int cntBlank, int& answer) {
	if (targetIdx == cctvList.size()) {
		answer = min(cntBlank, answer);
		return;
	}

	auto& target = cctvList[targetIdx];
	int& cctvType = board[target.first][target.second];
	auto& cctvDir = CCTV[cctvType];

	for (int dir = 0; dir < 4; dir++) {
		if ((cctvType == 2 && dir > 1) || (cctvType == 5 && dir > 0)) break;

		vector<vector<int>> board_copy = board;
		int leftBlank = cntBlank;
		for (auto& d : cctvDir) {
			int targetDir = (d + dir) % 4;
			
			leftBlank -= detect(board_copy, target, targetDir);
		}

		check(board_copy, cctvList, targetIdx + 1, leftBlank, answer);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M; cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<pair<int, int>> cctvList;
	int cntBlank = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == BLANK) cntBlank++;
			if (board[i][j] != BLANK && board[i][j] != WALL) cctvList.push_back({ i, j });
		}
	}
	
	int answer = cntBlank;
	check(board, cctvList, 0, cntBlank, answer);

	cout << answer << '\n';

	return 0;
}
