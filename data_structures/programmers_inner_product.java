/*
테스트 1 〉	통과 (0.05ms, 81.4MB)
테스트 2 〉	통과 (0.02ms, 75.6MB)
테스트 3 〉	통과 (0.01ms, 77.1MB)
테스트 4 〉	통과 (0.02ms, 80.3MB)
테스트 5 〉	통과 (0.02ms, 75.6MB)
테스트 6 〉	통과 (0.03ms, 79.1MB)
테스트 7 〉	통과 (0.02ms, 78.4MB)
테스트 8 〉	통과 (0.03ms, 73.7MB)
테스트 9 〉	통과 (0.03ms, 78.9MB)
*/

class Solution {
    public int solution(int[] a, int[] b) {
        int answer = 0;
        for (int i = 0; i < a.length; i++)
            answer += (a[i] * b[i]);
        return answer;
    }
}
