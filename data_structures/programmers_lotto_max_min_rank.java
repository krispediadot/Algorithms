/*
테스트 1 〉	통과 (0.04ms, 88.1MB)
테스트 2 〉	통과 (0.05ms, 75.4MB)
테스트 3 〉	통과 (0.05ms, 76.4MB)
테스트 4 〉	통과 (0.05ms, 84.2MB)
테스트 5 〉	통과 (0.04ms, 77.3MB)
테스트 6 〉	통과 (0.04ms, 73.6MB)
테스트 7 〉	통과 (0.05ms, 78.7MB)
테스트 8 〉	통과 (0.04ms, 74.3MB)
테스트 9 〉	통과 (0.04ms, 84.5MB)
테스트 10 〉	통과 (0.04ms, 77.3MB)
테스트 11 〉	통과 (0.04ms, 74.2MB)
테스트 12 〉	통과 (0.05ms, 75.7MB)
테스트 13 〉	통과 (0.05ms, 72.1MB)
테스트 14 〉	통과 (0.05ms, 74.3MB)
테스트 15 〉	통과 (0.04ms, 73.9MB)
*/

import java.util.*;
// 복권 최고, 최저 순위

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        
        int cnt = 0;
        int cnt_zero = 0;
        
        List<Integer> nums = new ArrayList<Integer>();
        for (int n : win_nums) nums.add(n);
        
        for (int l : lottos) {
            if (nums.contains(l)) cnt++;
            if (l == 0) cnt_zero++;
        }
        
        int[] answer = new int[2];
        answer[0] = (cnt+cnt_zero < 2) ? 6 : (7-(cnt+cnt_zero));
        answer[1] = (cnt < 2) ? 6 : (7-cnt);
        
        return answer;
    }
}
