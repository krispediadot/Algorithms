// 2024MB, 0ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	using info = pair<pair<int, int>, int>;
	
	// 1. 입력 받기
	int N, D; cin >> N >> D;
	vector<int> minDist(D + 1, D);
	vector<info> shortcuts;

	while (N--) {
		int from, to, dist; cin >> from >> to >> dist;

		shortcuts.push_back({ {from, to}, dist });
	}

	// 2. 정렬하기
	auto cmp = [](info& a, info& b) {
		if (a.first.first == b.first.first) {
			if (a.first.second == b.first.second)
				return a.second < b.second;
			return a.first.second < b.first.second;
		}
		return a.first.first < b.first.first;
	};

	sort(shortcuts.begin(), shortcuts.end(), cmp);

	// 3. 거리 계산하기
	int sIdx = 0; // shortcuts index

	for (int pos = 0; pos <= D; pos++) {

		minDist[pos] = min(minDist[pos], (pos == 0) ? 0 : minDist[pos - 1] + 1);

		while (sIdx < shortcuts.size() && shortcuts[sIdx].first.first < pos) sIdx++;

		// 현재 위치가 지름길 시작인 경우, 지름길 도착점 거리 업데이트
		while (sIdx < shortcuts.size() && shortcuts[sIdx].first.first == pos) {
			int to = shortcuts[sIdx].first.second;
			int dist = shortcuts[sIdx].second;

			if (to <= D) minDist[to] = min(minDist[to], minDist[pos] + dist);
			sIdx++;
		}
	}
	
	cout << minDist[D] << '\n';
	
	return 0;
}
