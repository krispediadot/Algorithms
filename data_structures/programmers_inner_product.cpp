/*
테스트 1 〉	통과 (0.01ms, 4.2MB)
테스트 2 〉	통과 (0.01ms, 4.11MB)
테스트 3 〉	통과 (0.01ms, 4.17MB)
테스트 4 〉	통과 (0.01ms, 4.16MB)
테스트 5 〉	통과 (0.01ms, 4.16MB)
테스트 6 〉	통과 (0.01ms, 3.61MB)
테스트 7 〉	통과 (0.01ms, 3.69MB)
테스트 8 〉	통과 (0.01ms, 4.16MB)
테스트 9 〉	통과 (0.01ms, 4.09MB)
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    
    for (int i = 0; i < a.size(); i++) {
        answer += (a[i] * b[i]);
    }
    
    return answer;
}
