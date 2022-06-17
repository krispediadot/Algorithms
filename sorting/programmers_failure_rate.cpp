/*
테스트 1 〉	통과 (0.02ms, 3.72MB)
테스트 2 〉	통과 (0.02ms, 4.14MB)
테스트 3 〉	통과 (0.25ms, 4.18MB)
테스트 4 〉	통과 (1.06ms, 6.5MB)
테스트 5 〉	통과 (2.08ms, 9.92MB)
테스트 6 〉	통과 (0.05ms, 4.14MB)
테스트 7 〉	통과 (0.13ms, 4.11MB)
테스트 8 〉	통과 (1.05ms, 6.52MB)
테스트 9 〉	통과 (2.12ms, 9.87MB)
테스트 10 〉	통과 (1.11ms, 6.26MB)
테스트 11 〉	통과 (1.37ms, 6.58MB)
테스트 12 〉	통과 (1.52ms, 7.73MB)
테스트 13 〉	통과 (1.67ms, 8.35MB)
테스트 14 〉	통과 (0.02ms, 3.66MB)
테스트 15 〉	통과 (0.70ms, 5.29MB)
테스트 16 〉	통과 (0.35ms, 4.37MB)
테스트 17 〉	통과 (0.68ms, 5.11MB)
테스트 18 〉	통과 (0.34ms, 4.39MB)
테스트 19 〉	통과 (0.08ms, 3.86MB)
테스트 20 〉	통과 (0.49ms, 4.79MB)
테스트 21 〉	통과 (0.94ms, 6.16MB)
테스트 22 〉	통과 (2.69ms, 9.86MB)
테스트 23 〉	통과 (3.01ms, 9.73MB)
테스트 24 〉	통과 (1.99ms, 9.64MB)
테스트 25 〉	통과 (0.01ms, 4.17MB)
테스트 26 〉	통과 (0.01ms, 4.17MB)
테스트 27 〉	통과 (0.01ms, 3.59MB)
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 실패율 = 클리어하지 못한 플레이어수 / 스테이지에 도달한 플레이어수
// 실패율이 높은 스테이지로부터 내림차순으로 스테이지 번호

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    unordered_map<int, int> m;
    for (auto s : stages) m[s]++;

    vector<pair<float, int>> failure; // {실패율, 스테이지}

    int people = stages.size();
    for (int stage = 1; stage <= N; stage++) {
        if (m.find(stage) == m.end()) failure.push_back({0, stage});
        else {
            int blocked = m[stage];
            failure.push_back({(float)blocked / people, stage});
            people -= blocked;
        }
    }

    auto cmp = [](pair<float, int>& a, pair<float, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    };
    sort(failure.begin(), failure.end(), cmp);

    for (auto f : failure) {
        answer.push_back(f.second);
    }

    return answer;
}

