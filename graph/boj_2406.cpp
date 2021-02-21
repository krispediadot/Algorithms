//https://www.acmicpc.net/problem/2406
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> connected;
vector<pair<int, pair<int, int>>> edges;
vector<int> setInfo;
int n, m;

int findSet(int target) {
    if (target == setInfo[target]) return target;
    return setInfo[target] = findSet(setInfo[target]);
}
void unionSet(int target1, int target2) {
    int set1 = findSet(target1);
    int set2 = findSet(target2);

    if (set1 != set2) {
        setInfo[set2] = set1;
    }
}
void solution() {
    int totalCost = 0, totalConnect = 0;
    // setInfo 초기화
    for (int i = 0; i <= n; i++) setInfo.push_back(i);
    for (auto each : connected) {
        if (findSet(each.first) != findSet(each.second))
            unionSet(each.first, each.second);
    }
    //에지 크기에 따라 정렬 
    sort(edges.begin(), edges.end());

    for (auto each : edges) {
        if (findSet(each.second.first) != findSet(each.second.second)) {
            unionSet(each.second.first, each.second.second);
            connected.push_back(each.second);
            totalCost += each.first;
            totalConnect++;
        }
    }
    // 출력
    cout << totalCost << " " << totalConnect << "\n";
    for (int i = m; i < m + totalConnect; i++)
        cout << connected[i].first << " " << connected[i].second << "\n";
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        pair<int, int> edge;
        cin >> edge.first >> edge.second;
        connected.push_back(edge);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int cost; cin >> cost;
            if (i == j || i == 1 || j == 1) continue;
            edges.push_back(make_pair(cost, make_pair(i, j)));
        }
    }
    solution();
}
