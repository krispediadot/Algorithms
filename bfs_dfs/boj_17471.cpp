#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int total_population;
vector<int> population;
vector<vector<int>> conn;
vector<int> rflags;

bool is_connected(vector<int>& v) {
    vector<bool> visited(N, false);

    queue<int> q;
    visited[v[0]] = true;
    q.push(v[0]);
    
    while (!q.empty()) {
        auto target = q.front(); q.pop();

        for (auto c : conn[target]) {
            
            if (find(v.begin(), v.end(), c) == v.end()) continue;
            if (visited[c] == true) continue;
            
            visited[c] = true;
            q.push(c);
        }
    }

    for (auto c : v) {
        if (visited[c] == false) return false;
    }
    return true;
}

void get_min_diff(int& answer) {
    vector<int> red, blue;

    for (int i = 0; i < N; i++) {
        rflags[i] == 1 ? red.push_back(i) : blue.push_back(i); 
    }

    // 같은 그룹에 속하는지 확인
    if (is_connected(red) == false || is_connected(blue) == false) 
        return;

    int sum_red_population = 0;
    for (auto r : red) sum_red_population += population[r];

    answer = min(answer, abs(sum_red_population - (total_population - sum_red_population)));
}

int solution() {
    int answer = INT_MAX;

    for (int i = 1; i < N; i++) {
        rflags.clear();
        rflags.resize(N, 1);

        for (int j = 0; j < i; j++) rflags[j] = 0;

        do {
            get_min_diff(answer);
        } while (next_permutation(rflags.begin(), rflags.end()));
    }

    return answer;
}

int main() {
    cin >> N;

    population.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> population[i];
        total_population += population[i];
    }

    conn.resize(N);
    for (int i = 0; i < N; i++) {
        int cnt; cin >> cnt;
        conn[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            int num; cin >> num;
            conn[i][j] = num - 1;
        }
    }

    int result = solution();

    if (result == INT_MAX) cout << -1 << endl;
    else cout << result << endl;

}
