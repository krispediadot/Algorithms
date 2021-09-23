// 	2160 KB, 0ms
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int ROAD = 0;
const int BLOCK = 1;
const vector<vector<pair<int, int>>> NEAR = { {{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0}},
											  {{-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, 1}} };

bool isValid(pair<int, int>& pos, int& H, int& W) {
	return pos.first >= 0 && pos.first <= H+1 && pos.second >= 0 && pos.second <= W+1;
}

int check(vector<vector<int>>& board, vector<vector<bool>>& visited, int& H, int& W, pair<int, int> start) {
	int cnt = 0;
	queue<pair<int, int>> q;
	visited[start.first][start.second] = true;
	q.push({ start.first, start.second });

	while (!q.empty()) {
		auto target = q.front(); q.pop();
		vector<pair<int, int>> near = NEAR[target.first % 2]; // 행의 홀/짝에 따라 주변 노드가 달라짐

		for (int i = 0; i < 6; i++) {
			pair<int, int> pos = { target.first + near[i].first, target.second + near[i].second };
			if (isValid(pos, H, W)) {
				cnt += board[pos.first][pos.second];
				if (board[pos.first][pos.second] == ROAD && visited[pos.first][pos.second] == false) {
					visited[pos.first][pos.second] = true;
					q.push(pos);
				}
			}
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int W, H; cin >> W >> H;
	vector<vector<int>> board(H + 2, vector<int>(W + 2));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<bool>> visited(H + 2, vector<bool>(W + 2, false));
	int answer = 0;

	answer += check(board, visited, H, W, { 0,0 });

	cout << answer << '\n';

	return 0;
}
