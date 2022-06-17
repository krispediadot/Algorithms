/*
테스트 1 〉	통과 (0.04ms, 79.2MB)
테스트 2 〉	통과 (0.04ms, 85.2MB)
테스트 3 〉	통과 (0.04ms, 74.7MB)
테스트 4 〉	통과 (0.04ms, 75.8MB)
테스트 5 〉	통과 (0.04ms, 76MB)
테스트 6 〉	통과 (0.07ms, 83.6MB)
테스트 7 〉	통과 (0.04ms, 75.6MB)
테스트 8 〉	통과 (0.05ms, 73.6MB)
테스트 9 〉	통과 (0.04ms, 83.3MB)
*/

class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int answer = 0;
        
        for (int i = 0; i < signs.length; i++) 
            answer += ((signs[i] ? 1 : -1)*absolutes[i]);
        
        return answer;
    }
}
