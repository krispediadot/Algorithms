/*
테스트 1 〉	통과 (2.92ms, 79.2MB)
테스트 2 〉	통과 (1.34ms, 73.8MB)
테스트 3 〉	통과 (0.84ms, 75.4MB)
테스트 4 〉	통과 (1.01ms, 86.4MB)
테스트 5 〉	통과 (2.86ms, 79.5MB)
테스트 6 〉	통과 (0.36ms, 77.7MB)
테스트 7 〉	통과 (0.16ms, 74.7MB)
*/

import java.util.*;

class Solution {
    public int getCount(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) cnt++;
        }
        return cnt;
    }
    public int solution(int left, int right) {
        int answer = 0;
        
        for (int i = left; i <= right; i++) {
            if (getCount(i)%2 == 0) answer += i;
            else answer -= i;
        }
        
        return answer;
    }
}
