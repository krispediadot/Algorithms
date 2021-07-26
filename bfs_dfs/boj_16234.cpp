// 2156 KB, 156ms
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

bool is_valid(vector<vector<int>>& population, pair<int, int> a) {
	return a.first >= 0 && a.first < population.size() && a.second >= 0 && a.second < population.size();
}

bool is_movable(int& a, int& b, int& l, int& r) {
	int gap = abs(a - b);
	if (gap >= l && gap <= r) return true;
	return false;
}

bool movement(vector<vector<int>>& population, int& n, int& L, int& R) {
	bool moved = false;

	const int dirR[] = { -1, 0, 1, 0 }; // 북동남서
	const int dirC[] = { 0, 1, 0, -1 };
	
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	queue<pair<int, int>> q; // {r,  c}
	vector<pair<int, int>> wait; // {r, c}

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (visited[r][c] == false) {
				q.push({ r, c });
				visited[r][c] = true;
				int sum = 0;

				// 열 수 있는 국경 확인
				while (!q.empty()) {
					auto target = q.front(); q.pop();
					wait.push_back(target);

					sum += population[target.first][target.second];

					for (int dir = 0; dir < 4; dir++) {
						int nextR = target.first + dirR[dir];
						int nextC = target.second + dirC[dir];

						// 국경을 열 수 있다면
						if (is_valid(population, { nextR, nextC }) && !visited[nextR][nextC] && is_movable(population[target.first][target.second], population[nextR][nextC], L, R)) {
							q.push({ nextR, nextC });
							visited[nextR][nextC] = true;
						}
					}
				}

				if (wait.size() >= 2) {
					moved = true;

					int avgPopulation = sum / wait.size();

					// 인구 수 업데이트
					for (auto& pos : wait) {
						population[pos.first][pos.second] = avgPopulation;
					}
					
				}
				wait.clear();
			}
		}
	}

	return moved;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	int l, r; cin >> l >> r;
	vector<vector<int>> population(n, vector<int>(n));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++)
			cin >> population[r][c];
	}

	int day = 0;
	
	while (movement(population, n, l, r)) 
		day++;

	cout << day;

	return 0;
}

