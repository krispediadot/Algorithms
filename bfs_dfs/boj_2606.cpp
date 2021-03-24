#include <iostream>
#include <string>
#include <vector>

using namespace std;

int find_set(vector<int>& parents, int target) {
    if (parents[target] == target) return target;
    return parents[target] = find_set(parents, parents[target]);
}

void union_set(vector<int>& parents, int n1, int n2) {
    int p1 = find_set(parents, n1);
    int p2 = find_set(parents, n2);

    parents[p2] = p1;
}

// 1번 컴퓨터와 직간접적으로 연결되어있는 컴퓨터 개수
int solution(int& n, int& m,  vector<pair<int, int>> edges) {

    // 1. 부모 초기화
    vector<int> parents(n + 1, 0);
    for (int i = 1; i <= n; i++) parents[i] = i;

    // 2. 에지 연결 및 set 업데이트
    for (auto& edge : edges) {
        int n1 = edge.first;
        int n2 = edge.second;

        if (find_set(parents, n1) != find_set(parents, n2)) {
            union_set(parents, n1, n2);
        }
    }

    // 3. 동일한 set에 속하는 노드 개수 세기
    int answer = 0;

    int p1 = find_set(parents, 1);
    for (int i = 2; i <= n; i++) {
        parents[i] = find_set(parents, i);
        if (parents[i] == p1) answer++;
    }
    return answer;
}

int main() {

    int n, m; cin>>n>>m;
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int n1, n2; cin>>n1>>n2;
        edges.push_back({n1, n2});
    }

    cout << solution(n, m, edges) << endl; // 4
}
