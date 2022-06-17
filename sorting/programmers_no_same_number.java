/*
정확성  테스트
테스트 1 〉	통과 (0.02ms, 77.5MB)
테스트 2 〉	통과 (0.02ms, 73MB)
테스트 3 〉	통과 (0.02ms, 75.3MB)
테스트 4 〉	통과 (0.02ms, 76.8MB)
테스트 5 〉	통과 (0.02ms, 73.3MB)
테스트 6 〉	통과 (0.02ms, 83.8MB)
테스트 7 〉	통과 (0.02ms, 79.4MB)
테스트 8 〉	통과 (0.03ms, 79MB)
테스트 9 〉	통과 (0.02ms, 65.8MB)
테스트 10 〉	통과 (0.02ms, 75MB)
테스트 11 〉	통과 (0.02ms, 73.5MB)
테스트 12 〉	통과 (0.02ms, 67.2MB)
테스트 13 〉	통과 (0.02ms, 77.6MB)
테스트 14 〉	통과 (0.02ms, 71.8MB)
테스트 15 〉	통과 (0.03ms, 84.5MB)
테스트 16 〉	통과 (0.02ms, 75.6MB)
테스트 17 〉	통과 (0.01ms, 78.1MB)

효율성  테스트
테스트 1 〉	통과 (8.27ms, 107MB)
테스트 2 〉	통과 (9.04ms, 107MB)
테스트 3 〉	통과 (9.01ms, 107MB)
테스트 4 〉	통과 (10.13ms, 106MB)
*/ 

import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        
        int idx = 0;
        int saveidx = 0;
        
        while (idx < arr.length) {
            int num = arr[idx++];
            while (idx < arr.length && arr[idx] == num) idx++;
            
            arr[saveidx++] = num;
        }
        
        int[] answer = Arrays.copyOf(arr, saveidx);

        return answer;
    }
}
