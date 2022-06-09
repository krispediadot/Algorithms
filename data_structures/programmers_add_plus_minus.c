/*
테스트 1 〉	통과 (0.01ms, 4.14MB)
테스트 2 〉	통과 (0.01ms, 4.14MB)
테스트 3 〉	통과 (0.01ms, 4.06MB)
테스트 4 〉	통과 (0.01ms, 4.07MB)
테스트 5 〉	통과 (0.01ms, 4.13MB)
테스트 6 〉	통과 (0.01ms, 4.35MB)
테스트 7 〉	통과 (0.01ms, 4.16MB)
테스트 8 〉	통과 (0.01ms, 4.16MB)
테스트 9 〉	통과 (0.01ms, 4.16MB)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// absolutes_len은 배열 absolutes의 길이입니다.
// signs_len은 배열 signs의 길이입니다.
int solution(int absolutes[], size_t absolutes_len, bool signs[], size_t signs_len) {
    int answer = 0;
    
    for (int i = 0; i < absolutes_len; i++) {
        answer += ((signs[i] == true ? 1 : -1) * absolutes[i]);
    }
    
    return answer;
}
