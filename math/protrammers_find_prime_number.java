/*
정확성  테스트
테스트 1 〉	통과 (0.03ms, 71.9MB)
테스트 2 〉	통과 (0.07ms, 78.5MB)
테스트 3 〉	통과 (0.10ms, 71.9MB)
테스트 4 〉	통과 (0.19ms, 75.9MB)
테스트 5 〉	통과 (0.13ms, 76MB)
테스트 6 〉	통과 (1.02ms, 81.3MB)
테스트 7 〉	통과 (0.35ms, 72.4MB)
테스트 8 〉	통과 (0.82ms, 76.1MB)
테스트 9 〉	통과 (1.10ms, 72.8MB)
테스트 10 〉	통과 (39.66ms, 85.1MB)
테스트 11 〉	통과 (179.61ms, 93.3MB)
테스트 12 〉	통과 (45.10ms, 87.5MB)

효율성  테스트
테스트 1 〉	통과 (211.75ms, 52.5MB)
테스트 2 〉	통과 (193.73ms, 51.9MB)
테스트 3 〉	통과 (210.06ms, 52.5MB)
테스트 4 〉	통과 (207.54ms, 51.7MB)
*/

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for (int i = 2; i <= n; i++) {
            if (isPrime(i)) answer++;
        }
        
        return answer;
    }
    
    public boolean isPrime(int n) {
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
