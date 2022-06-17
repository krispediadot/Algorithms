/*
테스트 1 〉	통과 (0.51ms, 74.8MB)
테스트 2 〉	통과 (0.86ms, 78.2MB)
테스트 3 〉	통과 (1.77ms, 76.8MB)
테스트 4 〉	통과 (3.05ms, 99.4MB)
테스트 5 〉	통과 (4.31ms, 97.8MB)
테스트 6 〉	통과 (0.76ms, 72.7MB)
테스트 7 〉	통과 (1.32ms, 77MB)
테스트 8 〉	통과 (3.10ms, 91.2MB)
테스트 9 〉	통과 (4.41ms, 90.9MB)
테스트 10 〉	통과 (2.73ms, 82.7MB)
테스트 11 〉	통과 (3.23ms, 86.8MB)
테스트 12 〉	통과 (3.26ms, 90.2MB)
테스트 13 〉	통과 (3.77ms, 86.6MB)
테스트 14 〉	통과 (0.61ms, 78.4MB)
테스트 15 〉	통과 (1.72ms, 78.4MB)
테스트 16 〉	통과 (1.16ms, 81.4MB)
테스트 17 〉	통과 (1.82ms, 84.2MB)
테스트 18 〉	통과 (1.18ms, 90.2MB)
테스트 19 〉	통과 (0.66ms, 76.7MB)
테스트 20 〉	통과 (1.43ms, 80.9MB)
테스트 21 〉	통과 (2.42ms, 87.9MB)
테스트 22 〉	통과 (4.00ms, 103MB)
테스트 23 〉	통과 (3.50ms, 83.1MB)
테스트 24 〉	통과 (3.34ms, 93.5MB)
테스트 25 〉	통과 (0.52ms, 66MB)
테스트 26 〉	통과 (0.56ms, 77.1MB)
테스트 27 〉	통과 (0.53ms, 76.5MB)
*/

import java.util.*;

// 실패율이 높은 스테이지부터 내림차순으로

class Solution {
    public int[] solution(int N, int[] stages) {
        int[] stcnts = new int[N+2]; // N+1;
        int[] answer = new int[N];
        
        for (int st : stages) 
            stcnts[st]++;
        
        List<Stage> list = new ArrayList<Stage>();
        
        int npeople = stages.length;
        for (int i = 1; i <= N; i++) {
            if (npeople == 0)
                list.add(new Stage(i, (float)0));
            else
                list.add(new Stage(i, (float)stcnts[i] / npeople));
            npeople -= stcnts[i];
        }
        
        Collections.sort(list, new Comparator<Stage>(){
            @Override
            public int compare(Stage s1, Stage s2) {
                if (s2.failrate.compareTo(s1.failrate) == 0) {
                    return s1.idx.compareTo(s2.idx);
                }
                return s2.failrate.compareTo(s1.failrate);
            }
        });
        
        
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i).idx;
        }
        
        return answer;
    }
    
    static class Stage{
        Integer idx;
        Float failrate;
        public Stage(Integer idx, Float failrate) {
            this.idx = idx;
            this.failrate = failrate;
        }
    }
}
