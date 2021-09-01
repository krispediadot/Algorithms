// 2156 KB, 0ms
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 16;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);

	// 1. 입력
	int n, m, r; cin >> n >> m >> r;
	vector<int> cnts(n+1);
	for (int i = 1; i <= n; i++) cin >> cnts[i];
	vector<vector<int>> adj(n+1, vector<int>(n+1, MAX));
	for (int i = 0; i < r; i++) {
		int a, b, l; cin >> a >> b >> l;
		adj[a][b] = l;
		adj[b][a] = l;
	}

	// 2. 각 노드별 최대 아이템 수 확인
	int answer = 0;
	for (int start = 1; start <= n; start++) {

		// 2-1. 다익스트라
		vector<int> nodes(n+1, INT_MAX); // 노드에 갈 수 있는 최소 dist
		nodes[start] = 0;

		// start 노드와 연결된 에지 q에 추가
		queue<int> q; // nextNode
		for (int nextNode = 1; nextNode <= n; nextNode++) {
			if (adj[start][nextNode] <= m) {
				q.push(nextNode);
				nodes[nextNode] = adj[start][nextNode];
			}
		}

		// 각 노드의 dist 업데이트
		while (!q.empty()) {
			auto node = q.front(); q.pop();

			for (int nextNode = 1; nextNode <= n; nextNode++) {
				auto& nextDist = adj[node][nextNode];
				if (nodes[node] + nextDist < nodes[nextNode] && nodes[node] + nextDist <= m) {
					nodes[nextNode] = nodes[node] + nextDist;
					q.push(nextNode);
				}
			}
		}

		// 거리 m 이하로 방문할 수 있는 노드의 아이템 수만 더하기
		int sum = 0; // 아이템 개수
		for (int node = 1; node <= n; node++) {
			if (nodes[node] <= m) sum += cnts[node];
		}

		// answer = 최대 아이템 수
		answer = (sum > answer) ? sum : answer;
	}

	// 3. 출력
	cout << answer << '\n';

	return 0;
}
