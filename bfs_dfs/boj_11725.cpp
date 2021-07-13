
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution(int n, vector<vector<int>>& edges) {
	vector<int> answer(n + 1, 0);

	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		auto target = q.front(); q.pop();

		for (auto node : edges[target]) {
			if (answer[node] == 0) {
				answer[node] = target;
				q.push(node);
			}
		}
	}

	for (int i = 2; i < answer.size(); i++)
		cout << answer[i] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n; cin >> n;
	vector<vector<int>> edges(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	solution(n, edges);

	return 0;
}
