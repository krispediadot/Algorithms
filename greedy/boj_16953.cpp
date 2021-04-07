#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// a->b 변환하는데 필요한 연산의 최솟값 + 1
// 연산1 = num * 2
// 연산2 = "num" + "1"

void do_operate(long long a, long long b, int cnt, int& answer) {
    if (cnt > answer || a > b) return;

    if (a == b) {
        answer = min(answer, cnt);
        return;
    }
    
    // 연산1
    do_operate(a * 2, b, cnt + 1, answer);

    // 연산2
    do_operate(a * 10 + 1, b, cnt + 1, answer);
}

int solution(long long a, long long b) {
    int answer = INT_MAX;

    do_operate(a, b, 0, answer);

    if (answer == INT_MAX) return -1;
    return answer + 1;
}

int main() {
    long long a, b; cin >> a >> b;
    
    cout << solution(a, b) << endl;
}
