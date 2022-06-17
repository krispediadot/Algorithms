/*
테스트 1 〉	통과 (0.02ms, 75.8MB)
테스트 2 〉	통과 (0.02ms, 71.7MB)
테스트 3 〉	통과 (0.01ms, 73.8MB)
테스트 4 〉	통과 (0.02ms, 72.3MB)
테스트 5 〉	통과 (0.03ms, 74MB)
테스트 6 〉	통과 (0.01ms, 77.8MB)
테스트 7 〉	통과 (0.03ms, 66.2MB)
테스트 8 〉	통과 (0.02ms, 77.9MB)
테스트 9 〉	통과 (0.02ms, 76.3MB)
테스트 10 〉	통과 (0.03ms, 72.2MB)
테스트 11 〉	통과 (0.02ms, 73.3MB)
테스트 12 〉	통과 (0.01ms, 76MB)
테스트 13 〉	통과 (0.02ms, 75.1MB)
테스트 14 〉	통과 (0.02ms, 76.1MB)
테스트 15 〉	통과 (0.02ms, 80.4MB)
테스트 16 〉	통과 (0.02ms, 73.4MB)
테스트 17 〉	통과 (0.02ms, 76.5MB)
테스트 18 〉	통과 (0.02ms, 78MB)
테스트 19 〉	통과 (0.02ms, 75.1MB)
테스트 20 〉	통과 (0.02ms, 80.2MB)
*/
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        
        int[] students = new int[n+2];
        for (int idx : lost) students[idx]--;
        for (int idx : reserve) students[idx]++;
        
        for (int i = 1; i <= n; i++) {
            if (students[i] < 0) {
                // front
                if (students[i-1] > 0) {
                    answer++;
                    continue;
                }
                
                // back
                if (students[i+1] > 0) {
                    students[i+1]--;
                    answer++;
                }
            }
            else answer++;
        }
        
        return answer;
    }
}

