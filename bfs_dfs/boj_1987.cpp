// 2020 KB, 928ms
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dirR[] = {-1, 0, 1, 0}; //북동남서
const int dirC[] = {0, 1, 0, -1};
int R, C; 

bool is_valid(pair<int, int> pos) {
	return pos.first >= 0 && pos.first < R && pos.second >= 0 && pos.second < C;
}

void solution(vector<vector<char>>& board, vector<bool>& visited, pair<int, int> pos, int steps, int& answer) {
	answer = max(answer, steps);

	for (int dir = 0; dir < 4; dir++) {
		int nextR = pos.first + dirR[dir];
		int nextC = pos.second + dirC[dir];

		if (is_valid({nextR, nextC}) && visited[board[nextR][nextC] - 'A'] == false) {
			visited[board[nextR][nextC] - 'A'] = true;
			solution(board, visited, {nextR, nextC}, steps + 1, answer);
			visited[board[nextR][nextC] - 'A'] = false;
		}
	}
}

int main() {
	cin >> R >> C;
	vector<vector<char>> board(R, vector<char>(C));
	vector<bool> visited(26, false);
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++)
			cin >> board[r][c];
	}

	visited[board[0][0] - 'A'] = true;
	int answer = 0;
	solution(board, visited, {0, 0}, 1, answer);

	cout << answer;

	return 0;
}
