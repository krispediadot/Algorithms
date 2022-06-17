/*
테스트 1 〉	통과 (0.01ms, 73.6MB)
테스트 2 〉	통과 (0.01ms, 74.3MB)
테스트 3 〉	통과 (0.02ms, 77.4MB)
테스트 4 〉	통과 (0.02ms, 73.1MB)
테스트 5 〉	통과 (0.02ms, 78.3MB)
테스트 6 〉	통과 (0.01ms, 73.6MB)
테스트 7 〉	통과 (0.03ms, 75.3MB)
테스트 8 〉	통과 (0.02ms, 76.4MB)
테스트 9 〉	통과 (0.01ms, 73.9MB)
*/

class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        
        for (int i = 0; i <= 9; i++)
            answer += i;
        
        for (int n : numbers)
            answer -= n;
        
        return answer;
    }
}
