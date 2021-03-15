// 등굣길

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 웅덩이를 피해 집에서 학교로 갈 수 있는 최단 경로의 수를 구하시오.
int solution(int m, int n, vector<vector<int>> puddles) {
	const int PUDDLE = 0;

	// 0. 디폴트 1로 지정
	vector<vector<int>> paths(n + 1, vector<int>(m + 1, 1));

	// 1. 웅덩이 0로 지정
	for (auto target : puddles) paths[target[1]][target[0]] = PUDDLE;

	// 2. 패딩 위치 0으로 지정
	for (int r = 0; r <= n; r++) paths[r][0] = 0;
	for (int c = 0; c <= m; c++) paths[0][c] = 0;

	// 3. 좌표를 z로 이동하며 값 업데이트
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= m; c++) {
			if (r == 1 && c == 1) continue;
			if (paths[r][c] != PUDDLE) {
				paths[r][c] = (paths[r - 1][c] + paths[r][c - 1]) % 1000000007;
			}
		}
	}

	return paths[n][m];
}

int main()
{
	cout << solution(4, 3, {{2, 2}}) << endl; // 4
	cout << solution(4, 3, {{1, 2}}) << endl; // 6
}

