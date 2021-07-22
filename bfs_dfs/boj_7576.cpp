//12496 KB, 88ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int ROTTEN = 1;
const int RAW = 0;
const int BLANK = -1;

using qItem = pair<pair<int, int>, int>; // {{row, column}, day}

// 며칠이 지나면 토마토들이 모두 익는지, 최소 일수
int solution(vector<vector<int>>& bucket, queue<qItem>& q, int& cntRaw, int& cntBlank, int& N, int& M) {

	const int dirR[] = { -1, 0, 1, 0 }; //북동남서
	const int dirC[] = { 0, 1, 0, -1 };

	auto is_valid = [&](pair<int, int> a) {
		return a.first >= 0 && a.first < N && a.second >= 0 && a.second < M;
	};

	int lastDay = 0;

	// 1. 제약사항 확인 (모두 안익은 토마토 이거나 빈칸이면 -1 출력 / 처음부터 모두 익어있으면 0 출력)
	if ((cntRaw + cntBlank) == (N * M)) return -1;
	if (q.empty()) return 0;

	// 2. 큐에서 토마토 위치 확인하며 주변 토마토 익게 만들기
	while (!q.empty()) {

		auto target = q.front(); q.pop(); // target = {row, column}
		int day = target.second;

		lastDay = max(lastDay, day);

		// 2-1. 주변 토마토 확산
		for (int dir = 0; dir < 4; dir++) {
			int nextR = target.first.first + dirR[dir];
			int nextC = target.first.second + dirC[dir];

			if (is_valid({ nextR, nextC }) && bucket[nextR][nextC] == RAW) {
				bucket[nextR][nextC] = ROTTEN;
				cntRaw--;

				q.push({ { nextR, nextC }, day + 1 });
			}
		}
	}

	// 3. 제약사항 확인 후 리턴(토마토가 모두 익지 못하면 -1 출력)
	if (cntRaw != 0) return -1;
	return lastDay;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> M >> N;
	vector<vector<int>> bucket(N, vector<int>(M));
	queue<qItem> q;
	int cntRaw = 0;
	int cntBlank = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> bucket[i][j];
			if (bucket[i][j] == ROTTEN) q.push({ { i,j }, 0 });
			if (bucket[i][j] == RAW) cntRaw++;
			if (bucket[i][j] == BLANK) cntBlank++;
		}
	}

	cout << solution(bucket, q, cntRaw, cntBlank, N, M);

	return 0;
}
