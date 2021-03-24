// 조이스틱 (https://programmers.co.kr/learn/courses/30/lessons/42860)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string name) {
    int answer = 0;
    unordered_set<int> need_change;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != 'A') need_change.insert(i);
    }
    
    auto min_up_down = [&name](int idx) {
        int up = name[idx] - 'A';
        int down = 'Z' - name[idx] + 1;
        return up < down ? up : down;
    };
    auto min_left_right = [&name, &need_change](int& idx) {
        int term = 1;
        while (term < name.length()) {
            int left_idx = (idx - term + name.length()) % name.length();
            int right_idx = (idx + term) % name.length();
            
            if (need_change.find(right_idx) != need_change.end()) {
                idx = right_idx;
                break;
            }
            if (need_change.find(left_idx) != need_change.end()) {
                idx = left_idx;
                break;
            }
            
            term++;
        }
        return term;
    };
    
    int idx = 0;
    while (need_change.size() > 0) {
        // 1. 현재 위치가 A가 아니라면
        if (need_change.find(idx) != need_change.end()) {
            answer += min_up_down(idx);
            need_change.erase(idx);
        }
        if (need_change.size() == 0) break;
        // 2. 아직 변경할게 남았다면 가까운 곳으로 이동
        answer += min_left_right(idx);
    }
    
    return answer;
}

int main() {
    cout << solution("JAZ") << endl; // 11
    cout << solution("JEROEN") << endl; // 56
    cout << solution("JAN") << endl; // 23
    cout << solution("JAA") << endl; // 9
    cout << solution("AAA") << endl; // 0
}

