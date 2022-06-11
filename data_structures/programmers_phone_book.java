/*
정확성  테스트
테스트 1 〉	통과 (0.04ms, 82.5MB)
테스트 2 〉	통과 (0.06ms, 75.7MB)
테스트 3 〉	통과 (0.07ms, 78MB)
테스트 4 〉	통과 (0.05ms, 77.9MB)
테스트 5 〉	통과 (0.04ms, 77.7MB)
테스트 6 〉	통과 (0.04ms, 76.4MB)
테스트 7 〉	통과 (0.04ms, 76.6MB)
테스트 8 〉	통과 (0.05ms, 72.1MB)
테스트 9 〉	통과 (0.05ms, 80.7MB)
테스트 10 〉	통과 (0.05ms, 77.6MB)
테스트 11 〉	통과 (0.04ms, 78MB)
테스트 12 〉	통과 (0.04ms, 78MB)
테스트 13 〉	통과 (0.05ms, 78.6MB)
테스트 14 〉	통과 (1.83ms, 82.8MB)
테스트 15 〉	통과 (2.34ms, 78.5MB)
테스트 16 〉	통과 (7.47ms, 79MB)
테스트 17 〉	통과 (8.12ms, 80.1MB)
테스트 18 〉	통과 (13.62ms, 84.4MB)
테스트 19 〉	통과 (13.88ms, 88.5MB)
테스트 20 〉	통과 (5.88ms, 84.1MB)
효율성  테스트
테스트 1 〉	통과 (39.85ms, 76.2MB)
테스트 2 〉	통과 (34.83ms, 65MB)
테스트 3 〉	통과 (317.08ms, 230MB)
테스트 4 〉	통과 (2298.94ms, 407MB)
*/

import java.util.HashSet;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        
        HashSet<String> hs = new HashSet<String>();
        
        for (String number : phone_book) {
            for (int i = 1; i < number.length(); i++) {
                hs.add(number.substring(0, i));
            }
        }
        
        for (String number : phone_book) {
            if (hs.contains(number) == true) {
                answer = false;
                break;
            }
        }
        
        return answer;
    }
}
