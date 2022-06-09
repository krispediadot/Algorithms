/*
테스트 1 〉	통과 (0.01ms, 4.16MB)
테스트 2 〉	통과 (0.01ms, 4.16MB)
테스트 3 〉	통과 (0.01ms, 4.17MB)
테스트 4 〉	통과 (0.01ms, 4.43MB)
테스트 5 〉	통과 (0.01ms, 4.18MB)
테스트 6 〉	통과 (0.01ms, 3.68MB)
테스트 7 〉	통과 (0.01ms, 4.16MB)
테스트 8 〉	통과 (0.01ms, 4.4MB)
테스트 9 〉	통과 (0.01ms, 4.42MB)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a_len은 배열 a의 길이입니다.
// b_len은 배열 b의 길이입니다.
int solution(int a[], size_t a_len, int b[], size_t b_len) {
    int answer = 0;
    
    for (int i = 0; i < a_len; i++) {
        answer += (a[i] * b[i]);
    }
    
    return answer;
}

