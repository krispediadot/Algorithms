#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int find_set(vector<int>& parents, int target) {
    if (parents[target] == target) return target;
    return parents[target] = find_set(parents, parents[target]);
}

void union_set(vector<int>& parents, int node1, int node2) {
    int p1 = find_set(parents, node1);
    int p2 = find_set(parents, node2);

    parents[p2] = p1;
}

// 최소 비용으로 모은 섬 연결 costs {node1, node2, cosst}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 1. parents 초기화
    vector<int> parents(n, 0);
    for (int i = 0; i < n; i++) parents[i] = i;

    // 2. cost 작은 순으로 정렬
    using e = pair<int, pair<int, int>>;
    set<e> edges;
    for (auto& edge   : costs) {
        int node1 =  edge[0];
        int node2 = edge[1];
        int cost = edge[2];

        edges.insert({cost, {node1, node2}});
    }

    // 3. 연결
    for (auto& edge : edges) {
        int node1 = edge.second.first;
        int node2 = edge.second.second;
        int cost = edge.first;

        if(find_set(parents, node1) != find_set(parents, node2)) {
            union_set(parents, node1, node2);
            answer += cost;
        }
    }
 
    return answer;
}


int main() {
    cout << solution(4, {{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}) << endl; //4
}
