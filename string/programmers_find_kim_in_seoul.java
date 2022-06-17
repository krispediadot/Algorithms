/*
테스트 1 〉	통과 (0.82ms, 72.9MB)
테스트 2 〉	통과 (0.78ms, 73.9MB)
테스트 3 〉	통과 (0.74ms, 73.5MB)
테스트 4 〉	통과 (0.86ms, 74.9MB)
테스트 5 〉	통과 (0.83ms, 71.1MB)
테스트 6 〉	통과 (0.78ms, 80.4MB)
테스트 7 〉	통과 (0.89ms, 83.5MB)
테스트 8 〉	통과 (0.80ms, 73.7MB)
테스트 9 〉	통과 (0.77ms, 66MB)
테스트 10 〉	통과 (0.73ms, 78.4MB)
테스트 11 〉	통과 (0.72ms, 71.6MB)
테스트 12 〉	통과 (0.93ms, 79.6MB)
테스트 13 〉	통과 (0.93ms, 76.1MB)
테스트 14 〉	통과 (0.86ms, 77.8MB)
*/

class Solution {
    public String solution(String[] seoul) {
        String answer = "";
        
        for (int i = 0; i < seoul.length; i++) {
            if (seoul[i].equals("Kim")) {
                answer = String.format("김서방은 %d에 있다", i);
                break;
            }
        }
        return answer;
    }
}
