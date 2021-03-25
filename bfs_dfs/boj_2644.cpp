#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

// 두사람의 촌수를 계산하라 - 계산 못하면 -1
int solution(int n, int from, int to, vector<list<int>>& conn) {

    vector<bool> visited(n + 1, false);

    queue<pair<int, int>> q;
    q.push({from, 0});
    visited[from] = true;

    while (!q.empty()) {
        auto target = q.front(); q.pop();

        if (target.first == to) return target.second;

        for (auto& c : conn[target.first]) {
            if (visited[c] == false) {
                q.push({c, target.second + 1});
                visited[c] = true;
            }
        }
    }

    return -1;
}

int main() {
    int n; cin >> n;
    int from, to; cin >> from >> to;
    int m; cin >> m;
    vector<list<int>> conn(n + 1, list<int>(0));
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }

    cout << solution(n, from, to, conn) << endl;
}
