/*
테스트 1 〉	통과 (0.01ms, 3.66MB)
테스트 2 〉	통과 (0.01ms, 4.16MB)
테스트 3 〉	통과 (0.01ms, 4.18MB)
테스트 4 〉	통과 (0.01ms, 4.17MB)
테스트 5 〉	통과 (0.01ms, 4.17MB)
테스트 6 〉	통과 (0.01ms, 4.14MB)
테스트 7 〉	통과 (0.01ms, 4.09MB)
테스트 8 〉	통과 (0.01ms, 4.25MB)
테스트 9 〉	통과 (0.01ms, 4.2MB)
테스트 10 〉	통과 (0.01ms, 4.16MB)
테스트 11 〉	통과 (0.01ms, 4.17MB)
테스트 12 〉	통과 (0.01ms, 4.18MB)
테스트 13 〉	통과 (0.01ms, 4.09MB)
테스트 14 〉	통과 (0.01ms, 3.67MB)
테스트 15 〉	통과 (0.01ms, 4.03MB)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 알수 없는 번호 = 0
// 최고 순위와 최저 순위 알아보기
// 최고 순위, 최저 순위 리턴

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int cnt_match = 0;
    int cnt_zero = 0;
    
    for (auto& l : lottos) {
        if (l == 0) cnt_zero++;
        else {
            if (find(win_nums.begin(), win_nums.end(), l) != win_nums.end()) cnt_match++;
        }
    }
    
    // 최고 순위
    int max_match = cnt_match + cnt_zero;
    if (max_match <= 1) answer.push_back(6);
    else answer.push_back(7-max_match);
    
    // 최저 순위
    if (cnt_match <= 1) answer.push_back(6);
    else answer.push_back(7-cnt_match);
    
    return answer;
}
