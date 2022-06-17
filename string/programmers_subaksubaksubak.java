/*
테스트 1 〉	통과 (2.95ms, 77.8MB)
테스트 2 〉	통과 (11.45ms, 90.3MB)
테스트 3 〉	통과 (7.25ms, 84MB)
테스트 4 〉	통과 (21.68ms, 100MB)
테스트 5 〉	통과 (6.11ms, 82.7MB)
테스트 6 〉	통과 (1.96ms, 77.2MB)
테스트 7 〉	통과 (1.81ms, 83.8MB)
테스트 8 〉	통과 (1.92ms, 82.5MB)
테스트 9 〉	통과 (2.08ms, 76.9MB)
테스트 10 〉	통과 (1.99ms, 72.5MB)
테스트 11 〉	통과 (1.94ms, 74.6MB)
테스트 12 〉	통과 (1.92ms, 71.5MB)
테스트 13 〉	통과 (2.19ms, 71.7MB)
테스트 14 〉	통과 (1.91ms, 80.2MB)
테스트 15 〉	통과 (43.88ms, 130MB)
테스트 16 〉	통과 (1.81ms, 72.9MB)
*/

class Solution {
    public String solution(int n) {
        String answer = "";
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) answer += '수';
            else answer += '박';
        }
        
        return answer;
    }
}
