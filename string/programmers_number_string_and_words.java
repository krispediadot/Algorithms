/*
테스트 1 〉	통과 (0.35ms, 76MB)
테스트 2 〉	통과 (0.34ms, 72.8MB)
테스트 3 〉	통과 (0.31ms, 77.5MB)
테스트 4 〉	통과 (0.30ms, 70.2MB)
테스트 5 〉	통과 (0.35ms, 78MB)
테스트 6 〉	통과 (0.41ms, 65.5MB)
테스트 7 〉	통과 (0.35ms, 76.4MB)
테스트 8 〉	통과 (0.33ms, 73.1MB)
테스트 9 〉	통과 (0.41ms, 76.2MB)
테스트 10 〉	통과 (0.30ms, 74.8MB)
*/

import java.util.*;

class Solution {
    public int solution(String s) {
        String[] numstr = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        
        for (int i = 0; i < numstr.length; i++)
            s = s.replaceAll(numstr[i], Integer.toString(i));

        return Integer.parseInt(s);
    }
}
