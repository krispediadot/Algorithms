/*
테스트 1 〉	통과 (4.23ms, 78.6MB)
테스트 2 〉	통과 (0.01ms, 76.6MB)
테스트 3 〉	통과 (0.02ms, 71.3MB)
테스트 4 〉	통과 (0.01ms, 73.7MB)
테스트 5 〉	통과 (0.02ms, 77.2MB)
테스트 6 〉	통과 (0.02ms, 77.5MB)
테스트 7 〉	통과 (0.02ms, 76MB)
테스트 8 〉	통과 (0.02ms, 74.6MB)
테스트 9 〉	통과 (0.02ms, 71.2MB)
테스트 10 〉	통과 (0.01ms, 73.6MB)
테스트 11 〉	통과 (0.02ms, 72.1MB)
*/

class Solution {
    public int solution(int n) {
        int answer = 0;
        
        for (int x = 2; x < n; x++) {
            if (n % x == 1) {
                answer = x;
                break;
            }
        } 
        
        return answer;
    }
}
