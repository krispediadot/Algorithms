/*
테스트 1 〉	통과 (0.33ms, 75.7MB)
테스트 2 〉	통과 (0.34ms, 75.8MB)
테스트 3 〉	통과 (0.32ms, 73.4MB)
테스트 4 〉	통과 (0.32ms, 76.2MB)
테스트 5 〉	통과 (0.31ms, 76.9MB)
테스트 6 〉	통과 (0.33ms, 74.2MB)
테스트 7 〉	통과 (0.34ms, 77MB)
*/

import java.util.Arrays;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        
        for (int i = 0; i < commands.length; i++) {
            int[] sub = Arrays.copyOfRange(array, commands[i][0] - 1, commands[i][1]);
            Arrays.sort(sub);
            answer[i] = sub[commands[i][2] - 1];
        }
        return answer;
    }
}
