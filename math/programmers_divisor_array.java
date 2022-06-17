/*
테스트 1 〉	통과 (1.13ms, 75.5MB)
테스트 2 〉	통과 (0.33ms, 76.4MB)
테스트 3 〉	통과 (0.33ms, 77.2MB)
테스트 4 〉	통과 (1.55ms, 77.1MB)
테스트 5 〉	통과 (0.84ms, 65MB)
테스트 6 〉	통과 (2.18ms, 90.5MB)
테스트 7 〉	통과 (0.40ms, 77.8MB)
테스트 8 〉	통과 (1.07ms, 77MB)
테스트 9 〉	통과 (0.38ms, 77.9MB)
테스트 10 〉	통과 (0.41ms, 75.7MB)
테스트 11 〉	통과 (0.36ms, 72.3MB)
테스트 12 〉	통과 (0.34ms, 73.8MB)
테스트 13 〉	통과 (0.46ms, 72.4MB)
테스트 14 〉	통과 (0.40ms, 74.2MB)
테스트 15 〉	통과 (0.37ms, 77.8MB)
테스트 16 〉	통과 (0.35ms, 75.1MB)
*/

import java.util.*;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        
        int saveidx = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % divisor == 0) arr[saveidx++] = arr[i];    
        }
        
        if (saveidx == 0) arr[saveidx++] = -1;
        
        int[] answer = Arrays.copyOf(arr, saveidx);
        Arrays.sort(answer);
        
        return answer;
    }
}
