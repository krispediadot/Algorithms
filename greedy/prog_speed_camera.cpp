#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 단속 카메라를 한번은 만나도록, 최소의 단속 카메라 개수
int solution(vector<vector<int>> routes) {
    int answer = 1;

    // 차 들어오느 순서대로 오름차순
    sort(routes.begin(), routes.end());
    
    // 나가는 limit 구하고 업데이트
    int out = routes[0][1];
    for (auto& car : routes) {
        // 지금 보는 차가 나가는 limit 보다 뒤에 들어오면 카메라 추가
        if (out < car[0]) {
            answer++;
            out = car[1];
        }
        // 아니면 나가는 limit만 조정
        else out = min(car[1], out);
    }
    
    return answer;
}


int main() {
    cout << solution({{-20,15},{-14,-5},{-18,-13},{-5,-3}}) << endl; // 2
}
