/*
테스트 1 〉	통과 (0.13ms, 4.42MB)
테스트 2 〉	통과 (0.18ms, 4.4MB)
테스트 3 〉	통과 (0.05ms, 4.16MB)
테스트 4 〉	통과 (0.03ms, 4.17MB)
테스트 5 〉	통과 (0.22ms, 4.07MB)
테스트 6 〉	통과 (1.62ms, 4.09MB)
테스트 7 〉	통과 (0.06ms, 4.11MB)
테스트 8 〉	통과 (2.25ms, 4.07MB)
테스트 9 〉	통과 (0.21ms, 4.02MB)
테스트 10 〉	통과 (2.24ms, 4.15MB)
테스트 11 〉	통과 (0.01ms, 4.12MB)
테스트 12 〉	통과 (0.01ms, 4.1MB)
테스트 13 〉	통과 (0.01ms, 4.09MB)
테스트 14 〉	통과 (0.01ms, 4.16MB)
테스트 15 〉	통과 (0.01ms, 4.08MB)
테스트 16 〉	통과 (6.56ms, 4.09MB)
테스트 17 〉	통과 (0.09ms, 4.15MB)
테스트 18 〉	통과 (0.12ms, 4.09MB)
테스트 19 〉	통과 (0.01ms, 4.16MB)
테스트 20 〉	통과 (8.83ms, 4.33MB)
테스트 21 〉	통과 (7.72ms, 4.09MB)
테스트 22 〉	통과 (0.02ms, 4.1MB)
테스트 23 〉	통과 (0.01ms, 4.09MB)
테스트 24 〉	통과 (6.68ms, 4.03MB)
테스트 25 〉	통과 (6.80ms, 4.16MB)
테스트 26 〉	통과 (0.01ms, 4.1MB)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_prime(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    
    bool memoization[1000*3] = {false};
    
    int answer = 0;
    
    for (int i = 0; i < nums_len - 2; i++) {
        for (int j = i + 1; j < nums_len - 1; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int target = nums[i] + nums[j] + nums[k];
                
                if (memoization[target] == true || is_prime(target))
                    answer++;
            }
        }
    }
    
    return answer;
}
