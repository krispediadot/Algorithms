// 2160 KB, 0ms
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int findParent(vector<int>& parents, int idx) {
	if (parents[idx] == idx) return idx;
	return parents[idx] = findParent(parents, parents[idx]);
}

void unionParent(vector<int>& parents, int& e1, int& e2) {
	int p1 = findParent(parents, e1);
	int p2 = findParent(parents, e2);

	parents[p1] = p2;
}

string solution(vector<pair<int, int>>& edges, vector<int>& cities, int& N, int& M) {

	// 1. union-find 
	vector<int> parents(N + 1);
	for (int i = 1; i <= N; i++) parents[i] = i;

	for (auto& edge : edges) {
		if (findParent(parents, edge.first) != findParent(parents, edge.second)) {
			unionParent(parents, edge.first, edge.second);
		}
	}

	for (int i = 0; i < N; i++)
		parents[i] = findParent(parents, i);

	// 2. 같은 그룹에 속하는지 확인
	int base = parents[cities[0]];
	for (int i = 1; i < M; i++) {
		if (parents[cities[i]] != base)
			return "NO";
	}
	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N >> M;
	vector<pair<int, int>> edges;
	vector<int> cities(M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num; cin >> num;
			if (num)
				edges.push_back({ i, j });
		}
	}

	for (int i = 0; i < M; i++)
		cin >> cities[i];

	cout << solution(edges, cities, N, M);

	return 0;
}
