#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

// dfs와 bfs로 탐색한 결과를 출력하는 프로그램
// 정점이 여러개인 경우 정점 번호가 작은 것을 먼저 방문하고 더이상 방문할 수 있는 점이 없는 경우 종료
void solution(int n, int m, int start, vector<vector<int>> edges) {

    // 1. dfs
    stack<int> st;
    unordered_set<int> s;
    
    // 1-1. 시작 정점 넣기
    st.push(start);
    s.insert(start);
    cout << start << " ";

    while(!st.empty()) {
        int target = st.top();
     
        for (int i = 1; i <= n; i++) {
            if (edges[target][i] == 1 && s.find(i) == s.end()) {
                st.push(i); 
                s.insert(i);
                cout << i << " ";
                break;
            }
        }
        if (st.top() == target) st.pop();
    }
    cout << endl;

    // 2. bfs
    queue<int> q;
    s.clear();

    q.push(start);
    s.insert(start);

    while (!q.empty()) {
        int target = q.front(); q.pop();
        cout << target << " ";

        for (int i = 1; i <= n; i++) {
            if (edges[target][i] == 1 && s.find(i) == s.end()) {
                q.push(i);
                s.insert(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int n, m, start; cin>>n>>m>>start;
    vector<vector<int>> edges(n + 1, vector<int>(n + 1, 0)); // 인접 행렬
    for (int i = 0; i < m; i++) {
        int n1, n2; cin>>n1>>n2;
        edges[n1][n2] = 1;
        edges[n2][n1] = 1;
    }
    solution(n, m, start, edges);
}
