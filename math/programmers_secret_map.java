/*
테스트 1 〉	통과 (2.18ms, 74.1MB)
테스트 2 〉	통과 (2.59ms, 77.6MB)
테스트 3 〉	통과 (1.92ms, 78.3MB)
테스트 4 〉	통과 (2.55ms, 75.7MB)
테스트 5 〉	통과 (2.16ms, 77.1MB)
테스트 6 〉	통과 (2.41ms, 74.1MB)
테스트 7 〉	통과 (2.07ms, 75.5MB)
테스트 8 〉	통과 (2.00ms, 78.4MB)
*/

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        String[] str1 = new String[n];
        String[] str2 = new String[n];
        
        for (int i = 0; i < n; i++) {
            int num = arr1[i];
            String s = "";
            
            while (num > 0) {
                s = Integer.toString(num%2) + s;
                num /= 2;
            }
            
            while (s.length() < n) s = "0" + s;
            str1[i] = s;
        }
        
        for (int i = 0; i < n; i++) {
            int num = arr2[i];
            String s = "";
            
            while (num > 0) {
                s = Integer.toString(num%2) + s;
                num /= 2;
            }
            
            while (s.length() < n) s = "0" + s;
            str2[i] = s;
        }
        
        for (int i = 0; i < n; i++) {
            String s = "";
            
            for (int j = 0; j < n; j++) {
                s += ((str1[i].charAt(j) == '1' || str2[i].charAt(j) == '1') ? "#" : " ");
            }
            answer[i] = s;
        }
        
        return answer;
    }
}
