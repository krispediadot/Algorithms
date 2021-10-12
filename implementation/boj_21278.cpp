// 2024 KB, 388ms

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 접근성(치킨집 왕복 거리)의 합을 최소화

vector<int> getDist(vector<vector<bool>>& adj, int& N, int i, int j) {
    vector<int> dist(N+1, N+1);
    vector<bool> visited(N+1, false);
    
    queue<int> q; // idx
    dist[i] = 0;
    dist[j] = 0;
    q.push(i);
    q.push(j);
    visited[i] = true;
    visited[j] = true;

    while (!q.empty()) {
        auto target = q.front(); q.pop();

        for (int idx = 1; idx <= N; idx++) {
            if (visited[idx] == false && adj[target][idx] == true) {
                if (dist[target] + 1 < dist[idx]) {
                    dist[idx] = dist[target] + 1;
                    q.push(idx);
                }
            }
        }
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M; cin >> N >> M;
    vector<vector<bool>> adj(N+1, vector<bool>(N+1, false));
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    vector<int> dist(N+1, N+1);
    int sumDist = N*N;
    pair<int, int> storeIdx = {0, 0};

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            vector<int> sub = getDist(adj, N, i, j);

            int subSumDist = 0;
            for (int j = 1; j <= N; j++) subSumDist += sub[j];

            if (subSumDist < sumDist) {
                storeIdx = {i, j};
                dist = sub;
                sumDist = subSumDist;
            }
        }
    }

    cout << storeIdx.first << " " << storeIdx.second << " " << sumDist*2 << '\n';

    return 0;
}
