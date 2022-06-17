/*
테스트 1 〉	통과 (0.05ms, 76.3MB)
테스트 2 〉	통과 (0.04ms, 77.4MB)
테스트 3 〉	통과 (0.06ms, 77.7MB)
테스트 4 〉	통과 (0.05ms, 78.8MB)
테스트 5 〉	통과 (0.05ms, 77.3MB)
테스트 6 〉	통과 (0.06ms, 75.4MB)
테스트 7 〉	통과 (0.61ms, 73.5MB)
테스트 8 〉	통과 (0.14ms, 79.5MB)
테스트 9 〉	통과 (0.59ms, 77.8MB)
테스트 10 〉	통과 (0.30ms, 79MB)
테스트 11 〉	통과 (1.00ms, 80.1MB)
테스트 12 〉	통과 (0.90ms, 79.2MB)
테스트 13 〉	통과 (0.10ms, 72.6MB)
테스트 14 〉	통과 (0.59ms, 78.2MB)
*/

import java.util.*;

class Solution {
    public int[] solution(int[] answers) {
        int[] s1 = {1,2,3,4,5};
        int[] s2 = {2,1,2,3,2,4,2,5};
        int[] s3 = {3,3,1,1,2,2,4,4,5,5};
        
        int[] score = new int[3];
        
        for (int i = 0; i < answers.length; i++) {
        	if (s1[i%s1.length] == answers[i]) score[0]++;
        	if (s2[i%s2.length] == answers[i]) score[1]++;
        	if (s3[i%s3.length] == answers[i]) score[2]++;
        }
        
        int maxScore = Math.max(score[0], Math.max(score[1], score[2]));
        
        List<Integer> list = new ArrayList<Integer>();
        for (int i = 0; i < 3; i++) {
        	if (score[i] == maxScore) list.add(i+1);
        }
        
        int[] result = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
        	result[i] = list.get(i);
        }
        
        return result;
    }
}
