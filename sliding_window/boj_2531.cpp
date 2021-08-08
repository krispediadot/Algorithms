// 2264 KB, 12ms
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int N, D, K, C; cin >> N >> D >> K >> C;
	vector<int> sushi(N);
	unordered_map<int, int> cnts;
	for (int i = 0; i < N; i++) cin >> sushi[i];
	for (int i = 0; i < K; i++) {
		cnts[sushi[i]]++;
		sushi.push_back(sushi[i]);
	}
	cnts[C]++;

	int answer = cnts.size();
	for (int idx = 1; idx < N; idx++) {
		cnts[sushi[idx - 1]]--;
		if (cnts[sushi[idx - 1]] == 0) cnts.erase(sushi[idx - 1]);
		cnts[sushi[idx + K - 1]]++;

		answer = max(answer, (int)cnts.size());
	}
	cout << answer;
	
	return 0;
}
