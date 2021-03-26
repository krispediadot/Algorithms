#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

const int BEER_BOX = 20;
const int MAX_METER = 50;

// 상근이네에서 출발, 맥주 1박스(20개)
// 50미터에 맥주 1병
// 편의점에서 빈병 버리고 새 맥주 구매 가능
// 맥주 20개 넘을 수 없음
// 상근이 집에서 페스티벌 장소까지 행복하게 도착 가능 = "happy" / 불가능 = "sad"
string solution(pair<int, int>& from, pair<int, int>& to, set<pair<int, int>>& shops) {
    auto get_distance = [](pair<int, int>& a, pair<int, int>& b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };
    
    queue<pair<int, int>> q;
    q.push(from);

    while (!q.empty()) {
        auto target = q.front(); q.pop();

        // 1. 현재 상태로 페스티벌 장소에 갈 수 있으면 끝
        if (get_distance(target, to) <= BEER_BOX * MAX_METER) 
            return "happy";

        // 2. 못가면 편의점 들려서 맥주 사야함
        set<pair<int, int>> visited_shop;

        for (auto shop : shops) {
            int distance = get_distance(target, shop);
            if (distance <= BEER_BOX * MAX_METER) {
                q.push(shop);
                visited_shop.insert(shop);
            }
        }

        for (auto& shop : visited_shop) shops.erase(shops.find(shop));
    }

    return "sad";
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        pair<int, int> from {0, 0}; cin >> from.first >> from.second;
        set<pair<int, int>> shops;
        for (int i = 0; i < n; i++) {
            pair<int, int> loc {0, 0};
            cin >> loc.first >> loc.second;
            shops.insert(loc);
        }
        pair<int, int> to {0, 0}; cin >> to.first >> to.second;

        cout << solution(from, to, shops) << endl;
    }
}
