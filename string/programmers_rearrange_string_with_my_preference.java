/*
테스트 1 〉	통과 (0.48ms, 65.5MB)
테스트 2 〉	통과 (0.50ms, 75.7MB)
테스트 3 〉	통과 (0.50ms, 70.2MB)
테스트 4 〉	통과 (0.48ms, 72.3MB)
테스트 5 〉	통과 (0.48ms, 77.7MB)
테스트 6 〉	통과 (0.51ms, 75.6MB)
테스트 7 〉	통과 (0.40ms, 82.8MB)
테스트 8 〉	통과 (0.48ms, 72.3MB)
테스트 9 〉	통과 (0.50ms, 74.1MB)
테스트 10 〉	통과 (0.62ms, 72.6MB)
테스트 11 〉	통과 (0.45ms, 77MB)
테스트 12 〉	통과 (0.51ms, 79.4MB)
*/

import java.util.*;

class Solution {
    public String[] solution(String[] strings, int n) {


        List<String> slist = Arrays.asList(strings);

        Collections.sort(slist, new Comparator<String>(){
            @Override
            public int compare(String s1, String s2) {
                if (Character.compare(s1.charAt(n), s2.charAt(n)) == 0)
                    return s1.compareTo(s2);
                return Character.compare(s1.charAt(n), s2.charAt(n));
            }
        });

        String[] answer = new String[slist.size()];
        slist.toArray(answer);

        return answer;
    }
}
