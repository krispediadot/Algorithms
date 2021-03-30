#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int calculator(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
}

void dfs(string s, int idx, int result, int& answer) {
    if (idx > s.length()) {
        answer = result > answer ? result : answer;
        return;
    }
    // 괄호 없이
    dfs(s, idx + 2, calculator(result, s[idx] - '0', s[idx - 1]), answer);
    // 괄호 추가
    if (s.length() - idx > 2) {
        dfs(s, idx + 4, calculator(result, calculator(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]), s[idx - 1]), answer);
    }
}

int solution(int n, string s) {
    int answer = INT_MIN;
    s.insert(s.begin(), '+');
    dfs(s, 1, 0, answer);

    return answer;
}

int main() {
    int n; cin>>n;
    string s; cin>>s;

    cout << solution(n, s) << endl;
}
