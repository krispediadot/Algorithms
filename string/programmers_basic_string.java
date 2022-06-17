/*
테스트 1 〉	통과 (0.05ms, 74.9MB)
테스트 2 〉	통과 (0.02ms, 86.6MB)
테스트 3 〉	통과 (0.03ms, 72.7MB)
테스트 4 〉	통과 (0.04ms, 73.8MB)
테스트 5 〉	통과 (0.02ms, 72.5MB)
테스트 6 〉	통과 (0.02ms, 76.3MB)
테스트 7 〉	통과 (0.02ms, 72.3MB)
테스트 8 〉	통과 (0.08ms, 71.3MB)
테스트 9 〉	통과 (0.04ms, 74.7MB)
테스트 10 〉	통과 (0.04ms, 75.2MB)
테스트 11 〉	통과 (0.04ms, 75.3MB)
테스트 12 〉	통과 (0.02ms, 79.8MB)
테스트 13 〉	통과 (0.01ms, 76.3MB)
테스트 14 〉	통과 (0.04ms, 72.6MB)
테스트 15 〉	통과 (0.04ms, 77.8MB)
테스트 16 〉	통과 (0.03ms, 77.5MB)
*/

class Solution {
    public boolean solution(String s) {
        boolean answer = true;
        
        if (s.length() != 4 && s.length() != 6) answer = false;
        if (answer) {
            for (char c : s.toCharArray()) {
                if (Character.isDigit(c) == false) {
                    answer = false;
                    break;
                }
            }
        }
        
        return answer;
    }
}
