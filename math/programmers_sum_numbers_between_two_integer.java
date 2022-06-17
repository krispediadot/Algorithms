/*
테스트 1 〉	통과 (0.06ms, 73.9MB)
테스트 2 〉	통과 (0.07ms, 77.8MB)
테스트 3 〉	통과 (0.12ms, 73.4MB)
테스트 4 〉	통과 (0.06ms, 73.3MB)
테스트 5 〉	통과 (0.05ms, 73.4MB)
테스트 6 〉	통과 (0.05ms, 72.7MB)
테스트 7 〉	통과 (0.05ms, 74.6MB)
테스트 8 〉	통과 (0.04ms, 73.4MB)
테스트 9 〉	통과 (0.04ms, 74.8MB)
테스트 10 〉	통과 (0.04ms, 77.6MB)
테스트 11 〉	통과 (0.05ms, 83.9MB)
테스트 12 〉	통과 (0.04ms, 73.7MB)
테스트 13 〉	통과 (0.04ms, 78.4MB)
테스트 14 〉	통과 (0.05ms, 75.1MB)
테스트 15 〉	통과 (0.04ms, 73MB)
테스트 16 〉	통과 (0.04ms, 76.9MB)
*/

class Solution {
    public long solution(int a, int b) {
        long answer = 0;
        
        // b > a 되도록 만듬 
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        
        answer = (long)(b-a+1)*(a+b)/2;
        
        return answer;
    }
}
