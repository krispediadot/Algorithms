// 4676KB, 160ms
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

void solution(vector<vector<int>>& edges, vector<int>& nodes, int& n, int start) {
    queue<int> q;
    nodes[start] = 0;
    q.push(start);

    while (!q.empty()) {
        auto target = q.front(); q.pop();

        for (int idx = 1; idx <= n; idx++) {
            int& cost = edges[target][idx];
            if (cost > 0) {
                if (nodes[target] + cost < nodes[idx]){
                    nodes[idx] = nodes[target] + cost;
                    q.push(idx);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, e; cin >> n >> e;
    vector<vector<int>> edges(n+1, vector<int>(n+1, 0));
    vector<int> nodes_from(n+1, INT_MAX);
    vector<int> nodes_to(n+1, INT_MAX);
    vector<int> nodes_middle(n+1, INT_MAX);

    for (int i = 0; i < e; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[a][b] = c;
        edges[b][a] = c;
    }
    int from, to; cin >> from >> to;

    solution(edges, nodes_from, n, 1);
    solution(edges, nodes_to, n, n);
    solution(edges, nodes_middle, n, from);

    bool exist = true;
    int sum = 0;

    long long sub1 = nodes_from[from] + nodes_to[to];
    long long sub2 = nodes_from[to] + nodes_to[from];

    if (sub1 < INT_MAX && sub1 <= sub2) sum += sub1;
    if (sub2 < INT_MAX && sub1 > sub2) sum += sub2;
    if (nodes_middle[to] == INT_MAX) exist = false;
    else sum += nodes_middle[to];

    if (sum == 0 || exist == false) cout << -1;
    else cout << sum;

    return 0;
}
