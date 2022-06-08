/*
테스트 1 〉	통과 (0.01ms, 4.16MB)
테스트 2 〉	통과 (0.01ms, 4.17MB)
테스트 3 〉	통과 (0.01ms, 3.72MB)
테스트 4 〉	통과 (0.01ms, 4.1MB)
테스트 5 〉	통과 (0.01ms, 4.19MB)
테스트 6 〉	통과 (0.01ms, 4.11MB)
테스트 7 〉	통과 (0.01ms, 4.13MB)
테스트 8 〉	통과 (0.01ms, 4.18MB)
테스트 9 〉	통과 (0.01ms, 3.8MB)
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    for (int i = 0; i < absolutes.size(); i++) {
        answer += ((signs[i] == true ? 1 : -1) * absolutes[i]);
    }
    
    return answer;
}
