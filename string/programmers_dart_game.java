/*
테스트 1 〉	통과 (5.54ms, 75.2MB)
테스트 2 〉	통과 (5.38ms, 76.8MB)
테스트 3 〉	통과 (5.69ms, 77.1MB)
테스트 4 〉	통과 (10.43ms, 77.1MB)
테스트 5 〉	통과 (10.80ms, 81.1MB)
테스트 6 〉	통과 (10.19ms, 78.7MB)
테스트 7 〉	통과 (10.24ms, 77.9MB)
테스트 8 〉	통과 (5.19ms, 74.5MB)
테스트 9 〉	통과 (10.51ms, 75.1MB)
테스트 10 〉	통과 (10.00ms, 81.1MB)
테스트 11 〉	통과 (9.84ms, 71.1MB)
테스트 12 〉	통과 (10.23ms, 75MB)
테스트 13 〉	통과 (10.14ms, 79.9MB)
테스트 14 〉	통과 (15.90ms, 74.1MB)
테스트 15 〉	통과 (10.47ms, 66.8MB)
테스트 16 〉	통과 (9.88ms, 74.6MB)
테스트 17 〉	통과 (10.34ms, 78.2MB)
테스트 18 〉	통과 (11.89ms, 89.1MB)
테스트 19 〉	통과 (9.95ms, 75.6MB)
테스트 20 〉	통과 (10.37ms, 78.3MB)
테스트 21 〉	통과 (9.98ms, 78.4MB)
테스트 22 〉	통과 (10.12ms, 73.5MB)
테스트 23 〉	통과 (10.15ms, 78.7MB)
테스트 24 〉	통과 (10.10ms, 73.9MB)
테스트 25 〉	통과 (12.22ms, 79.5MB)
테스트 26 〉	통과 (10.24ms, 78.1MB)
테스트 27 〉	통과 (10.22ms, 75.3MB)
테스트 28 〉	통과 (5.28ms, 73.4MB)
테스트 29 〉	통과 (12.28ms, 74.9MB)
테스트 30 〉	통과 (9.92ms, 76.6MB)
테스트 31 〉	통과 (9.78ms, 77.4MB)
테스트 32 〉	통과 (9.90ms, 84MB)
*/

import java.util.*;

// S**1, D**2, T**3
//*NUM = score*2
//#NUM = -score

class Solution {
    public int solution(String dartResult) {
        int answer = 0;    
        int[] sub = new int[3];
        
        int idx = 0;
        int cnt = 0;
        while (idx < dartResult.length()) {
            // 점수 확인
            String num = "" + dartResult.charAt(idx++);
            while (Character.isDigit(dartResult.charAt(idx))) num += dartResult.charAt(idx++);
            
            // 보너스 확인
            char bonus = dartResult.charAt(idx++);
            
            int npower = (bonus == 'S' ? 1 : (bonus == 'D' ? 2 : 3));
            sub[cnt] = (int)Math.pow(Integer.valueOf(num), npower);
            
            // 옵션 확인
            String option = "";
            while (idx < dartResult.length() && !Character.isDigit(dartResult.charAt(idx))) {
                option += dartResult.charAt(idx++);
            }

            for (char c : option.toCharArray()) {
                if (c == '*') {
                    sub[cnt]*= 2;
                    if (cnt >= 1)
                        sub[cnt-1]*= 2;
                }
                if (c == '#') sub[cnt]*= -1;
            }
            cnt++;
        }
        for (int n : sub) answer += n;
        
        return answer;
    }
}
