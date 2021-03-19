#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 야근 피로도 최소화
// 피로도 += 남은일 작업량 제곱
long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq(begin(works), end(works));
    
    while (n-- && !pq.empty()) {
        int target = pq.top(); pq.pop();
        target--;
        if (target > 0) pq.push(target);
    }
    
    while (!pq.empty()) {
        int w = pq.top(); pq.pop();
        answer += (w * w);
    }
    
    return answer;
}
int main() {
    cout << solution(4, {4, 3, 3}) << endl;
}

