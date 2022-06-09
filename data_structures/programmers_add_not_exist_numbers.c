/*
테스트 1 〉	통과 (0.01ms, 4.09MB)
테스트 2 〉	통과 (0.01ms, 4.18MB)
테스트 3 〉	통과 (0.01ms, 4.36MB)
테스트 4 〉	통과 (0.01ms, 4.16MB)
테스트 5 〉	통과 (0.01ms, 4.16MB)
테스트 6 〉	통과 (0.01ms, 4.16MB)
테스트 7 〉	통과 (0.01ms, 4.16MB)
테스트 8 〉	통과 (0.01ms, 4.1MB)
테스트 9 〉	통과 (0.01ms, 4.09MB)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len) {
    int answer = 0;
    
    for (int i = 0; i <= 9; i++) answer += i;
    for (int i = 0; i < numbers_len; i++) answer -= numbers[i];
    
    return answer;
}
