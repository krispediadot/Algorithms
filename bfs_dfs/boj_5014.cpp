#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;

// 스타링크 총 F층, 스타링크 위치 G층
// 강호 현재 S층 , 엘베로 G층으로 이동
// 버튼은 U층 위로 / D층 아래로 만 있음 
// 버튼을 눌러야하는 최소 횟수
// 엘베로 갈 수 없으면 use the stairs 
void solution(int F, int S, int G, int U, int D) {

    auto is_valid = [&F](int loc) {
        return loc >= 1 && loc <= F;
    };
    
    unordered_set<int> visited;
    queue<pair<int, int>> q;
    q.push({S, 0});
    visited.insert(S);

    while (!q.empty()) {
        auto target = q.front(); q.pop();
        int loc = target.first;
        int cnt = target.second;

        if (loc == G) {
            cout << cnt << "\n";
            return;
        }
        
        // 위로 이동
        if (is_valid(loc + U) && visited.find(loc + U) == visited.end()) {
            q.push({loc + U, cnt + 1});
            visited.insert(loc + U);
        }

        // 아래로 이동
        if (is_valid(loc - D) && visited.find(loc - D) == visited.end()) {
            q.push({loc - D, cnt + 1});
            visited.insert(loc - D);
        } 
    }

    cout << "use the stairs\n";
}

int main() {
    int F, S, G, U, D; cin >> F >> S >> G >> U >> D;

    solution(F, S, G, U, D);
}
