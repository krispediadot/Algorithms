/*
테스트 1 〉	통과 (0.66ms, 69MB)
테스트 2 〉	통과 (0.62ms, 71.6MB)
테스트 3 〉	통과 (0.25ms, 77.9MB)
테스트 4 〉	통과 (0.22ms, 74.1MB)
테스트 5 〉	통과 (0.70ms, 66.6MB)
테스트 6 〉	통과 (3.14ms, 83.8MB)
테스트 7 〉	통과 (0.38ms, 82.4MB)
테스트 8 〉	통과 (4.20ms, 75.9MB)
테스트 9 〉	통과 (0.63ms, 76.9MB)
테스트 10 〉	통과 (4.09ms, 76.9MB)
테스트 11 〉	통과 (0.05ms, 79.7MB)
테스트 12 〉	통과 (0.03ms, 80.1MB)
테스트 13 〉	통과 (0.08ms, 72.7MB)
테스트 14 〉	통과 (0.04ms, 76.3MB)
테스트 15 〉	통과 (0.04ms, 75.4MB)
테스트 16 〉	통과 (8.90ms, 77.4MB)
테스트 17 〉	통과 (1.05ms, 78.9MB)
테스트 18 〉	통과 (0.43ms, 82.4MB)
테스트 19 〉	통과 (0.05ms, 78MB)
테스트 20 〉	통과 (11.39ms, 78.5MB)
테스트 21 〉	통과 (10.37ms, 91.9MB)
테스트 22 〉	통과 (0.25ms, 67.8MB)
테스트 23 〉	통과 (0.02ms, 75.9MB)
테스트 24 〉	통과 (9.03ms, 77.1MB)
테스트 25 〉	통과 (9.12ms, 81.8MB)
테스트 26 〉	통과 (0.01ms, 78.4MB)
*/

// 3개 더해서 소수가 되는 경우

class Solution {
    public int solution(int[] nums) {
        int answer = 0;

        for (int i = 0; i < nums.length - 2; i++) {
            for (int j = i+1; j < nums.length - 1; j++) {
                for (int k = j+1; k < nums.length; k++)
                    if (isPrime(nums[i] + nums[j] + nums[k])) answer++;
            }
        }

        return answer;
    }
    
    public boolean isPrime(int n) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}
