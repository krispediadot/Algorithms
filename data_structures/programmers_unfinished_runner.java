/*
정확성  테스트
테스트 1 〉	통과 (0.04ms, 73MB)
테스트 2 〉	통과 (0.07ms, 70.8MB)
테스트 3 〉	통과 (0.42ms, 80.3MB)
테스트 4 〉	통과 (0.65ms, 84.2MB)
테스트 5 〉	통과 (0.67ms, 77.2MB)
효율성  테스트
테스트 1 〉	통과 (72.56ms, 81.2MB)
테스트 2 〉	통과 (81.83ms, 89MB)
테스트 3 〉	통과 (83.28ms, 94.4MB)
테스트 4 〉	통과 (80.00ms, 96MB)
테스트 5 〉	통과 (81.53ms, 95.5MB)
*/

import java.util.HashMap;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        for (String player : participant) hm.put(player, hm.getOrDefault(player, 0) + 1);
        for (String player : completion) hm.put(player, hm.get(player) - 1);

        for (String key : hm.keySet()) {
            if (hm.get(key) != 0) {
                answer = key;
                break;
            }
        }

        return answer;
    }
}
