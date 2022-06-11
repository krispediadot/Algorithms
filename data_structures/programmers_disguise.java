/*
테스트 1 〉	통과 (0.06ms, 68.3MB)
테스트 2 〉	통과 (0.06ms, 68.4MB)
테스트 3 〉	통과 (0.10ms, 78.6MB)
테스트 4 〉	통과 (0.06ms, 75.5MB)
테스트 5 〉	통과 (0.07ms, 78.7MB)
테스트 6 〉	통과 (0.05ms, 76MB)
테스트 7 〉	통과 (0.10ms, 77.3MB)
테스트 8 〉	통과 (0.05ms, 68.4MB)
테스트 9 〉	통과 (0.04ms, 76.6MB)
테스트 10 〉	통과 (0.06ms, 76.5MB)
테스트 11 〉	통과 (0.04ms, 73.4MB)
테스트 12 〉	통과 (0.08ms, 76.5MB)
테스트 13 〉	통과 (0.10ms, 74.1MB)
테스트 14 〉	통과 (0.04ms, 73.2MB)
테스트 15 〉	통과 (0.05ms, 68.2MB)
테스트 16 〉	통과 (0.05ms, 78.1MB)
테스트 17 〉	통과 (0.05ms, 73.6MB)
테스트 18 〉	통과 (0.05ms, 75.3MB)
테스트 19 〉	통과 (0.04ms, 78.6MB)
테스트 20 〉	통과 (0.05ms, 75.1MB)
테스트 21 〉	통과 (0.05ms, 76.2MB)
테스트 22 〉	통과 (0.03ms, 75.9MB)
테스트 23 〉	통과 (0.05ms, 83.8MB)
테스트 24 〉	통과 (0.05ms, 72.8MB)
테스트 25 〉	통과 (0.06ms, 74.4MB)
테스트 26 〉	통과 (0.07ms, 75.8MB)
테스트 27 〉	통과 (0.04ms, 79.5MB)
테스트 28 〉	통과 (0.05ms, 74.9MB)
*/

import java.util.HashMap;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        
        HashMap<String, Integer> hs = new HashMap<>();
        
        for (int i = 0; i < clothes.length; i++) {
            hs.put(clothes[i][1], hs.getOrDefault(clothes[i][1], 0) + 1);
        }
        
        for (String key : hs.keySet()) {
            answer *= (hs.get(key) + 1);
        }
        
        return answer - 1;
    }
}
