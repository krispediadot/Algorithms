/*
테스트 1 〉	통과 (0.34ms, 73.3MB)
테스트 2 〉	통과 (0.40ms, 75MB)
테스트 3 〉	통과 (152.31ms, 179MB)
테스트 4 〉	통과 (0.54ms, 77.7MB)
테스트 5 〉	통과 (0.86ms, 76.2MB)
테스트 6 〉	통과 (5.12ms, 80MB)
테스트 7 〉	통과 (6.64ms, 89.8MB)
테스트 8 〉	통과 (11.42ms, 99MB)
테스트 9 〉	통과 (94.05ms, 134MB)
테스트 10 〉	통과 (67.65ms, 131MB)
테스트 11 〉	통과 (125.92ms, 170MB)
테스트 12 〉	통과 (1.47ms, 74.6MB)
테스트 13 〉	통과 (1.46ms, 78.3MB)
테스트 14 〉	통과 (72.44ms, 136MB)
테스트 15 〉	통과 (108.31ms, 146MB)
테스트 16 〉	통과 (1.15ms, 74.4MB)
테스트 17 〉	통과 (1.27ms, 80.6MB)
테스트 18 〉	통과 (1.81ms, 78.8MB)
테스트 19 〉	통과 (3.01ms, 82.5MB)
테스트 20 〉	통과 (70.69ms, 137MB)
테스트 21 〉	통과 (134.57ms, 153MB)
테스트 22 〉	통과 (0.29ms, 76.6MB)
테스트 23 〉	통과 (0.42ms, 86.6MB)
테스트 24 〉	통과 (0.28ms, 70.9MB)
*/

import java.util.*;

// k번 이상 신고되면 정지
// 정지된 사람을 신고한 사람에게 메일 발송

class Solution {
    public int[] solution(String[] id_list, String[] report, int k) {
        
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        List<Person> people = new ArrayList<Person>();
        
        for (int i = 0; i < id_list.length; i++) {
            hm.put(id_list[i], i);
            people.add(new Person(id_list[i]));
        }
        
        for (String r : report) {
            String[] subs = r.split(" ");
            String from = subs[0];
            String to = subs[1];
            
            people.get(hm.get(to)).froms.add(hm.get(from));
            if (people.get(hm.get(to)).froms.size() >= k) 
                people.get(hm.get(to)).blocked = true;
        }
        
        int[] answer = new int[id_list.length];
        for (int i = 0; i < people.size(); i++) {
            if (people.get(i).blocked == true) {
                for (Integer idx : people.get(i).froms)
                    answer[idx]++;
            }
        }
        
        return answer;
    }
    static class Person {
        String name;
        HashSet<Integer> froms;
        boolean blocked;
        public Person(String name) {
            this.name = name;
            this.froms = new HashSet<Integer>();
            this.blocked = false;
        }
    }
}
