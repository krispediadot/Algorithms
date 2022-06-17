/*
테스트 1 〉	통과 (0.25ms, 72.6MB)
테스트 2 〉	통과 (0.23ms, 77.5MB)
테스트 3 〉	통과 (0.25ms, 77.5MB)
테스트 4 〉	통과 (0.23ms, 77.9MB)
테스트 5 〉	통과 (0.21ms, 76.1MB)
테스트 6 〉	통과 (0.24ms, 76.7MB)
테스트 7 〉	통과 (0.46ms, 74.2MB)
테스트 8 〉	통과 (0.49ms, 83MB)
테스트 9 〉	통과 (0.46ms, 77.2MB)
테스트 10 〉	통과 (0.60ms, 77.6MB)
테스트 11 〉	통과 (0.41ms, 74.5MB)
테스트 12 〉	통과 (0.43ms, 77.7MB)
테스트 13 〉	통과 (0.50ms, 76MB)
테스트 14 〉	통과 (0.44ms, 73MB)
테스트 15 〉	통과 (0.50ms, 71.6MB)
테스트 16 〉	통과 (0.51ms, 71.6MB)
테스트 17 〉	통과 (0.49ms, 73.6MB)
테스트 18 〉	통과 (0.47ms, 79.2MB)
테스트 19 〉	통과 (0.56ms, 79.4MB)
테스트 20 〉	통과 (0.32ms, 76.6MB)
테스트 21 〉	통과 (0.26ms, 76.4MB)
테스트 22 〉	통과 (0.36ms, 73.8MB)
테스트 23 〉	통과 (0.38ms, 72.8MB)
*/

import java.util.*;

// 최대 몇개의 부서에 물품 지원 가능한지

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0;
        
        List<Integer> list = new ArrayList<Integer>();
        
        for (int i = 0; i < d.length; i++) {
            list.add(d[i]);
        }
        
        Collections.sort(list);
        
        int idx = 0;
        while (idx < list.size()) {
            if (list.get(idx) > budget) break;
            
            answer++;
            budget -= list.get(idx);
            idx++;
        }
        
        return answer;
    }
}
