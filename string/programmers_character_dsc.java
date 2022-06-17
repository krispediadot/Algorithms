/*
테스트 1 〉	통과 (10.64ms, 75MB)
테스트 2 〉	통과 (9.41ms, 70.9MB)
테스트 3 〉	통과 (9.68ms, 77.4MB)
테스트 4 〉	통과 (10.50ms, 86.6MB)
테스트 5 〉	통과 (15.65ms, 94.4MB)
테스트 6 〉	통과 (11.41ms, 83.9MB)
테스트 7 〉	통과 (11.04ms, 80.1MB)
테스트 8 〉	통과 (9.68ms, 71.5MB)
테스트 9 〉	통과 (11.11ms, 79.6MB)
테스트 10 〉	통과 (9.78ms, 77.2MB)
테스트 11 〉	통과 (11.35ms, 78.9MB)
테스트 12 〉	통과 (9.62ms, 74.5MB)
테스트 13 〉	통과 (10.15ms, 77.2MB)
테스트 14 〉	통과 (11.19ms, 75MB)
테스트 15 〉	통과 (9.88ms, 77.8MB)
테스트 16 〉	통과 (11.19ms, 80.8MB)
*/

import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        char[] schar = s.toCharArray();
        
        Arrays.sort(schar);
        
        String uppers = "";
        boolean isupper = false;
        for (int i = schar.length - 1; i >= 0; i--) {
            if (!isupper && schar[i] <= 'Z') isupper = true;
            
            if (isupper) uppers += schar[i];
            else answer += schar[i];
        }
        
        answer += uppers;
        
        return answer;
    }
}
