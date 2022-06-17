/*
테스트 1 〉	통과 (0.18ms, 71.9MB)
테스트 2 〉	통과 (0.32ms, 77MB)
테스트 3 〉	통과 (0.21ms, 76.2MB)
테스트 4 〉	통과 (0.25ms, 74.4MB)
테스트 5 〉	통과 (0.44ms, 72.8MB)
테스트 6 〉	통과 (0.97ms, 85.2MB)
테스트 7 〉	통과 (5.10ms, 74.7MB)
테스트 8 〉	통과 (1.62ms, 75MB)
테스트 9 〉	통과 (0.94ms, 73.3MB)
*/

import java.util.*;

class Solution {
    public int[] solution(int[] numbers) {
        
        List<Integer> list = new ArrayList<Integer>();
        
        for (int i = 0; i < numbers.length; i++) {
            for (int j = i+1; j < numbers.length; j++) {
                int sum = numbers[i] + numbers[j];
                if (list.contains(sum) == false)
                    list.add(sum);
            }
        }
        
        Collections.sort(list);
        
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++)
            answer[i] = list.get(i);
        
        return answer;
    }
}
