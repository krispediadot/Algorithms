/*
테스트 1 〉	통과 (0.05ms, 74.1MB)
테스트 2 〉	통과 (0.05ms, 78.9MB)
테스트 3 〉	통과 (0.05ms, 74.3MB)
테스트 4 〉	통과 (0.06ms, 82.2MB)
테스트 5 〉	통과 (0.04ms, 76.3MB)
테스트 6 〉	통과 (0.05ms, 84.3MB)
테스트 7 〉	통과 (0.05ms, 79.7MB)
테스트 8 〉	통과 (0.05ms, 78.1MB)
테스트 9 〉	통과 (0.05ms, 79.6MB)
테스트 10 〉	통과 (0.04ms, 76.8MB)
테스트 11 〉	통과 (0.04ms, 74.8MB)
테스트 12 〉	통과 (0.06ms, 74.2MB)
테스트 13 〉	통과 (0.05ms, 81.3MB)
테스트 14 〉	통과 (0.05ms, 74.8MB)
테스트 15 〉	통과 (0.08ms, 74.6MB)
테스트 16 〉	통과 (0.05ms, 76MB)
테스트 17 〉	통과 (0.05ms, 75.4MB)
테스트 18 〉	통과 (0.08ms, 80.6MB)
테스트 19 〉	통과 (0.07ms, 72.9MB)
테스트 20 〉	통과 (0.09ms, 83.7MB)
테스트 21 〉	통과 (0.12ms, 73.8MB)
테스트 22 〉	통과 (0.08ms, 75.7MB)
테스트 23 〉	통과 (0.11ms, 73.8MB)
*/

class Solution {
    public long solution(int price, int money, int count) {
        long answer = 0;
        
        for (int i = 1; i <= count; i++)
            answer += i;
        
        answer *= price;
        answer -= money;

        if (answer < 0) return 0;
        return answer;
    }
}
