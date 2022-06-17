/*
테스트 1 〉	통과 (0.01ms, 73.5MB)
테스트 2 〉	통과 (0.01ms, 75.6MB)
테스트 3 〉	통과 (0.02ms, 86.5MB)
테스트 4 〉	통과 (0.02ms, 75.9MB)
테스트 5 〉	통과 (0.02ms, 77.4MB)
테스트 6 〉	통과 (0.02ms, 71.9MB)
테스트 7 〉	통과 (0.01ms, 76.1MB)
테스트 8 〉	통과 (0.02ms, 77.8MB)
테스트 9 〉	통과 (0.02ms, 73.7MB)
테스트 10 〉	통과 (0.02ms, 75.9MB)
테스트 11 〉	통과 (0.02ms, 77.8MB)
테스트 12 〉	통과 (0.01ms, 78.2MB)
테스트 13 〉	통과 (0.01ms, 76.6MB)
테스트 14 〉	통과 (0.01ms, 75.2MB)
테스트 15 〉	통과 (0.01ms, 77.9MB)
테스트 16 〉	통과 (0.01ms, 86.2MB)
*/

class Solution {
    public String solution(String s) {
        String answer = "";
        
        if (s.length() % 2 == 0) 
            answer = s.substring(s.length() / 2 - 1, s.length() / 2 + 1);
        else
            answer = s.substring(s.length() / 2, s.length() / 2 + 1);
        
        return answer;
    }
}
