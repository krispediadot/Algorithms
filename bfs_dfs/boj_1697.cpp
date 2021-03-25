#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

// 수빈이 N, 동생 K/ 걷기 = X-1, X+1, 순간이동 2*X / 동생을 찾는 가장 빠른 시간
int solution(int N, int K) {

    const int MAX_LOC = 100000;

    auto is_valid = [&](int loc) {
        return loc >= 0 && loc <= MAX_LOC;
    };

    unordered_set<int> visited;
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited.insert(N);

    while (!q.empty()) {
        auto target = q.front(); q.pop();
        int cur = target.first;
        int sec = target.second;

        if (cur == K) return sec;

        // 걷기 
        if (is_valid(cur + 1) && visited.find(cur + 1) == visited.end()) {
            q.push({cur + 1, sec + 1});
            visited.insert(cur + 1);
        }
        if (is_valid(cur - 1) && visited.find(cur - 1) == visited.end()) {
            q.push({cur - 1, sec + 1});
            visited.insert(cur - 1);
        }
        
        // 순간이동 
        if (is_valid(cur * 2) && visited.find(cur * 2) == visited.end()) {
            q.push({cur * 2, sec + 1});
            visited.insert(cur * 2);
        }
    }
    return -1;
}

int main() {
    int N, K; cin >> N >> K; // 수빈, 동생

    cout << solution(N, K) << endl;
}
