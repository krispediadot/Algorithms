// 2156 KB, 436ms
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool checker(vector<vector<int>>& people, vector<bool> visited, int target, int cnt) {
	if (cnt == 5) return true;

	bool result = false;

	for (auto buddy : people[target]) {
		if (visited[buddy] == false) {
			visited[buddy] = true;
			result |= checker(people, visited, buddy, cnt + 1);
			visited[buddy] = false;
		}
		if (result) break;
	}
	return result;
}

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>> people(N);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		people[a].push_back(b);
		people[b].push_back(a);
	}
	vector<bool> visited(N, false);

	bool result = false;
	for (int target = 0; target < N; target++) {
		visited[target] = true;
		result |= checker(people, visited, target, 1);
		visited[target] = false;
	}
	
	cout << result;

	return 0;
}
